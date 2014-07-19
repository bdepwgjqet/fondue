#include <cstdio>
#include <vector>
#include <list>

using namespace std;

int main() {
	list<int> li;
	for(int i=0; i<5; i++)
		li.push_back(i);
	list<int>::iterator it;
	for(it=li.begin(); it!=li.end(); it++) {
		printf("%d\n",*it);
	}
	li.insert(it,10);
	for(it=li.begin(); it!=li.end(); it++) {
		printf("%d\n",*it);
	}
	it=li.begin();
	return 0;
}
