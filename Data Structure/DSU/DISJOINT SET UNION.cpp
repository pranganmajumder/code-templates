/**OOO**/
//UVA 459 - GRAPH CONNECTIVITY
//FIND OUT TOTAL SUBGRAPH OF A GRAPH
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define pf                      printf
#define sc                      scanf
int par[100005];
int member[100005];

int Find(int x){
    if(par[x]==x)return x;
    return par[x]=Find(par[x]);
}
void Union(int a,int b)
{
    par[Find(b)]=Find(a);
}


int main()
{
   int t,id,f,F,i,j,T;
   string u,v;

   //freopen("A1.in","r",stdin);
   // freopen("A1.out","w",stdout);
   cin>>T;
   for(t=1;t<=T;t++){
        scanf("%d",&F);

        id=1;
        map<string,int>mmap;
        for(i=1;i<=100000;i++){//default value
            par[i]=i;
            member[i]=1;//prottekei tader network a 1 jon kore ache initially
        }

        for(f=1;f<=F;f++){
            cin>>u>>v;
            if(mmap[u]==0)mmap[u]=id++;
            if(mmap[v]==0)mmap[v]=id++;

            int p1=Find(mmap[u]);
            int p2=Find(mmap[v]);

            if(p1!=p2){//if parents are not equal,then merge the two parents member
                member[p1]+=member[p2];//p1 ar total membar ar sathe p2 ar total member jog
                member[p2]+=member[p1];//p2 ar total membar ar sathe p1 ar total member jog
                Union(mmap[u],mmap[v]);
            }
            printf("%d\n",member[p1]);
        }
   }


//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
return 0;
}
