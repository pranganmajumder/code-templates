#include<iostream>
typedef long long int LL ;
#define    NMAX     11 

using namespace std ;

int arr[NMAX]  , n ;
LL dp[1<<NMAX];

void initDp() ;


bool Check(int N , int pos)
{
    return (bool) (N&(1<<pos)) ;
}

int Set(int N , int pos)
{
    return N = N | (1<<pos) ;
}

LL fun(int mask)
{
    if(mask == (1<<n) -1 )return 0 ;
    if(dp[mask] != -1)return dp[mask] ;

    LL p = 0 , ans = 0  ;
    for(int i = 0 ; i<n ; i++){
        if(Check(mask , i) == 0){
            LL L = 0 , R = 0 , mul = 1 ;
            for(int j = i+1 ; j<n ; j++){// go to right 
                if(Check(mask , j) == 0){
                   R = 1 ;  mul*=arr[j] ; break ;
                }
            }
            for(int j = i-1 ; j>=0 ; j--){// go to left 
                if(Check(mask , j) == 0){
                   L = 1 ; mul*=arr[j] ; break ;
                }
            }
            if(L == 0 && R == 0)p=arr[i] ; // Left , Right a jodi kono baloon na thake 
            else p=mul ;
            ans = max(ans , p+fun(Set(mask , i))) ;
        }
    }
    return dp[mask] = ans ;
}

int main()
{
    initDp() ;
    cin >> n ; 
    for(int i = 0 ; i<n ; i++)cin >> arr[i] ;
    cout << fun(0) << endl ;
}

void initDp()
{
    for(int i = 0 ; i<(1<<NMAX) ; i++)dp[i] = -1 ;
}