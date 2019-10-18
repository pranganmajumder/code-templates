/**OOO

    problem link : https://codeforces.com/contest/1237/problem/C2
    using editorial

**/
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
#define Mod                     1000000007
#define hiii                    1e9//1000000000
#define looo                   -1e9//-1000000000
#define NMAX                    100005


inline void speedUp(){ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);}

LL n ;

struct info{
    LL x , y , z , id ;
}p[NMAX];



void fun2(vector<info> & v)//ai vector ar x, y dutoi fix // dhore dhore z remove kora lagbe
{
    map<LL , info > zf ;
    for(auto it : v ){
        info t = it ;
        zf[t.z] = t ;
    }

    int c = 0 ;
    info last ;

    for(auto it : zf){
        if(c==0)
            last = it.ss ;
        else
            cout << last.id << ' ' << it.ss.id << endl ;
        c^=1 ;
    }

    v.clear() ;
    if(c==1)v.pb( last ) ;
}



void fun1(vector<info> &v)//x fix , akhon y fix gulao rakha lagbe :: note = reference hisebe vector send kora hoyeche
{
    map<LL , vector< info > > yf ;
    for(auto it : v ){
        info t = it ;
        yf[t.y].pb(t) ; // y fix ar sobgula  point rakhlam
    }

    int c = 0 ;
    info last ;

    for(auto it : yf){
        fun2(it.ss) ;
        if(it.ss.size() == 1){
            if(c==0)
                last = it.ss[0] ;
            else
                cout << last.id << ' ' << it.ss[0].id << endl ;
            c^=1 ;
        }
    }

    v.clear() ;
    if(c==1)v.pb( last ) ; /** reference hisebe vector pathale za modify kora hobe setai zekhan theke send kora hoyeche sekhane save hoye thakbe**/

}


int main()
{
    speedUp() ;
    cin >>  n ;


    map<LL , vector< info > > xf ; // map ar vetore vector
    vector<info>v(n+1) ;

    for(int i = 1 ; i<=n ; i++){
        cin >> p[i].x >> p[i].y >> p[i].z ;    p[i].id = i ;
        v[i] = p[i] ;

        xf[ v[i].x ].pb(v[i]) ; // x fix
        /** zehetu map ar vetore vector value hisebe tai push_back() use kora geche , nahole kora zeto na **/
    }

    int c = 0 ;
    info last ;

    for(auto it : xf){//sobgular x fix
        fun1(it.ss) ; /** akhane akta vector pathay dicche **/
        if(it.ss.size() == 1){
            if(c==0)
                last = it.ss[0] ;
            else cout << last.id << ' ' << it.ss[0].id << endl ;
            c^=1 ;
        }
    }

}
