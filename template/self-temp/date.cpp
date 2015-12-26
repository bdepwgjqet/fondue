//日期模板 判断合法性/ 比较大小/ 判闰年/ 判星期几/ 日期转天数/ 天数转日期/
#include <cstdio>

int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
struct date{ int y,m,d; };

//判闰年
inline int leap(int year)
{
    return (year%4==0 && year%100!=0)||0==year%400;
}

//判合法性
inline int legal(date a)
{
    if(a.m<0 || a.m>12) return 0;
    if(a.m==2)      return a.d>0 && a.d<=28+leap(a.y);
    return a.d>0 && a.d<=days[a.m-1];
}

//比较日期大小
inline int datecmp(date a,date b)
{
    if(a.y != b.y)  return a.y-b.y;
    if(a.m != b.m)  return a.m-b.m;
    return a.d-b.d;
}

//返回指定日期是星期几
//蔡勒公式  适合于1582年10月15日之后的情形
//0 表示星期日
int weekday(date a)
{
    int tm=a.m>=3? (a.m-2):(a.m+10);
    int ty=a.m>=3? a.y:(a.y-1);
    return (ty+ty/4-ty/100+ty/400+(int)(2.6*tm-0.2)+a.d)%7;
}

//日期转天数偏移
//1 1 1认为是第366天
int date2int(date a)
{
    int ret=a.y*365+(a.y-1)/4-(a.y-1)/100+(a.y-1)/400,i;
    days[1]+=leap(a.y);
    for(i=0; i<a.m-1; ret+=days[i++]);
    days[1]=28;
    return ret+a.d;
}

//天数偏移转日期
//400年=146097天
//1 1 1认为是第366天  400 1 1则第146097天
date int2date(int a)
{
    date ret;
    ret.y=a/146097*400;
    for(a%=146097; a>=365+leap(ret.y); a-=365+leap(ret.y),ret.y++);
    days[1]+=leap(ret.y);
    for(ret.m=1; a>=days[ret.m-1]; a-=days[ret.m-1],ret.m++);
    days[1]=28;
    ret.d=a+1;
    return ret;
}

