/**OOO

using operator overloading       https://ideone.com/2zqeSy

help ==>>
https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/

https://stackoverflow.com/questions/2439283/how-can-i-create-min-stl-priority-queue/43183813#43183813



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
//#define Mod                     1000000007
#define hiii                    1e9//1000000000
#define looo                   -1e9//-1000000000

#define Booster                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define _cout(x)               cout << x << endl ;
#define yes                    cout << "YES" << endl
#define no                     cout << "NO" << endl
#define PrintVector(v)         for(auto it : v)cout << it <<' ';cout << endl
#define ScanVector(v)          for(auto &it:v)cin >> it ;

#define debug(x)                cout << x << "   output" << endl
#define NMAX                   200005





struct data{
    int dif ;
    pair<int,int>pv ;
    data(int x , pair<int,int> y){
        dif = x ;
        pv = y ;
    }


};



// this is an strucure which implements the
// operator overlading
struct cmp{
    bool operator() (data& p1 , data& p2){
        if(p1.dif == p2.dif){
            return p1.pv.ff > p2.pv.ff ;
        }
        return p1.dif < p2.dif ;
    }
};

int main()
{
        priority_queue<data ,vector<data> , cmp >PQ ;

        PQ.push(data(5,{1,6})) ;
        PQ.push(data(2,{7,9})) ;
        PQ.push(data(2,{2,4})) ;

        while(!PQ.empty()){
            data u = PQ.top() ;
            PQ.pop() ;
            cout << u.dif << "  " << u.pv.first <<  "   " << u.pv.second << endl ;
        }
}





 /**

 5 {1 6}
 2 {2 4}
 2 {7 9}

 diff zar beshi take age rakhbe , diff soman hole zar left kom take age rakhbe .

 problem link : https://codeforces.com/contest/1353/problem/D

 **/
