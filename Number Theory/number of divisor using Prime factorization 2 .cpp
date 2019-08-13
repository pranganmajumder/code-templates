
/**OOO**/
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
using namespace std;


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
#define RUN_CASE(t,T)           for(t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)

bool mark[10000000];
ll nPrime;
vector<ll>Prime;

void sieve(ll n)
{
    ll i,j,sq=sqrt(1.0*n)+2;
    mark[1]=1;
    for(i=4;i<=n;i+=2)mark[i]=1;
    for(i=3;i*i<=n;i+=2){
        if(!mark[i]){//jodi prime hoy
            for(j=i*i;j<=n;j+=2*i)mark[j]=1;
        }
    }
    for(i=1;i<=n;i++){
        if(mark[i]==0)Prime.pb(i);
    }
    nPrime=Prime.size();
}

ll nod(ll n)
{
    ll c=0,res=1;
    for(ll i=0;i<nPrime&&(Prime[i]*Prime[i])<=n;i++){
        c = 0;
        if(n%Prime[i]==0){
            while(n%Prime[i]==0){
                n/=Prime[i];
                c++;
            }
            res = res * (c + 1);
        }
    }
    if(n>1)res = res * (1 + 1);
    return res;
}

int main()
{
    sieve(1e6+10);//it will work if your given_input<=1e12

    ll n;
    while(scanf("%lld",&n)){
        ll res = nod(n);
        cout<<res<<endl;
    }
return 0;
}



