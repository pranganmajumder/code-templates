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
#define NMAX                    100005
#define NO                       cout << "NO" << endl
#define YES                      cout << "YES" << endl
 
// Ordered set
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
 
struct info
{
 
    int val,key ;
    info(int a,int b){
        val = a ;
        key = b ;
    }
    bool operator<(const info& p)const{
        if(val==p.val){
            return key<p.key;
        }
        else{
            return val>p.val;            //descending sort
        }
    }
};
 
 
 
map<int,int>freq ;
orderset<info>s ;
orderset<info>::iterator oit ;
 
 
int main()
{
//    freopen("A1.in","r",stdin);
//    freopen("A1.out","w",stdout) ;
//
    int n , q , a[NMAX] ;
    cin >> n ;
    for(int i = 0 ; i<n ; i++){
        cin >> a[i] ;
        freq[a[i]]++ ;
    }
    for(auto it : freq){
        s.insert(info(it.ss,it.ff)) ;  // val , key ;
    }
 
 
    cin >> q ;
    while(q--){
        char ch ; int key ;
        cin >> ch >> key ;
 
        int id = s.order_of_key(info(freq[key] , key)) ;
        s.erase(info(freq[key] , key)) ;
 
 
 
        if(ch=='+'){
            freq[key]++ ;
            s.insert(info(freq[key] , key)) ;
        }
 
        else{
            freq[key]--;
            if(freq[key]>0)s.insert(info(freq[key] , key)) ;
        }
 
        if(end(s)!=s.find_by_order(0)){                                   //if 0th index don't exist orderset(if 0th index exist)
             info first = *s.find_by_order(0) ;
             if(first.val>=8)YES;
             else if(first.val>=4 && end(s)!=s.find_by_order(1)){         //(if 1th index exist in orderset)
                  info second = *s.find_by_order(1) ;
                  if(first.val>=6 && second.val>=2)YES;
                  else if(first.val>=4){
                       if(second.val>=4)YES;
                       else{
                            if(end(s)!=s.find_by_order(2)){               // if 2th index exist in orderset
                                 info third = *s.find_by_order(2) ;
                                 if(third.val>=2)YES;
                                 else NO ;
                            }
                            else NO;
                       }
                  }
                  else NO ;
             }
             else NO ;
        }
        else NO;
 
    }
 
return 0;
}
