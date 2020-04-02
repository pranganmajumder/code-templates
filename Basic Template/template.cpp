/**OOO**/
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
using namespace std;

#define LL                      ll
#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pii                     pair<int,int>
#define mk                      make_pair
#define pb                      push_back
#define ff                      first
#define ss                      second
#define PI                      acos(-1.0)

#define pf                      printf
#define sc                      scanf
//#define Mod                     1000000007
#define hiii                    1e9//1000000000
#define looo                   -1e9//-1000000000

#define Booster                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define _cout(x)               cout << x << endl ;
#define yes                    cout << "YES" << endl
#define no                     cout << "NO" << endl
#define PrintVector(v)         for(auto it : v)cout << it <<' ';cout << endl
#define ScanVector(v)          for(auto &it:v)cin >> it ;

#define debug(x)                cout << x << "   output" << endl
#define NMAX                   200005

template< typename T > void dekhao(T val){cout << "template val   is  " << val << endl ;}


//
//
//int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
//inline int Set(int n,int pos) { return n = n | (1LL << pos); }
//inline int Reset(int n,int pos) { return n = n & ~(1LL << pos); }
//inline bool Check(int n,int pos) { return (bool)(n & (1LL << pos)); }
//inline int Count(ll n) { return __builtin_popcountll(n); }
////typedef pair<int,int> pint;


/**  top , Right , Down , Left
int dx[] = {-1,  0 ,+1 , 0 } ;
int dy[] = { 0, +1 , 0 , -1} ;

**/

/**
// Ordered set
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset =
tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4
//cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl; // 0 //cout<<X.order_of_key(1)<<endl; // 0
//cout<<X.order_of_key(3)<<endl; // 2 //cout<<X.order_of_key(4)<<endl; // 2
//cout<<X.order_of_key(400)<<endl; // 5



struct info
{
        int val,id;
	info(){};
        info(int a,int b){
                val = a;
                id = b;
        }

        bool operator<(const info& p)const{

                if(val==p.val){
                        return id<p.id;
                }
                else{
                        return val<p.val;//ascending sort korbe. descending korte hole > pass koro
                }
        }
};

**/


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

/**

bool compare(struct_type s1,struct_type s2){//sort ascending order
    return s1.a<s2.a;
}
bool cmp(int a,int b){return a<b;}

bool com(const string a,const string b){//string compare which length is small
    return a.size()<b.size();
}


**/

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

ll power(ll base,ll p){ll mul=1;for(ll i=1;i<=p;i++)mul*=base;return mul;}

/**
            /////////////////////////////////////////////////////moooooooooooooooooooood////////////////////////////////
ll bigmod(ll N,ll P,ll Mod)//N=base P=power
{
    if(P==0) return 1;
    if(P%2==0)
    {
        ll ret=bigmod(N,P/2,Mod);
        return ((ret%Mod)*(ret%Mod))%Mod;
    }
    else return ((N%Mod)*(bigmod(N,P-1,Mod)%Mod))%Mod;

}
ll ModInverse(ll number,ll MOD){return bigmod(number, MOD-2, MOD);}//(x^-1 % m)


ll mulmod(ll base,ll p)//base, p bar jog mane 3 dia 5 ke gun
{
    ll res=0;
    base=base%mod;
    while(p>0){
        if(p%2==1)res=(res+base)%mod;
        base=(base*2)%mod;//base=(base+base)%mod;
        p=p/2;
    }
    return res%mod;
}

ll bigmod2(ll base,ll p)//base, p bar gun
{
    ll res=1;
    base=base%mod;
    while(p>0){
        if(p%2==1)res=mulmod(res,base);//res=(res*base)%mod;
        base=mulmod(base,base);//base*base;base=(base*base)%mod;
        p=p/2;
    }
    return res;
}

**/

ll kache(ll first,ll second,ll terget)
{//amar "target" ki "first" theke kache naki "second" theke kache???
    ll t1=abs(first-terget);
    ll t2=abs(second-terget);
    ll temp=min(t1,t2);
    if(temp==t1)return first;
    return second;
}



ll ceel(ll lob,ll hor){ return ((lob-1)/hor)+1;}



//#define artcell
void Ekfile()
{
    #ifdef artcell
        freopen("A1.in","r",stdout);
        freopen("A1.out","w",stdout) ;
    #endif // scorpion
}

int main()
{
    //clock_t startTime = clock() ;
    //Ekfile();

    //struct_type arr[101];
    //sort(arr,arr+n,compare);



//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
return 0;
}


