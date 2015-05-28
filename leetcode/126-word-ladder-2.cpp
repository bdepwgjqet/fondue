#include <cstdio>
#include <queue>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {

    vector<int> vis;
    vector<int> dp;
    vector<vector<int> > gr;
    int end;
    int start;
    vector<string> dic;
    map<string,int> dicm;
    const static int inf=0x3fffffff;
    queue<int> q;
    vector<vector<string> > ans;

public:
    void dfs(int now, vector<string> tmp) {
        if (now == start) {
            reverse(tmp.begin(),tmp.end());
            ans.push_back(tmp);
            return;
        }
        for (int i=0; i<gr[now].size(); i++) {
            if (dp[gr[now][i]]==dp[now]-1) {
                tmp.push_back(dic[gr[now][i]]);
                dfs(gr[now][i],tmp);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string> > bfs(int now) {
        int l=0,r=0;
        q.push(now);
        dp[now]=1;
        vis[now] = 1;
        int flag = 0;
        while(q.size()>0) {
            if (flag) {
                break;
            }
            int p = q.front();
            q.pop();
            for(int i=0; i<gr[p].size(); i++) {
                if(!vis[gr[p][i]]) {
                    vis[gr[p][i]]=1;
                    dp[gr[p][i]] = dp[p]+1;
                    if (gr[p][i] == end) {
                        flag = 1;
                        break;
                    }
                    q.push(gr[p][i]);
                }
            }
        }

        ans.clear();
        vector<string> tmp;
        tmp.push_back(dic[end]);
        dfs(end,tmp);
        return ans;
    }

    vector<vector<string> > findLadders(string beginWord, string endWord,unordered_set<string>& wordDict) {
    //vector<vector<string> > findLadders(string beginWord, string endWord,set<string>& wordDict) {
        ans.clear();
        if (beginWord == endWord) {
            return ans;
        }
        if (wordDict.count(beginWord) <= 0) {
            wordDict.insert(beginWord);
        }
        if (wordDict.count(endWord) <= 0) {
            wordDict.insert(endWord);
        }
        dic.clear();
        vis.resize(wordDict.size());
        dp.resize(wordDict.size());
        gr.resize(wordDict.size());
        dicm.clear();
        for(unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); it++) {
        //for(set<string>::iterator it = wordDict.begin(); it != wordDict.end(); it++) {
            dic.push_back(*it);
            dicm[*it] = dic.size()-1;
        }
        for(int i=0; i<dic.size(); i++) {
            dp[i] = -1;
            vis[i] = 0;
            for (int j=0; j<dic[i].length(); j++) {
                for (int k=0; k<26; k++) {
                    if (k == dic[i][j]-'a') {
                        continue;
                    }
                    string tmp = dic[i];
                    tmp[j] = 'a'+k;
                    if (dicm.count(tmp) > 0) {
                        gr[i].push_back(dicm[tmp]);
                    }
                }
            }
        }

        end = dicm[endWord];
        start = dicm[beginWord];
        vis[dicm[beginWord]] = 1;
        return bfs(dicm[beginWord]);
    }
};

int main() {
    Solution s;
    set<string> st;
    st.insert("hot");
    st.insert(("lot"));
    st.insert(("log"));
    st.insert("dot");
    st.insert("dog");
    vector<vector<string> > ans = s.findLadders("hit","cog",st);
    for(int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        puts("");
    }
    return 0;
}
