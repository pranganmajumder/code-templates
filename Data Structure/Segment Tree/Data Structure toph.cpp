/**OOO**/
//problem link : https://toph.co/p/data-structure
//hints : it can also be done using order set
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
//#define Mod                     1000000007
#define hiii                    1e9//1000000000
#define looo                   -1e9//-1000000000
#define Nsize                   100005

int A[Nsize],a[Nsize],B[Nsize];
struct info{
    int one = 0,val;
}tree[4*Nsize];

void createTree(int node, int lo, int hi)
{
    if(lo==hi){
        tree[node].one = 0;
        return ;
    }
    int left = node<<1;int right = left + 1 ;int mid = (lo+hi)>>1;

    createTree(left,lo,mid);
    createTree(right,mid+1,hi);

    tree[node].one = tree[left].one + tree[right].one;
}


void update(int node, int lo,int hi,int i,int j,int val)
{
    if(hi<i || lo>j)return ;
    if(lo>=i && hi<=j){
        tree[node].one += val;
        return ;
    }
    int left = node<<1;int right= left+1;int mid = (lo+hi)>>1;
    update(left,lo,mid,i,j,val);
    update(right,mid+1,hi,i,j,val);

    tree[node].one = tree[left].one + tree[right].one;
}

int query(int node ,int lo, int hi,int val)
{
    if(lo==hi)return lo;
    else{
        int left = node<<1;int right = left+1;int mid = (lo+hi)>>1;
        if(tree[left].one<val){
            return query(right,mid+1,hi,val-tree[left].one);
        }
        else return query(left,lo,mid,val);

    }

}

vector<int>vec[1000006];

int main()
{


    int N;
    sc("%d",&N);
    createTree(1,1,N);
    for(int i=1;i<=N;i++){
        sc("%d",&A[i]);
        a[i] = A[i];
    }
    for(int i=1;i<=N;i++)sc("%d",&B[i]);

    sort(a+1,a+N+1);

    for(int i=1;i<=N;i++){
        vec[a[i]].pb(i);
    }

    for(int i=1;i<=N;i++){
        int pos = vec[A[i]].back();
        vec[A[i]].pop_back();

        update(1,1,N,pos,pos,1);
        int res = query(1,1,N,B[i]);
        printf("%d\n",a[res]);
    }

}
