/**OOO**/
/**author : Prangan Majumder **/
#include<bits/stdc++.h>
using namespace std;
#define ll                      long long
#define ull                     unsigned long long
#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pii                     pair<string,int>
#define mk                      make_pair
#define pb                      push_back
#define ff                      first
#define ss                      second
#define PI                      acos(-1.0)

#define pf                      printf
#define sc                      scanf
#define hiii                    1e9//1000000000
#define looo                   -1e9//-1000000000
#define arraysize(arr)          sizeof(arr)/sizeof(arr[0])

vector<int>EDGE[200005];
int visit[200005];


void addEDGE(int x,int y){
    EDGE[x].pb(y);
    EDGE[y].pb(x);
}

void bfs(int s)
{
    queue<int>Q;
    Q.push(s);
    visit[s]=2;//make visited

    while(!Q.empty()){
        int father=Q.front();
        Q.pop();
        for(int i=0;i<EDGE[father].size();i++){
            int child=EDGE[father][i];
            if(visit[child]==0){//if unvisited
                visit[child]=2;//make it visited
                Q.push(child);//then push the child into queue
            }
        }
    }
}


int main()
{

return 0;
}
