/** OOO
contest Link : https://www.hackerrank.com/contests/test-1-1565202619/challenges
problem name : The Exchange
**/


#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
using namespace std;

#define LL                      ll
#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pLL                     pair<LL,LL>
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
#define NMAX                100005









LL T,N,B[30005];
vector<LL>fact[NMAX],Prime[NMAX];
LL level[NMAX];/**kon page ar level koto **/
bool prVisit[NMAX],pageVisit[NMAX];/**prime visit , page Visit**/



void refresh();
void sieve(LL n)
{
    for(LL i=2;i<=n;i++){
        if(fact[i].size() == 0){
            for(LL j = i; j<=n;j+=i)
                fact[j].pb(i);/**j ar prime factor gulo factor[j] te save hoye zabe **/
        }
    }
}


void bfs(LL u)
{
    queue<LL>Q;
    Q.push(u);
    level[u] = 0;/**first page ar level zero **/
    pageVisit[u] = 1;

    while(!Q.empty())
    {
        LL u = Q.front();
        Q.pop();

        for(LL i = 0; i<fact[B[u]].size(); i++){/**u page ar value B[u] theke zesob prime a zaoya zay **/
            LL pr = fact[B[u]][i];
            if(prVisit[pr] == 0){/**oi prime ta zodi visited na hoy **/
                prVisit[pr] = 1;
                for(LL j = 0; j<Prime[pr].size(); j++){/** oi prime ar under a zesob page ache oder leveling kora lagbe **/
                    LL page = Prime[pr][j];
                    if( pageVisit[page] == 0){
                        pageVisit[page] = 1;
                        Q.push(page);
                        level[page] = level[u] + 1;
                    }
                }
            }

        }
    }

}

int main()
{
    sieve(100000);
    sc("%lld",&T);
    while(T--)
    {
        sc("%lld",&N);
        for(LL i = 1; i<=N; i++){
            sc("%lld", &B[i]);
            for(auto &it:fact[B[i]])
                Prime[it].pb(i);/**kon prime ar under e kon kon page ache seta save , i = page**/
        }
        bfs(1);//1 no page theke bfs
        pf("%lld\n",level[N]);
        refresh();
    }

}



void refresh()
{
    for(LL i=0;i<NMAX;i++){
        level[i] = -1;
        Prime[i].clear();
        prVisit[i] = 0;
        pageVisit[i] = 0;
    }
}
