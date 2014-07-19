#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#define N 1011

using namespace std;

char s[N];
int cnt[26];

int main()
{
	int n;
	scanf("%s",s);
	for(int i=0; s[i]; i++)
		cnt[s[i]-'a']++;
	int ret=0;
	for(int i=0; i<26; i++)
		if(cnt[i]&1)
			ret++;
	if((ret&1)||ret==0)
		puts("First");
	else
		puts("Second");
	return 0;
}
