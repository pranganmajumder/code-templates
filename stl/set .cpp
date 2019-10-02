/**OOO**/
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




int main()
{
    int  n ,q;
    cin >> n;
    set<int>myset;

    for(int i=1 ; i<=n ; i++){
        int x ;
        cin >> x ;
        myset.insert(x);
    }

    while(cin >> q){
        auto it = myset.upper_bound(q);
        if(it == myset.end() ){// na paile
            cout << "pai nai  but iterator value is " << *it <<endl;
        }
        else cout << *it << endl ;


    }
    //myset.erase()

}

/**

   10 20 30 40 50 60
myset.find() a jodi element khuje pay tahole oi value tai return korbe ex :
uporer set a jodi find(4) dei tahole iterator return korbe end() mane sese cole zabe
find(40) dile 40 return korbe iterator . that means paile oi value tai return korbe ,
na paile myset.end() return korbe .



myset.lower_bound(val)
val pay , ba tar ceye boro thake tahole oi value / boro number ta retunr korbe
na paile myset.end() return korbe
ex: myset.lower_bound(30) dile 30 return korbe , 35 dile 40 return korbe
60 dileo 60 return korbe , 1 dile 10 return korbe but 65 dile myset.end()
return korbe


myset.upper_bound(val)
val paile , tar samner value return korbe ex :
myset.upper_bound(1) dile 10 return korbe
myset.upper_bound(10) dile 20 return korbe
myset.upper_bound(50) dile 60 retun korbe
but myset.upper_bound(60) dile myset.end() return korbe


myset.erase(val)
zodi set a value thake tahole erase hobe , nahole hobe na erase.

multiset =>>>
ata normal array ar motoi

multiset<int>mulset
multiset.insert(val)

zodi erase korte hoy tahole aktu carefull karon duplicate element thakte pare
ex : 10 20 30 30 30 40 50
mulset.erase(30) deya zabe na
auto it = mulset.find(30) dite hobe , tahole
10 20 30 30 30 40 50
      ^ iterator point korbe

tarpor mulset.erase(it) dile prothom 30 erase hoye zabe

**/


