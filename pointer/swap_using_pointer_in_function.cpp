#include<iostream>
using namespace std;


void fun(int* address_A, int* address_B){
    // cout << "\n before " << endl ;
    // cout << address_A << ' ' << address_B << endl ;
    // cout << *address_A << ' ' << *address_B << endl ;

    int temp = *address_A ;                     // temp = value of address_A
    *address_A = *address_B ;                   // value of address_A = value of address_B
    *address_B = temp ;                         // value of address_B = value of temp

    // cout << "\n after " << endl ;
    // cout << address_A << ' ' << address_B << endl ;
    // cout << *address_A << ' ' << *address_B << endl << endl  ;
}

int main()
{
    int a , b ;
    cin >> a >> b;
    fun(&a,&b) ;
    // cout << &a << ' ' << & b << endl ;
    // cout << "a =  " << a << endl ;
    // cout << "b =  " << b << endl ;
}