#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;

int main()
{
    LL w,h;
    while(cin>>w>>h)
    {
        LL ret=0;
        for(LL i=1; i<h; i++)
            for(LL j=1; j<w; j++)
            {
                ret+=min(i,h-i)*min(j,w-j);
            }
        cout<<ret<<endl;
    }
    return 0;
}
