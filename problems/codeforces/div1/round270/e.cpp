#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 35;
const int MN = 1000;

int A[N][N],B[N][N],ok[N][N],vis[N][N],cnt[MN];
int n,m;
int dir[8][2] = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};

bool same_count() {
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cnt[A[i][j]]++;
            cnt[B[i][j]]--;
        }
    }
    for(int i=0; i<MN; i++) {
        if (cnt[i] != 0) {
            return false;
        }
    }
    return true;
}

void do_special() {
    int k = m;
    if (m == 1) {
        k = n;
        for(int i=0; i<k; i++) {
            A[0][i] = A[i][0];
            B[0][i] = B[i][0];
        }
    }
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++) {
            if (i == j) {
                continue;
            }
            //0,i->0,j
            int d = i>j?-1:1;
            for (int u = i; u!=j; u+=d) {
                swap(A[0][u],A[0][u+d]);
            }
            int ok = 1;
            for (int u=0; u<k; u++) {
                if (A[0][u] != B[0][u]) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 0) {
                for (int u = j; u!=i; u-=d) {
                    swap(A[0][u],A[0][u-d]);
                }
                continue;
            }
            int ans = (j-i)/d;
            printf("%d\n",ans);
            for (int u=i; u != j+d; u+=d) {
                if (m == 1) {
                    printf("%d %d\n",u+1,1);
                } else {
                    printf("%d %d\n",1,u+1);
                }
            }
            return;
        }
    }
    puts("-1");
}

class node {
public:
    int x,y; 
    node(){}
    node(int x,int y):x(x),y(y){}
};
vector<node> path;
node nowp;

void move_to(node next) {
    path.push_back(next);
    swap(A[nowp.x][nowp.y],A[next.x][next.y]);
    nowp = next;
}

bool find_path(node now, node ed, node nogo, vector<node> &tpath) {
    int x = now.x, y = now.y;
    if (x == ed.x && y == ed.y) {
        return true;
    }
    vis[x][y] = 1;
    vector<node> son;
    int mlen = 1000000;
    for (int i=0; i<8; i++) {
        int dx = dir[i][0], dy = dir[i][1];
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }
        if (nx == nogo.x && ny == nogo.y) {
            continue;
        }
        if (vis[nx][ny] || ok[nx][ny]) {
            continue;
        }
        int astar_value = abs(nx-ed.x) + abs(ny-ed.y);
        if (astar_value < mlen) {
            mlen = astar_value;
            son.clear();
            son.push_back(node(nx,ny));
        } else if (astar_value == mlen) {
            son.push_back(node(nx,ny));
        }
    }
    
    for (int i=0; i<son.size(); i++) {
        node next = son[i];
        tpath.push_back(next);
        if (find_path(next,ed,nogo,tpath)) {
            vis[x][y] = 0;
            return 1;
        }
        tpath.pop_back();
    }
    son.clear();
    vis[x][y] = 0;
    return 0;
}

vector<node> mopath;
void do_move(node ed,node nogo) {
    mopath.clear();
    find_path(nowp,ed,nogo,mopath);
    for (int i=0; i<mopath.size(); i++) {
        move_to(mopath[i]);
    }
}

vector<node> expath;
void do_exchange(node st, node ed) {
    expath.clear();
    find_path(st,ed,node(-1,-1),expath);
    for (int i=0; i<expath.size(); i++) {
        do_move(expath[i],st);
        move_to(st);
        st.x = expath[i].x;
        st.y = expath[i].y;
    }
}

int main () {
    while(scanf("%d%d",&n,&m) +1 ) {
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        memset(ok,0,sizeof(ok));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                scanf("%d",&A[i][j]);
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                scanf("%d",&B[i][j]);
            }
        }
        if (!same_count()) {
            puts("-1");
            continue;
        }
        if (n == 1 || m == 1) {
            do_special();
            continue;
        }

        int flag = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (A[i][j] == B[n-1][m-1]) {
                    nowp.x = i;
                    nowp.y = j;
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }

        move_to(nowp);
        for (int i=0; i<n-2; i++) {
            for (int j=0; j<m; j++) {
                if (A[i][j] == B[i][j] && (i != nowp.x || j != nowp.y)) {
                    ok[i][j] = 1;
                    continue;
                }
                int fail = 1;
                int fx = i, fy = j;
                while(fail) {
                    fy += 1;
                    if (fy == m) {
                        fx += 1;
                        fy = 0;
                    }
                    if (A[fx][fy] == B[i][j] && (fx != nowp.x || fy != nowp.y)) {
                        fail = 0;
                    }
                }
                do_exchange(node(fx,fy),node(i,j));
                ok[i][j] = 1;
            }
        }
        for (int j=0; j<m; j++) {
            for (int i=n-2; i<n; i++) {
                if (i == n-1 && j == m - 1) {
                    break;
                }
                if (A[i][j] == B[i][j] && (i != nowp.x ||j != nowp.y)) {
                    ok[i][j] = 1;
                    continue;
                }
                int fail = 1;
                int fx = i, fy = j;
                while(fail) {
                    fx += 1;
                    if (fx == n) {
                        fy += 1;
                        fx = n-2;
                    }
                    if (A[fx][fy] == B[i][j] && (fx != nowp.x || fy != nowp.y)) {
                        fail = 0;
                    }
                }
                do_exchange(node(fx,fy),node(i,j));
                ok[i][j] = 1;
            }
        }
        printf("%d\n",path.size()-1);
        for(int i=0; i<path.size(); i++) {
            printf("%d %d\n",path[i].x+1,path[i].y+1);
        }
    }
    return 0;
}
