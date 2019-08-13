#include <iostream>
    #include<bits/stdc++.h>
    #define ll long long int
    #define pf printf
    using namespace std;

    void pri(const vector<int>&v)
{   cout<<"vector printing "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
}



    int prime[100000000/32];
    int nPrime;
    vector<int>vec;
    bool BitCheck(int n, int position)
    {
        return n & (1<<position);
    }

    int BitSet(int n, int position)
    {
        n = n | (1<<position);
        return n;
    }


    void sieve(int n)
    {
        int sqrtN;
        sqrtN = sqrt(n);

        prime[0] = BitSet( prime[0], 0 );
        prime[0] = BitSet( prime[0], 1 );

        for( int i = 4; i <= n; i += 2 ) prime[i>>5] = BitSet(prime[ i>>5 ], i&31 );

        for(int i=3; i <= sqrtN; i+=2 ){ if( BitCheck(prime[i>>5],i&31)==0){
            for(int j=i*i; j<=n; j += (i<<1) ){ prime[j>>5]=BitSet(prime[j>>5],j & 31);
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(BitCheck(prime[i>>5],i&31)==0){
                vec.push_back(i);
            }
        }
        nPrime=vec.size();
    }

    int main()
    {
        ll n;
        //cin>>n;
        clock_t startTime = clock() ;
        sieve(1e8);
        printf("total Prime = %lld\n",nPrime);

        pri(vec);

//    ll number;
//    cin>>number;
//    if(mark[number]==0)printf("prime\n");

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
}

