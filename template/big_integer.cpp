#include <cstdio>
#include <cstring>

#define DIGIT 4
#define DEPTH 10000
#define MAXN  2502
#define SGN(x) ((x)>0?1:((x)<0?-1:0))
#define ABS(x) ((x)>0?(x):-(x))
typedef int big_num[MAXN+1];

int read(big_num a)
{
    char buf[MAXN*DIGIT+1],ch; int i,j;
    memset(a,0,sizeof(int)*(MAXN+1));
    if( scanf("%s",&buf)==EOF ) return 0;
    for(a[0]=strlen(buf),i=a[0]/2-1; i>=0; i--)
        ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
    for(j=a[0],a[0]=(a[0]+DIGIT-1)/DIGIT; j<a[0]*DIGIT; buf[j++]='0');
    for(i=1; i<=a[0]; i++)
        for(a[i]=0,j=0; j<DIGIT; j++)
            a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
    for(;!a[a[0]]&&a[0]>1;a[0]--);
    return 1;
}

int read(big_num a,int &sgn)                    //read big_num a which is lower than zero
{
    char str[MAXN*DIGIT+1],ch,*buf; int i,j;
    memset(a,0,sizeof(int)*(MAXN+1));
    if( scanf("%s",&str)==EOF ) return 0;
    buf=str,sgn=1;
    if(*buf=='-')   sgn=-1,buf++;
    for(a[0]=strlen(buf),i=a[0]/2-1; i>=0; i--)
        ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
    for(j=a[0],a[0]=(a[0]+DIGIT-1)/DIGIT; j<a[0]*DIGIT; buf[j++]='0');
    for(i=1; i<=a[0]; i++)
        for(a[i]=0,j=0; j<DIGIT; j++)
            a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
    for(;!a[a[0]]&&a[0]>1;a[0]--);
    if(a[0]==1 && !a[1])    sgn=0;
    return 1;
}

void write(const big_num a)
{
    int i,j;
    for(printf("%d",a[i=a[0]]),i--; i; i--)
        for(j=DEPTH/10; j; j/=10)
            printf("%d",a[i]/j%10);
}

int comp(big_num a,big_num b)
{
    int i;
    if(a[0]!=b[0])  return a[0]-b[0];
    for(i=a[0]; i; i--)
        if(a[i]!=b[i])
            return a[i]-b[i];
    return 0;
}

int comp(big_num a,const int b)
{
    int c[12]={1};
    for(c[1]=b; c[c[0]]>=DEPTH; c[c[0]+1]=c[c[0]]/DEPTH,c[c[0]]%=DEPTH,c[0]++);
    return comp(a,c);
}

int comp(big_num a,int c,int d,big_num b)      //compete a*c before dth bit with b...  return a*c>b;
{
    int i,t=0,O=-DEPTH*2;
    if(b[0]-a[0]<d && c)
        return 1;
    for(i=b[0]; i>d; i--)
    {
        t=t*DEPTH+a[i-d]*c-b[i];
        if(t>0) return 1;
        if(t<O) return 0;
    }
    for(i=d; i; i--)
    {
        t=t*DEPTH-b[i];
        if(t>0) return 1;
        if(t<O) return 0;
    }
    return t>0;
}

void add(big_num a,big_num b)
{
    int i;
    for(i=1; i<=b[0]; i++)
        if((a[i]+=b[i])>=DEPTH)
            a[i]-=DEPTH,a[i+1]++;
    if(b[0]>=a[0])      a[0]=b[0];
    else                for(; a[i]>=DEPTH && i<=a[0]; a[i]-=DEPTH,i++,a[i]++ );
    a[0]+=(a[a[0]+1]>0);
}

void add(big_num a,int b)
{
    int i=1;
    for(a[1]+=b; a[i]>=DEPTH && i<a[0]; a[i+1]+=a[i]/DEPTH,a[i]%=DEPTH,i++);
    for(; a[a[0]]>=DEPTH; a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
}

void sub(big_num a,big_num b)   //a>b;
{
    int i;
    for(i=1; i<=b[0]; i++)
        if((a[i]-=b[i])<0)
            a[i+1]--,a[i]+=DEPTH;
    for(; a[i]<0; a[i]+=DEPTH,i++,a[i]--);
    for(; !a[a[0]]&&a[0]>1; a[0]--);
}

void sub(big_num a,int b)
{
    int i=1;
    for(a[1]-=b; a[i]<0; a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
    for(; !a[a[0]]&&a[0]>1; a[0]--);
}

void sub(big_num a,big_num b,int c,int d)       //a-=b*c...before dth bit of a..
{
    int i,O=b[0]+d;
    for(i=1+d; i<=O; i++)
        if((a[i]-=b[i-d]*c)<0)
            a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH;
    for(; a[i]<0; a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);
    for(; !a[a[0]]&&a[0]>1; a[0]--);
}

void mul(big_num a,big_num b,big_num c)
{
    int i,j;
    memset(c,0,sizeof(int)*(MAXN+1));
    for(c[0]=a[0]+b[0]-1,i=1; i<=a[0]; i++)
        for(j=1;j<=b[0];j++)
            if((c[i+j-1]+=a[i]*b[j])>=DEPTH)
                c[i+j]+=c[i+j-1]/DEPTH,c[i+j-1]%=DEPTH;
    for(c[0]+=(c[c[0]+1]>0); !c[c[0]]&&c[0]>1; c[0]--);
}

void mul(big_num a,const int b)     // AC
{
    int i;
    for(a[1]*=b,i=2; i<=a[0]; i++)
    {
        a[i]*=b;
        if(a[i-1]>=DEPTH)
            a[i]+=a[i-1]/DEPTH,a[i-1]%=DEPTH;
    }
    for(; a[a[0]]>=DEPTH; a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
    for(; !a[a[0]] && a[0]>1; a[0]--);
}

void div(big_num c,big_num a,big_num b)
{
    int h,l,m,i;
    memset(c,0,sizeof(int)*(MAXN+1));
    c[0]=(b[0]<a[0]+1)?(a[0]-b[0]+2):1;
    for(i=c[0]; i; sub(a,b,c[i]=m,i-1),i--)
        for(h=DEPTH-1,l=0,m=(h+l+1)>>1; h>l; m=(h+l+1)>>1)
            if( comp(b,m,i-1,a) )   h=m-1;
            else                    l=m;
    for(; !c[c[0]]&&c[0]>1; c[0]--);
    c[0]=c[0]>1?c[0]:1;
}

void div(big_num a,const int b,int& c)      //c=a%b;    a=a/b;
{
    int i;
    for(c=0,i=a[0]; i; c=c*DEPTH+a[i],a[i]=c/b,c%=b,i--);
    for(; !a[a[0]]&&a[0]>1; a[0]--);
}

void sqrt(big_num b,big_num a)      //b=sqrt(a)
{
    int h,l,m,i;
    memset(b,0,sizeof(int)*(MAXN+1));
    for(i=b[0]=(a[0]+1)>>1; i; sub(a,b,m,i-1),b[i]+=m,i--)
        for(h=DEPTH-1,l=0,b[i]=m=(h+l+1)>>1; h>l; b[i]=m=(h+l+1)>>1)
            if(comp(b,m,i-1,a)) h=m-1;
            else                l=m;
    for(; !b[b[0]]&&b[0]>1; b[0]--);
    for(i=1; i<=b[0]; b[i++]>>=1);
}

int length(big_num a)
{
    int t,ret;
    for(ret=(a[0]-1)*DIGIT,t=a[a[0]]; t; t/=10,ret++);
    return ret>0?ret:1;
}

int digit(big_num a,int b)      //return bth digit of a;
{
    int i,ret;
    for(ret=a[(b-1)/DIGIT+1],i=(b-1)%DIGIT; i; ret/=10,i--);
    return ret%10;
}

int zeronum(big_num a)          //return the first one digit wihch is zero...
{
    int ret,t;
    for(ret=0; !a[ret+1]; ret++);
    for(t=a[ret+1],ret*=DIGIT; !(t%10); t/=10,ret++);
    return ret;
}

void comp(int t[],int l,int h,int d)        //divide l*(l+1)*...*(h) to t[]...; d=1 or -1
{
    int i,j,tmp;
    for(i=l; i<=h; i++)
        for(tmp=i,j=2; tmp>1; j++)
            while(!(tmp%j))
                t[j]+=d,tmp/=j;
}

void convert(int t[],int h,big_num a)       //conver C(m,n) or A(m,n)   from t[]    to ret;
{
    int i,j,tmp=1;
    memset(a,0,sizeof(int)*(MAXN+1));
    for(a[0]=a[1]=1,i=2; i<=h; i++)
        if(t[i])
            for(j=t[i]; j; tmp*=i,j--)
                if(tmp*i>DEPTH)
                    mul(a,tmp),tmp=1;
    mul(a,tmp);
}

const int MMM=10000;
void combination(big_num a,int m,int n)     //return a=C(m,n)
{
    int t[MMM]={0};
    comp(t,n+1,m,1);
    comp(t,2,m-n,-1);
  //  for(int i=0;i<m;i++)    printf("%d ",t[i]);
  //  printf("\n");
    convert(t,m,a);
}

void permutation(big_num a,int m,int n) //return a=A(m,n)
{
    int i,t=1;
    memset(a,0,sizeof(int)*(MAXN+1));
    a[0]=a[1]=1;
    for(i=m-n+1; i<=m; t*=i++)
        if(t*i>DEPTH)
            mul(a,t),t=1;
    mul(a,t);
}
