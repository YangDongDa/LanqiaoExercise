#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Num[10000001];
int main (int argc, char *argv[])
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp = 0;
        cin>>temp;
        while (Num[temp] != 0)
        {
          Num[temp] ++;
            temp = temp + Num[temp] - 1;
        }
        Num[temp] = 1;
        cout<<temp<< " ";

    }
    cout<<endl;
}
