#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

int n;

struct point {
    int x,y,i;
    point(int xx,int yy,int ii) {
        x = xx;
        y = yy;
        i = ii;
    }
};

vector<point> li;
vector<point> st;
vector<point> nli;
set<int> ans;
set<pair<int,int> > need;

bool cmp(point a,point b) {
    if (a.x == b.x) {
        return a.y > b.y;
    }
    return a.x > b.x;
}

bool converx(point a, point b, point c) {
    return 1LL*b.y*c.x*(a.y-c.y)*(a.x-b.x) < 1LL*b.x*c.y*(a.y-b.y)*(a.x-c.x);
}

int main() {

    while (scanf("%d",&n)+1) {
        li.clear();
        int mxx = -1,mxy = -1;
        for (int i=0; i<n; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            if (mxy < y) {
                mxx = x;
                mxy = y;
            } else if(mxy == y) {
                mxx = max(x,mxx);
            }
            li.push_back(point(x,y,i));
        }
        sort(li.begin(),li.end(),cmp);
        nli.clear();
        nli.push_back(li[0]);
        point now = li[0];
        for(int i=1; i<li.size(); i++) {
            if (now.x == li[i].x) {
                continue;
            }
            now = li[i];
            nli.push_back(li[i]);
        }
        st.clear();
        for (int i=0; i < nli.size(); i++) {
            for(; st.size() > 1 && converx(st[st.size()-2],st[st.size()-1],nli[i]); st.pop_back());
            st.push_back(nli[i]);
            if (mxy == nli[i].y && mxx == nli[i].x) {
                break;
            }
        }
        ans.clear();
        need.clear();
        for (int i=0; i<st.size(); i++) {
            need.insert(make_pair(st[i].x,st[i].y));
        }
        for (int i=0; i<li.size(); i++) {
            if(need.count(make_pair(li[i].x,li[i].y)) > 0) {
                ans.insert(li[i].i+1);
            }
        }
        for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
            printf("%d ",*it);
        }
        puts("");
    }
    return 0;
}
