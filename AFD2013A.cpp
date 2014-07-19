#include <cstdio>

char s[100][100]={
"Washington",
"Adams",
"Jefferson",
"Madison",
"Monroe",
"Quincy Adams",
"Jackson",
"Van Buren",
"Henry Harrison",
"Tyler",
"K. Polk",
"Taylor",
"Fillmore",
"Pierce",
"Buchanan",
"Lincoln",
"Johnson",
"S. Grant",
"B. Hayes",
"Garfield",
"A. Arthur",
"Cleveland",
"Harrison",
"Cleveland",
"McKinley",
"Roosevelt",
"Howard Taft",
"Wilson",
"Harding",
"Coolidge",
"Hoover",
"D. Roosevelt",
"S Truman",
"D. Eisenhower",
"F. Kennedy",
"B. Johnson",
"M. Nixon",
"R. Ford",
"Carter",
"Reagan",
"H.W. Bush",
"J. Clinton"};


int main()
{
	int n;
	scanf("%d",&n);
	printf("%s\n",s[n-1]);
	return 0;
}
