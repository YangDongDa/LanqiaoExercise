// 给定一棵包含 N 个节点的完全二叉树，树上每个节点都有一个权值，按从上到下、从左到右的顺序依次是 A1, A2, · · · AN
// 现在小明要把相同深度的节点的权值加在一起，他想知道哪个深度的节点权值之和最大？
// 如果有多个深度的权值和同为最大，请你输出其中最小的深度。
// 注：根的深度是 1。
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main (int argc, char *argv[])
{
    
    int n;
    cin >> n;
    int a[n+1];
    int sum[1000] = {0};
    int depth = 1;
    int max = 0;
    int max_index = 1;
    //max = a[1];
    int i = 1;
    while( i <= n ){
        cin >> a[i];
        sum[depth] += a[i];
        i++;
        if(i == pow(2 , depth)){
            depth++;
        }


    }
    /*
     for (int i = 1; i <= n; i++) {
         cin >> a[i];
         int temp = log2(i) + 1;
         sum[temp] += a[i];
         
     }*/
     int temp = log2(n) + 1;
     max = sum[1];
    for (int i = 1 ; i <= temp;i++){
        if(sum[i] > max) {
          max = sum[i];
          max_index = i;
        }
     }
    cout << max_index << endl;
    return 0;
}

