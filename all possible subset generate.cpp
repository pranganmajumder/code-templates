 #include<bits/stdc++.h>
typedef long long int LL;
#define ll          LL
#define pLL        pair<LL,LL>
#define pb         push_back
#define sc          scanf
#define pf          printf
using namespace std;


inline bool Check(int n,int pos) { return (bool)(n & (1LL << pos)); }

int n,a[100];

void pri()
{   int cnt = (1<<n);

    for(int i=1; i<cnt;  i++){// i = 0 theke start korleo same hobe . in here 0 has no significance , cz 0 te kono ON bit nai, 000
        for(int pos = 0; pos<n ; pos++){
            if(Check(i,pos)){
                cout<<a[pos]<<' ';
            }
        }
        cout<<endl;
    }
}

int main()
{

    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    pri();

}
