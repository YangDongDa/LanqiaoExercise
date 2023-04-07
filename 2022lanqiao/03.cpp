#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long a[200001];
int main (int argc, char *argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        int temp = 0;
        for(int j = i + 1; j <= n; j++){
            temp = a[j] + temp;
        }
        sum = sum + a[i] * temp;
    }
    cout << sum <<endl;
    return 0;
}
