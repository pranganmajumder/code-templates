/**OOO**/
//problem link : https://www.codechef.com/problems/REVERSE
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
#define INFI                    99999999
#define pf                      printf
#define sc                      scanf
//#define Mod                     1000000007
#define hiii                    1e9//1000000000
#define looo                   -1e9//-1000000000
#define NMAX                    100005
 
 
 vector<pii>graph[NMAX] ;
 int d[NMAX] ; 
 int n , m , u, v ;



struct info{
    int a , b ;
    //info(){} ;
    info(int aa , int bb){
        a = aa , b = bb ;
    }
    bool operator<(const info& p)const{
        return b>p.b ;
    }
};


void pqprint(priority_queue<info>pq)
{   cout << "priority queue printing   " ;
    while (!pq.empty())
    {
        cout << "(" << pq.top().a << ' '<<pq.top().b << ")" ;
        pq.pop() ;
    }
    cout << endl << endl ;
}

 int dkstra(int s , int last )
 {
     for(int i = 1 ; i<=NMAX ; i++)d[i] = INFI ;
     priority_queue<info>PQ ;
     PQ.push(info(s,0)) ;
     d[s] = 0 ;

     while (!PQ.empty())
     {
         int u = PQ.top().a ;
         //int cc = PQ.top().b ;
         
         pqprint(PQ) ;
         PQ.pop() ;
         //if(cc != d[u])continue ;
         for(int i = 0 ; i<graph[u].size() ; i++){
             int v = graph[u][i].ff ;
             if(d[u] + graph[u][i].ss < d[v]){
                 d[v] = d[u] + graph[u][i].ss ;
                 PQ.push(info(v,d[v])) ;
             }
         }

     }
     return (d[last] == INFI ? -1 : d[last]) ;

 }
 
 
int main()
{
    cin >> n >> m ;
    for(int i = 0 ; i<m ; i++){
        cin >> u >> v ;
        graph[u].pb({v,0}) ;
        graph[v].pb({u,1}) ;
    }
    cout << dkstra(1 , n ) << endl ;
}
