#!/bin/python
# -*- coding: utf-8 -*-
"""
__module__ : ProfilingKagglers.py
__author__ : SRK

Please feel free to change the variable 
"ENTER_THE_RANK_HERE" (Rank of the Kaggler whom you would like to profile)
and see the performance of the Kaggler you would like to see

This is a work in progress.! Please feel free to add your suggestions in the comments section and I will try to incorporate them
"""

import sqlite3 as sql
import bokeh
import seaborn as sb
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from datetime import datetime
import networkx as nx

""" Please enter the rank of the Kaggler whom you would like to profile """
ENTER_THE_RANK_HERE = 54

## Connecting to sqlite and getting the data ##
conn = sql.connect("../input/database.sqlite")
cur = conn.cursor()

cur.execute('select a.DisplayName, a.Ranking, c.Ranking, d.CompetitionName, d.Deadline \
from Users a \
join \
TeamMemberships b \
on a.ID = b.UserID \
join Teams c \
on b.TeamID = c.ID \
join Competitions d \
on c.CompetitionID = d.ID \
where a.Ranking={rnk} \
order by d.Deadline'.format(rnk=ENTER_THE_RANK_HERE))
result = cur.fetchall()

query1 = 'select TeamId \
from Users a \
join \
TeamMemberships b \
on a.Id=b.UserId \
where Ranking={rnk}'.format(rnk=ENTER_THE_RANK_HERE)
query = 'select b.DisplayName, count(*) as Count, min(c.Ranking) as BestRank \
from TeamMemberships a \
join \
Users b \
on a.UserId=b.Id \
join Teams c \
on a.TeamID = c.ID \
where a.TeamId in ( {tids} ) \
group by b.DisplayName  \
order by Count desc'.format(tids=query1)
cur.execute(query)
members_count = cur.fetchall()
conn.close()

## creating dataframes from the result to do some aggregation ##
result_df = pd.DataFrame(result)
result_df.columns = ["DisplayName", "KaggleRank", "CompRanking", "CompName","CompEndDate"]
result_df["YearOfComp"] = result_df["CompEndDate"].apply(lambda x: datetime.strptime(x, "%Y-%m-%d %H:%M:%S").year)

team_members_df = pd.DataFrame(members_count[1:])
team_members_df.columns = ["TeamMate","Count","BestRank"]

## Ranking histogram plot ##
plt.figure()
plt.hist(np.array(result_df["CompRanking"]), np.arange(0,1000,20), histtype = "bar", color='green')
plt.title("Histogram of competition rankings of "+str(result_df["DisplayName"][0]))
plt.ylabel("No. of competitions")
plt.xlabel("Rank")
plt.savefig('Plot_a_RankHist.png')
plt.show()

## Compeition ranking plot ##
plt.figure()
result_df["CompRanking"].plot(kind='line', color='red')
plt.xticks(range(result_df.shape[0]), result_df['CompName'], size='small', rotation=270)
plt.title("Ranking of "+str(result_df["DisplayName"][0])+" in different competitions")
plt.ylabel("Rank")
plt.savefig('Plot_b_CompetitionRanking.png')
plt.show()

## Median ranking plot ##
year_group = result_df.groupby("YearOfComp").aggregate([np.median,'count'])
fig, ax1 = plt.subplots()
ax2 = ax1.twinx()
width = 0.35
ax1.bar(np.arange(year_group.shape[0]), year_group["CompRanking"]["median"], width, color='blue')
ax1.set_xticks(np.arange(year_group.shape[0])+width)
ax1.set_xticklabels(year_group.index, size='small', rotation=0, horizontalalignment='center')
ax1.set_title("Performance of "+str(result_df["DisplayName"][0])+" across different years")
ax1.set_xlabel("Year")
ax1.set_ylabel("Median Competition Ranking", color='blue')
ax2.bar(np.arange(year_group.shape[0])+width, year_group["CompRanking"]["count"], width, color='brown')
ax2.set_ylabel("No of competitions", color='brown')
ax2.grid(b=False)
plt.savefig("Plot_c_PerformanceYear.png")
plt.show()

## Team mates bar chart #
fig, ax1 = plt.subplots()
ax2 = ax1.twinx()
width = 0.35
ax1.bar(np.arange(team_members_df.shape[0]), team_members_df["Count"], color='brown')
ax1.set_xticks(np.arange(team_members_df.shape[0])+width)
ax1.set_xticklabels(team_members_df.TeamMate, size='small', rotation=270, horizontalalignment='center')
ax1.set_title("Team-mates of "+str(result_df["DisplayName"][0])+" in competitions")
ax1.set_xlabel("Display Name")
ax1.set_ylabel("No. of Competitions", color='brown')
ax2.plot(np.arange(team_members_df.shape[0])+width, team_members_df["BestRank"], color='blue')
ax2.set_ylabel("Best Rank", color='blue')
ax2.grid(b=False)
plt.savefig("Plot_d_TeamMates.png")
plt.show()
