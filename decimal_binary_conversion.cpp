#include<bits/stdc++.h>
using namespace std;
#define ll long long
string toString(ll n)
{
    stringstream ss;
    ss<<n;
    string ret=ss.str();
    return ret;
}

string decToBinary(ll n)//geeksforgeeks
{   if(n==0)return "0";
    string num="";
    ll i = 0;
    while (n > 0) {
        ll v = n % 2;
        num=num+toString(v);
        n = n / 2;
        i++;
    }
    reverse(num.begin(),num.end());
    return num;//note return type is in string cz jodi n onek boro hoy tokhon setar binary value onek boro hobe , normal approach a hobe na
}



ll binaryToDecimal(string n)//parameter is in string
{
    string num = n;
    ll dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    ll base = 1;

    ll len = num.length();
    for (int i=len-1;i>=0;i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}
int main()
{
                    /**decimal to binary**/
    ll n;
    printf("enter your decimal number : ");//32422423434535353535
    cin>>n;
    cout<<"in binary format = "<<decToBinary(n)<<endl;




                /**binary to decimal**/
    printf("enter your binary number in string format = ");//11110000011110000111110000
    string st;
    cin>>st;
    cout<<"binary to decimal is ===  "<<binaryToDecimal(st)<<endl;
}
