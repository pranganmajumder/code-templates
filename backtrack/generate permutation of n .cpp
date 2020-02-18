#include<iostream>
using namespace std ;

int used[20] , number[20] , n  ;

void fun(int pos )
{
    if(pos == n+1 ){
        for(int i = 1 ; i<=n ; i++)cout << number[i] << ' ' ;
        cout << endl ;
    }

    for(int i = 1 ; i<=n ; i++){
        if(used[i] == 0 ){// use kora na hole
            //if(!(pos == 2 && i % 2 == 0)){
                used[i] = 1 ; // use koro ;
                number[pos] = i ;
                fun(pos + 1 ) ;
                used[i] = 0 ;
            //}
        }
    }

// pos 2 te zodi jor number thake tobe print korbe na

}

int main()
{
    cin >> n ;
    fun(1) ;
}
