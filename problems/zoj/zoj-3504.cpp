#include <cstdio>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

struct node{ double x,y; };
vector<node> vec[2];
string str;

double len(double x,double y)
{
	return sqrt(x*x+y*y);
}

void get(int i)
{
	istringstream iss(str);
	node now;
	char x;
	while(iss>>x>>now.x>>x>>now.y>>x)
		vec[i].push_back(now);
}

int main()
{
	double p;
	while(getline(cin,str))
	{
		for(int i=0; i<2; i++)
			vec[i].clear();
		get(0);
		getline(cin,str);
		get(1);
		scanf("%lf",&p);
		char x;
		while((x=getchar())!='\n');
		assert(vec[0].size()==vec[1].size());
		double ret=0;
		for(size_t i=0; i<vec[0].size(); i++)
			ret+=pow(len(vec[0][i].x-vec[1][i].x,vec[0][i].y-vec[1][i].y),p);
		printf("%.16lf\n",pow(ret,1.0/p));
	}
	return 0;
}
