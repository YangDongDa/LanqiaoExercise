#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void initSet(int *fa,int n){
    for (int i = 0; i < n; i++) {
        fa[i] = i;
        
    }
}
int findSet(int *fa,int n){
    if(fa[n] == n) return n;
    else return fa[n] = findSet(fa,fa[n]);
}
void unionSet(int *fa,int a,int b){
    fa[findSet(fa,a)] = findSet(fa,b);
}
int main (int argc, char *argv[])
{
    int n;
    cin >> n;
    int fa [1000001];
    initSet(fa,1000001);
    for(int i = 0; i < n; i++){
        int a;
        int temp;
        cin >> a;
        temp = findSet(fa,a);
        cout << temp << " ";
        if(temp != 1000001) unionSet(fa,temp,temp + 1);
    }
    return 0;
}
