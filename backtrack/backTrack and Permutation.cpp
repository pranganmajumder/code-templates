#include<iostream>
using namespace std ;

int arr[100] , n ;

bool Check(int N , int pos)
{
    return (bool)(N & (1<<pos)) ;
}

void fun()
{
    int cnt = (1<<n) ;
    for(int i = 0 ; i<cnt ; i++){
        for(int pos = 0 ; pos<n ; pos++){
            if(Check(i , pos))cout << arr[pos] <<' ' ;
        }
        cout << endl ;
    }
}


int used[100] , number[100] ;

void backTrack(int pos)
{
    if(pos == n){
        for(int i = 0 ; i<n ; i++)
            cout << number[i] << ' ' ;
        cout << endl ;
    }

    for(int i = 0 ; i<n ; i++){
        if(used[i] == 0){
            used[i] = 1 ;
            number[pos] = arr[i] ;
            backTrack(pos+1) ;
            used[i] = 0 ;
        }
    }
}

int main()
{
    cin >> n ;
    for(int i = 0 ; i<n ; i++)cin >> arr[i] ;

    cout << "all  possible subset generate   " << endl ;
    fun() ;
    cout << endl << endl << " all possible permutation using  backtrack   " << endl ;
    backTrack(0) ;
}