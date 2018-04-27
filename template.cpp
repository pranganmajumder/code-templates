/**OOO**/
#include<bits/stdc++.h>
using namespace std;
#define ll                      long long
#define ull                     unsigned long long
#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pii                     pair<int,int>
#define mk                      make_pair
#define pb                      push_back
#define ff                      first
#define ss                      second
#define PI                      acos(-1.0)

#define pf                      printf
#define sc                      scanf



template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

struct struct_type
{
    int a;
    float f;
    double d;
    char c;
    string s;
};




bool compare(struct_type s1,struct_type s2){//sort ascending order
    return s1.a<s2.a;
}
bool cmp(int a,int b){return a<b;}



string toString(ll n)
{
    stringstream ss;
    ss<<n;
    string ret=ss.str();
    return ret;
}

ll toLong(string a)
{
    ll num;
    stringstream ss(a);
    ss>>num;
    return num;
}



bool isVOWEL(char ch){
    ch=toupper(ch);
    if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')return true;
    return false;
}
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


ll kache(ll first,ll second,ll terget)
{//amar "target" ki "first" theke kache naki "second" theke kache???
    ll t1=abs(first-terget);
    ll t2=abs(second-terget);
    ll temp=min(t1,t2);
    if(temp==t1)return first;
    return second;
}

int f(int n)//sum of first n number
{
    return (n*(n+1))/2;
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //clock_t startTime = clock() ;
	//freopen("A1.in","r",stdin);
    //freopen("A1.out","w",stdout);

    //struct_type arr[101];
    //sort(arr,arr+n,compare);



//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
return 0;
}


/**
#define ll                      long long
#define lf                      double
#define Lf                      long double
#define ull                     unsigned long long

#define mems(x,y)               memset(x,y,sizeof(x))
#define arraysize(arr)          sizeof(arr)/sizeof(arr[0])

#define pf                      printf
#define sc                      scanf

#define input(a)                sc("%d",&a)
#define iinput(a,b)             sc("%d%d",&a,&b)
#define llinput(a)              sc("%lld",&a)
#define lliinput(a,b)           sc("%lld %lld",&a,&b)
#define lfinput(a)              sc("%lf",&a);
#define lfiinput(a,b)           sc("%lf %lf",&a,&b);


#define output(a)               pf("%d\n",a)
#define ooutput(a,b)            pf("%d %d\n",a,b)
#define lloutput(a)             pf("%lld\n",a)
#define llooutput(a,b)          pf("%lld %lld\n",a,b)
#define lfoutput(a)             pf("%lf\n",a)
#define lfooutput(a,b)          pf("%lf %lf\n",a,b)


take string in c
char st[1000];//string size with space
gets(st);//scanf
puts(st);//printf


**/
