/**OOO**/
/**problem link: https://toph.co/p/a-unique-array**/
#include<bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long uLL;
using namespace std;

#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pf                      printf
#define sc                      scanf
#define  MX                     100005
#define INF                     100006

LL t,T,N,q,x,y,caseno=1;
LL A[MX],tot=0;

struct leftRight{
    LL L,R;
}pos[MX];


struct info{
    LL one=0;
}tree[MX*4];

void createTree(LL node, LL lo,LL hi)
{
        if(lo==hi){
            tree[node].one=1;
            return ;
        }
        LL left=node<<1;LL right=left+ 1;LL mid=(lo+hi)>>1;

        createTree(left,lo,mid);
        createTree(right,mid+1,hi);
        tree[node].one=tree[left].one  +  tree[right].one;
}

void update(LL node,LL lo, LL hi, LL i, LL j, LL val)
{
        if(hi<i||lo>j)return ;
        if(lo>=i&&hi<=j){
                tree[node].one+=val;
                return ;
        }

               LL left=node<<1;LL right=left+ 1;LL mid=(lo+hi)>>1;

         update(left,lo,mid,i,j,val);
         update(right,mid+1,hi,i,j,val);

        tree[node].one=tree[left].one  + tree[right].one;
}

LL query(LL node , LL lo, LL hi, LL val)
{
        if(lo==hi){
               if(tree[node].one==val)return lo;
               return -1;
        }
        else{
                        LL left=node<<1;LL right=left+ 1;LL mid=(lo+hi)>>1;
                if(tree[left].one<val){
                        return query(right,mid+1,hi,val-tree[left].one);
                }
                else{
                    return query(left,lo,mid,val);
                }
        }
}

int main()
{
    LL i,idx,y;
    LL left,mid,right;
    LL Lev,Miv,Riv;
    //freopen("A1.in","r",stdin);
    //freopen("A1.out","w",stdout);

        sc("%lld",&T);
        for(t=1;t<=T;t++)
        {
                sc("%lld%lld",&N,&q);
                tot=N;

                for(i=1;i<=N;i++){
                        sc("%lld",&A[i]);
                }


                pos[1].L=-1;    pos[1].R=2;  pos[N].L=N-1;  pos[N].R=INF;

                if(N==1){               /**if N==1**/
                    pos[1].L=-1;
                    pos[1].R=INF;
                }

                for(i=2;i<N;i++) /**initial position setup**/
                {
                        pos[i].L=i-1;
                        pos[i].R=i+1;
                }



                createTree(1,1,N);              /**create main tree**/

                printf("Case %lld:\n",t);

                while(q--)/**query **/
                {
                           sc("%lld%lld",&idx,&y);
                           idx++;

                           LL  p=query(1,1,N,idx);

                           A[p]=y;
                           mid=p;
                           left=pos[p].L;
                           right=pos[p].R;


                             if(left==-1&&right!=INF)//sudhu right ar ta ache
                            {
                                       Miv=A[p];
                                       Riv=A[right];
                                       if(Miv==Riv){
                                                LL t1=pos[pos[p].R].R;

                                                pos[p].R=pos[pos[p].R].R;
                                                pos[t1].L= p;


                                                update(1,1,N,right,right,-1);
                                                tot--;
                                       }
                                       else if(Miv!=Riv){
                                                Miv=A[p];
                                       }
                            }

                            else if(left!=-1&&right==INF)//sudhu left ar ta ache
                            {
                                       Miv=A[p];
                                       Lev=A[left];
                                       if(Miv==Lev){
                                                LL t1=pos[pos[p].L].L;
                                                pos[p].L=pos[pos[p].L].L;
                                                pos[t1].R=p;

                                                update(1,1,N,left,left,-1);
                                                tot--;
                                       }
                                       else if(Miv!=Lev){
                                                Miv=A[p];
                                       }
                            }
                            else if(left!=-1&&right!=INF)// left & right duitai ache
                            {
                                        Miv=A[p];
                                        Lev=A[left];
                                        Riv=A[right];

                                        if(Lev==Miv&&Miv==Riv)
                                        {
                                                LL t1=pos[pos[p].L].L;
                                                pos[p].L= pos[pos[p].L].L;
                                                pos[t1].R = p ;

                                                LL t2=pos[pos[p].R].R;
                                                pos[p].R=pos[pos[p].R].R;
                                                pos[t2].L= p;

                                                update(1,1,N,left,left,-1);
                                                update(1,1,N,right,right,-1);
                                                tot-=2;

                                        }
                                        else if(Lev==Miv)
                                        {
                                                LL t1=pos[pos[p].L].L;
                                                pos[p].L=pos[pos[p].L].L;
                                                pos[t1].R = p ;


                                                update(1,1,N,left,left,-1);
                                                tot--;
                                        }
                                        else if(Miv==Riv)
                                        {
                                                LL t1=pos[pos[p].R].R;
                                                pos[p].R=pos[pos[p].R].R;
                                                pos[t1].L=  p;

                                                update(1,1,N,right,right,-1);
                                                tot--;
                                        }
                            }

                           printf("%lld\n",tot);
                }
        }

return 0;
}

/**shahadat solution

https://ideone.com/8TJqgI?fbclid=IwAR0li5CBHpHhKKO5zJctriLD9tPSkLXAHAvxzGPfl62HCTh5RQquajI-yMI

**/
