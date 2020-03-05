#include<iostream>
typedef long long int LL ;
#define    NMAX     11 

using namespace std ;

int arr[NMAX]  , n , used[NMAX] ;
LL ans ;


void backTrack(int pos , LL profit)
{
    if(pos == n){
        ans = max(ans , profit) ;
        return ; 
    }
    
    LL p = 0 ;
    for(int i = 0 ; i<n ; i++){
        if(used[i] == 0){
            used[i] = 1 ;
            LL L = 0 , R = 0 , mul = 1 ;  
            for(int j = i+1 ; j<n ;j++){ // go to Right 
                if(used[j] == 0){
                    R = 1 ; mul*=arr[j] ; break ;
                }
            } 
            for(int j = i-1 ; j>= 0 ; j--){// go to Left 
                if(used[j] == 0){
                    L = 1 ; mul*=arr[j] ; break ;
                }
            }
            if(L == 0 && R == 0)p = arr[i] ;
            else p = mul ;
            backTrack(pos+1 , profit + p) ;
            used[i] = 0 ;                     
        }
    }
}

int main()
{
    cin >> n ; 
    for(int i = 0 ; i<n ; i++)cin >> arr[i] ;
    backTrack(0 , 0 ) ;
    cout << ans << endl ;
}

