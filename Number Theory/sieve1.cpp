#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb          push_back
void pri(const vector<ll>&v);




ll mark[100000002];//1e8
ll nPrime;//3e5
vector<ll>allPrimeUp2N;

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
        if(mark[i]==0)allPrimeUp2N.pb(i);
    }
    nPrime=allPrimeUp2N.size();//total prime upto n;
}


int main()
{
    ll n;
    cin>>n;
    clock_t startTime = clock() ;
    sieve(n);
    printf("total Prime = %lld\n",nPrime);

//    pri(allPrimeUp2N);

//    ll number;
//    cin>>number;
//    if(mark[number]==0)printf("prime\n");

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
}




void pri(const vector<ll>&v)
{   cout<<"vector printing "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
}
