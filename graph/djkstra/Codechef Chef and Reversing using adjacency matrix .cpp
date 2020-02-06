
/** according to mahbubul hasan shanto adjacency matrix **/
#include<iostream>
#define NMAX    10000
#define INIF    99999999


using namespace std ;

int graph[NMAX][NMAX] , cost[NMAX][NMAX] , n , m , visited[NMAX] , d[NMAX] ;
void initgraph(){
    for(int i = 0 ; i<NMAX; i++){
        for(int j = 0 ; j<NMAX ; j++)graph[i][j] = -1 ;
    }
}
void initdis(){
    for(int i = 0 ; i<NMAX ; i++)
        d[i] = INIF ;
}


int djkstra(int s , int last )
{
    d[s] = 0 ;
    int u , mn , ck ; 

    while (1){
        mn = 99999999 , ck = 0 ;
        for(int i = 1 ; i<=n ; i++){
            if(visited[i] == 0 && d[i] < mn)mn = d[i] , u = i , ck = 1 ;
        }
        if(ck == 0)break ;
        visited[u] = 1 ;
        for(int i = 1 ; i<=n ; i++){
            if(graph[u][i] == 1 && visited[i] == 0 && d[u] + cost[u][i] < d[i])
                d[i] = d[u] + cost[u][i] ;
        }
    }
    return (d[last] == INIF ? -1 : d[last]) ;
}

int main()
{   initgraph() ;
    initdis() ;

    cin >> n >> m ;
    for(int i = 0 ; i<m ; i++){
        int u , v ;
        cin >> u >> v ;
        graph[u][v] = 1 ;
        graph[v][u] = 1 ;
        cost[u][v] = 0 ;
        cost[v][u] = 1 ;
    }
    cout << djkstra(1 , n) << endl ;
}