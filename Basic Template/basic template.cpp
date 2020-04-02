/**OOO**/
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



/***********************************************************************************************************************/

template< typename T > void dekhao(T val){cout << "template val   is  == " << val << endl ;}


template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
	os << "{";
	typename vector< T > :: const_iterator it;
	for ( it = v.begin(); it != v.end(); it++ ) {
		if ( it != v.begin() ) os << ", ";
		os << *it;
	}
	return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
	os << "[";
	typename set< T > :: const_iterator it;
	for ( it = v.begin(); it != v.end(); it++ ) {
		if ( it != v.begin() ) os << ", ";
		os << *it;
	}
	return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
	os << "[";
	typename map< F , S >::const_iterator it;
	for ( it = v.begin(); it != v.end(); it++ ) {
		if ( it != v.begin() ) os << ", ";
		os << it -> first << " = " << it -> second;
	}
	return os << "]";
}

#define deb(x) cerr<< #x << " = " << x << endl;

/***********************************************************************************************************************/



//#define artcell
void Ekfile()
{
    #ifdef artcell
        freopen("A1.in", "r", stdin) ;
        freopen("A1.out", "w" , stdout) ;
    #endif

}

/**********************************************************************************************************************/


















int main()
{
    Booster ;
}
