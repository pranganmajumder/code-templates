/**OOO**/
/**SPOJ Prime Jenerator**/
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
using namespace std;
#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pb                      push_back
#define pf                      printf



ll mark[10000000];
vector<ll>Prime;

void sieve(ll n)
{
    ll i,j,sq=sqrt(1.0*n)+2;
    mark[1]=1;//not prime
    for(i=4;i<=n;i=i+2)mark[i]=1;
    for(i=3;i<=sq;i=i+2){
        if(!mark[i]){
            for(j=i*i;j<=n;j+=(2*i))mark[j]=1;
        }
    }
    for(i=1;i<=n;i++){
        if(!mark[i])Prime.pb(i);
    }
}

int arr[100005];//size= B-A+1;
int segment(ll a,ll b){
    ll sqB=sqrt(1.0*b)+2,i,j;//sqrt(B)
    mems(arr,0);// Make all index of arr 0.

    if(a==1)a++;
    for(i=0;i<Prime.size()&&Prime[i]<=sqB;i++){
        int p=Prime[i];
        j=p*p;
        if(j<a)j=((a+p-1)/p)*p;// If j is smaller than a, then shift it inside of segment [a,b]
        for(;j<=b;j+=p){
            arr[j-a]=1;/*mark as not prime*/
        }
    }
    int res=0;
    for(i=a;i<=b;i++){
        if(!arr[i-a]){// If it is not marked, then it is a prime
            pf("%lld\n",i);//print every prime number from a to b;
            res++;//count total prime from a to b;
        }
    }
    printf("\n");
    return res;
}


int main()
{
    ll n=sqrt(1000000009);// sqrt(B)
    sieve(n);

    ll q,a,b;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld%lld",&a,&b);
        ll res=segment(a,b);
        //pf("%lld\n",res);//res= total prime between that range
    }
return 0;
}




