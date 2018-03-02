#!/usr/bin/env python
# -*- coding: utf-8 -*-


import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
from scipy.stats import norm
from sklearn.preprocessing import StandardScaler
from scipy import stats
from scipy.stats import skew
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error

from sklearn.ensemble import GradientBoostingRegressor
from sklearn.grid_search import GridSearchCV 


train = pd.read_csv('../data/train.csv')
test = pd.read_csv('../data/test.csv')


all_data = pd.concat((
    train.loc[:,'MSSubClass':'SaleCondition'],
    test.loc[:,'MSSubClass':'SaleCondition']
))

#print(train.columns)

train["SalePrice"] = np.log1p(train["SalePrice"])

numeric_feats = all_data.dtypes[all_data.dtypes != "object"].index

skewed_feats = train[numeric_feats].apply(lambda x: skew(x.dropna())) #compute skewness
skewed_feats = skewed_feats[skewed_feats > 0.75]
skewed_feats = skewed_feats.index

all_data[skewed_feats] = np.log1p(all_data[skewed_feats])

all_data = pd.get_dummies(all_data)

all_data = all_data.fillna(all_data.mean())


X_train = all_data[:train.shape[0]]
X_test = all_data[train.shape[0]:]
y = train.SalePrice

forest_model = RandomForestRegressor()
forest_model.fit(X_train, y)
preds = forest_model.predict(X_test)
acc = round(forest_model.score(X_train, y)*100, 2)
print("Random forest acc is: {}".format(acc))


"""
param_test1 = {'min_samples_leaf': list(range(1, 151, 10))}
gsearch = GridSearchCV(
    estimator=GradientBoostingRegressor(n_estimators=150, max_depth=5, min_samples_split=142, max_features='sqrt', subsample=0.8, random_state=10),
    param_grid=param_test1,
    scoring='neg_mean_squared_log_error',
    iid=False,
    cv=5
)
gsearch.fit(X_train, y)
for score in gsearch.grid_scores_:
    print(score)
print(gsearch.best_params_, gsearch.best_score_)
"""

gbdt_model = GradientBoostingRegressor(
    n_estimators=150, max_depth=5, min_samples_split=142
)
gbdt_model.fit(X_train, y)
preds = gbdt_model.predict(X_test)
acc = round(gbdt_model.score(X_train, y)*100, 2)
print("GBDT acc is: {}".format(acc))
importances = gbdt_model.feature_importances_
indices = np.argsort(importances)[::-1]
features = list(X_train)
for indice in indices:
    print("Feature {}, importance {}".format(features[indice], importances[indice]))


test['SalePrice'] = pd.Series(np.exp(preds) - 1)
predict_pd = test[['Id', 'SalePrice']]
predict_pd.to_csv("../data/predict.csv", index=False)
