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

string complement(string n)
{
    ll len=n.size();
    string temp="";
    for(ll i=0;i<len;i++){
        if(n[i]=='0')temp+='1';
        else if(n[i]=='1')temp+='0';
    }
    return temp;
}

int main()
{
    printf("enter your number ");
    ll n;
    scanf("%lld",&n);

    printf("binary format of n is ");
    string s=decToBinary(n);
    cout<<s<<endl<<endl;


    printf("complement binary format of n is ");
    string temp=complement(s);
    cout<<temp<<endl<<endl;

    printf("complement decimal format of n is ");
    cout<<binaryToDecimal(temp)<<endl;
}
