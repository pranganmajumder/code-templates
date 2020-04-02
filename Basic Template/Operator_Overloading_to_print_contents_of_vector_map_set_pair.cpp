
// https://www.geeksforgeeks.org/operator-overloading-cpp-print-contents-vector-map-pair/


#include                            <iostream>
#include							<list>
#include                            <stdio.h>
#include                            <math.h>
#include                            <string.h>
#include                            <time.h>
#include                            <stdlib.h>
#include                            <string>
#include                            <bitset>
#include                            <vector>
#include                            <set>
#include                            <map>
#include                            <queue>
#include                            <algorithm>
#include                            <sstream>
#include                            <stack>
#include                            <iomanip>
#include                            <numeric>
#include							<unordered_map>
 
 
using namespace                     std;
#define MOD                         1000000007
//#define int                         int64_t
#define booster                   ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define mpii                        map<int,int>
#define pb                          push_back
#define mk                         make_pair
#define all(x)                      x.begin(),x.end()
#define allr(x)                     x.rbegin(),x.rend()
#define ub(v,x)                     upper_bound(all(v),x)
#define lb(v,x)                     lower_bound(all(v),x)
#define bs(v,x)                     binary_search(all(v),x)
#define gcd(a,b)                    __gcd(a,b)
#define lcm(a,b)                    (((a*b))/__gcd(a,b))
#define vi                          vector<int>
#define pii                         pair<int,int>
#define vpii                        vector<pii>
#define vs                          vector<string>
#define ff                          first
#define ss                          second
#define debug(x)                     cout << x <<"  output   " 
 
 
#define double						long double
/***********************************************************************************************************************/
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
 

int main()
{
    freopen("A1.in","r",stdin);
    freopen("A1.out","w",stdout) ;

	int n ;
    cin >> n ;

    std::vector<pair<int, pair<int,int>>> v;
    std::map<pair<int,int> , int> mmap;
    set<pair<int,int>>myset ;
    pair<int,int>arr ; // pair array neya zabe na 


    for(int i = 0 ; i<n ; i++){
        int x ; cin >> x ;
        v.push_back({i,{x ,i+x}}); // vector push
        mmap[{x,i}]++;			   // map 
        myset.insert({i,x}) ;	   // set insert
        arr = {x , i} ;		   // pair input
    }
    debug("vector ");
    cout << v << endl << endl ; // vector output

    debug("map  ") ;
    cout << mmap << endl << endl ; // map output 

    debug("set  ") ;
    cout << myset << endl << endl ; // set output

    debug("pair  ") ;
    cout << arr << endl << endl ; // pair output



}