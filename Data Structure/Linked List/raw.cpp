#include<bits/stdc++.h>
using namespace std ;


int addSum(int a , int b){
    return a+b ;
}


void prinMyName(){
    cout << "prangan Majumder " << endl ;
}
void ret(int n = 3){
    if(n == 20)return ;
    cout << "n  " << n << endl ;
    ret(n+1) ;
}
void again(int n = 3){
    if(n == 20)return ;
    cout << "n  " << n << endl ;
    again(n+1) ;

}

int main()
{
    cout << "This is a demo raw file for Linked List Push" << endl ;
    int res = addSum(4,5) ;
    cout << "result is    " << res << endl ;

    prinMyName() ;

    ret() ;
    again() ;
}