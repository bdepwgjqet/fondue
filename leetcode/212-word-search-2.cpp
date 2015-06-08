#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class TrieNode {
public:
    int id;
    vector<int> next;
    TrieNode():id(-1){
        for (int i=0; i<26; i++) {
            next.push_back(-1);
        }
    }
    TrieNode(int id):id(id){
        for (int i=0; i<26; i++) {
            next.push_back(-1);
        }
    }
};

class TrieTree {
public:
    vector<TrieNode> pool;
    int root;

    void addWord(string s,int id) {
        int now = root;
        for(int i=0; i<s.length(); i++) {
            int x = s[i] - 'a';
            if (pool[now].next[x] < 0) {
                TrieNode tmp;
                pool.push_back(tmp);
                pool[now].next[x] = pool.size()-1;
            } 
            now = pool[now].next[x];

            if (i == s.length()-1) {
                pool[now].id = id;
            }
        }
    }

    void BuildTrie(vector<string> words) {
        TrieNode tmp;
        pool.push_back(tmp);
        root = 0;
        for(int i=0; i<words.size(); i++) {
            addWord(words[i],i);
        }
    }
};

class Solution {

public:
    TrieTree tree;
    set<int> ans;
    vector<vector<char> > dic;
    vector<vector<int> > vis;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;

    bool inboard(int x,int y) {
        return 0<=x && x<m && 0<=y && y<n;
    }

    void search(int x, int y, int node, int flag) {
        if (node < 0) {
            return;
        }
        if (tree.pool[node].id>=0) {
            ans.insert(tree.pool[node].id);
        }
        if (!inboard(x,y)) {
            return;
        }
        TrieNode now = tree.pool[node];
        if (now.id >= 0) {
        }
        for (int i=0; i<4; i++) {
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];
            if (inboard(xx,yy) && vis[xx][yy] != flag) {
                vis[xx][yy] = flag;
                search(xx,yy,now.next[dic[xx][yy]-'a'],flag);
                vis[xx][yy] = -1;
            }
        }
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> ans_v;
        if (board.size() <= 0) {
            return ans_v;
        }
        m = board.size();
        n = board[0].size();
        tree.BuildTrie(words);
        if (tree.pool.size() <= 0) {
            return ans_v;
        }
        dic = board;
        for (int i=0; i<board.size(); i++) {
            vector<int> tmp;
            for (int j=0; j<board[i].size(); j++) {
                tmp.push_back(-1);
            }
            vis.push_back(tmp);
        }
        int now = 0;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                vis[i][j] = now;
                search(i,j,tree.pool[0].next[dic[i][j]-'a'],now);
                now = now + 1;
            }
        }
        for (set<int>::iterator it=ans.begin(); it!=ans.end(); it++) {
            ans_v.push_back(words[*it]);
        }
        return ans_v;
    }
};

int main() {
    Solution s;
    vector<vector<char> > board;
    board.resize(2);
    board[0].push_back('a');
    board[0].push_back('b');
    board[1].push_back('d');
    board[1].push_back('c');
    vector<string> words;
    words.push_back("abcd");
    vector<string> ans = s.findWords(board,words);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
