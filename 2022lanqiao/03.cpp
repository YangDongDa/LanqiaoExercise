#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long a[200001];
long long SUM;
int main (int argc, char *argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        SUM = SUM + a[i];
    }
    long long sum = 0;
    long long temp = 0;
    for(int i = 1; i <= n; i++){
        temp = temp + a[i];
        sum = sum + a[i] * (SUM - temp);
       
    }
    cout << sum <<endl;
    return 0;
}
