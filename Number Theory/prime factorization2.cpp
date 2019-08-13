#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;


#define pb                  push_back



vector<ll>v1,v2;

void pri(vector<ll>v)
{   cout<<"vector printing "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
}

vector<ll> primeFactorize(ll n)
{
    ll i,sq=sqrt(n*1.0);


    if(n%2==0){
        v1.pb(2);
        while(n%2==0){
            n/=2;
        }
    }

    for(i=3;i<=sq+1;i=i+2){
        while(n>0){
            if(n%i==0){
                n/=i;
                v1.pb(i);
            }
            else{
                break;
            }
        }
    }
    if(n!=1)v1.pb(n);
    return v1;
}



                                                    /****************driver program**************/
int main()
{
    ll n;
    cin>>n;
    vector<ll>temp=primeFactorize(n);
    pri(temp);

return 0;
}



