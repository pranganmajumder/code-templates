
/**OOO**/
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

// Ordered set
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5



int main()
{


    orderset<int>s;
    orderset<int>::iterator it;

    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }

    cout<<"after insering into order set  the value will  be   "<<endl;
    for(it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
    }
    cout<<endl<<endl<<endl;

    cout<<"1th element of order set is   "<<*s.find_by_order(1)<<endl;//index 1 ar je element seta print korbe
    cout<<"the expected index of 20  is    "<<s.order_of_key(20)<<endl;//value ta kon index a bosbe seta print korbe


return 0;
}




