#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int N,M,K;
int S[1 << 20],B[105];
int main (int argc, char *argv[])
{
   cin>>N>>M>>K; 
    for(int i = 1;i <= N;i++){
        for(int j = 0; j < K; j++){
            int temp;
            cin >> temp;
            B[i] = B[i] | (1 <<(temp - 1));

        }
        // cout << B[i] << " ";
    }
    // cout << endl;
    memset(S,127,sizeof(S));
    S[0] = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < (1 << M); j++){
            S[j | B[i + 1]] = min(S[j] + 1,S[j | B[i + 1]]);
        }
    }
    if(S[(1 << M) - 1] == 127) cout << -1 << endl;
    else cout << S[(1 << M) - 1] << endl;
    return 0;
}
