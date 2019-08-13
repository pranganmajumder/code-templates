#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb          push_back
void pri(const vector<ll>&v);




bool mark[100000002];//1e7
ll nPrime;//3e5
vector<ll>Prime;//all prime number up 2 n;

void sieve(ll n)
{   ll i,j,sq=sqrt(1.0*n)+2;

    mark[1]=1;
    for(i=4;i<=n;i=i+2)mark[i]=1;


    for(i=3;i<=sq;i=i+2){
        if(!mark[i]){//prime
            for(j=i*i;j<=n;j+=2*i)//mark all odd multiple of i
                mark[j]=1;
        }
    }

    for(i=1;i<=n;i++){
        if(mark[i]==0)Prime.pb(i);
    }
    nPrime=Prime.size();//total prime upto n;
}

vector<ll>factor;
void factorize(ll n)
{   ll i,sq=sqrt(1.0*n)+1;
    for(i=0;i<nPrime&&Prime[i]<=sq;i++){
        if(mark[n]==0)break;/*Checks if n is prime or not*/
        if(n%Prime[i]==0){
            while(n%Prime[i]==0){
                n=n/Prime[i];
                factor.pb(Prime[i]);
            }
            sq=sqrt(1.0*n)+1;
        }
    }
    if(n!=1)factor.pb(n);//1 prime na, tai n ke vag korte korte 1 thakle ignore 1
/**jodi onekboro songkhar(1e12) factorize korte bole tokhon
38 line mark[n] ai optimization kaj korbe na
38 line ta comment kore dite hobe
**/
}

int main()
{
    ll n;
    cin>>n;
    clock_t startTime = clock() ;
    sieve(n);

    printf("total Prime = %lld\n",nPrime);

//    pri(Prime);

    ll number;
    while(cin>>number){

//    if(mark[number]==0)printf("prime\n");

        factorize(number);
        pri(factor);
        factor.clear();
    }
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
}




void pri(const vector<ll>&v)
{   cout<<"factorization is "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
}
