/**OOO

problem : https://toph.co/p/man-in-the-queue

**/
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

// Ordered set
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
ll n,q,p,v,m,type,x;
struct info
{

    ll w,indx;
    info(ll a,ll b){
        w=a;
        indx=b;
    }
    bool operator<(const info& p)const{
        if(w==p.w){
            return indx<p.indx;
        }
        else{
            return w>p.w;
        }
    }
};

//int fun(orderset<info>s,ll m){
//    orderset<info>::iterator it;
//
//    ll lo=0,hi=n-1,mid,res=0;
//    while(lo<=hi){
//        mid=(lo+hi)/2;
//        ll value=(*s.find_by_order(mid)).w;
//        if(mid*m<=value){
//            lo=mid+1;
//            res=mid;
//        }
//        else hi=mid-1;
//    }
//    return res+1;
//
//}

int main()
{
    int t;
    scanf("%lld",&t);
    while(t--){

        orderset<info>s;
        orderset<info>::iterator it;
        scanf("%lld",&n);
        ll arr[50005];
        for(ll i=0;i<n;i++){
            scanf("%lld",&x);
            s.insert(info(x,i));
            arr[i]=x;
        }

        scanf("%lld",&q);
        while(q--){
            scanf("%lld",&type);
            if(type==1){
                scanf("%lld%lld",&p,&v);
                ll i=p-1;
                s.erase(info(arr[i],i));
                arr[i]=v;//update the array;
                s.insert(info(arr[i],i));
            }
            else{
                scanf("%lld",&m);
                        /**process binary **/
                 ll lo=0,hi=n-1,mid,res=0;
                    while(lo<=hi){
                        //if(lo<0||hi>=n)break;
                        mid=(lo+hi)/2;
                        ll value=(*s.find_by_order(mid)).w;
                        if(mid*m<=value){
                            lo=mid+1;
                            res=mid;
                        }
                        else hi=mid-1;
                    }
                printf("%lld\n",res+1);
            }
        }
}
return 0;
}


//    //*order set output
//        for(it=s.begin();it!=s.end();it++){
//            info x = *it ;
//            cout<<x.w<<"       "<<x.indx<<endl;
//        }
