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
    vector<string> dic;
    map<string,int> dicm;
    const static int inf=0x3fffffff;
    queue<int> q;

public:
    int bfs(int now) {

        int l=0,r=0;
        q.push(now);
        dp[now]=1;
        vis[now] = 1;
        while(q.size()>0) {
            int p = q.front();
            q.pop();
            for(int i=0; i<gr[p].size(); i++) {
                if(!vis[gr[p][i]]) {
                    vis[gr[p][i]]=1;
                    dp[gr[p][i]] = dp[p]+1;
                    if (gr[p][i]==end) {
                        return dp[gr[p][i]];
                    }
                    q.push(gr[p][i]);
                }
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord,unordered_set<string>& wordDict) {
        if (beginWord == endWord) {
            return 0;
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
        vis[dicm[beginWord]] = 1;
        int ans = bfs(dicm[beginWord]);
        if (ans == inf) {
            return 0;
        }
        return ans;
    }
};

int main() {
    Solution s;
    set<string> st;
    st.insert("hot");
    //st.insert(new string("hit"));
    //st.insert(new string("cog"));
    st.insert("dot");
    st.insert("dog");
    printf("%d\n",s.ladderLength("hit","cog",st));
    return 0;
}
