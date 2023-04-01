// 给定数列1,1,1,3,5,9,17,⋯，从第4项开始，每项都是前3项的和。求
// 第20190324项的最后4位数字。
#include <iostream>
#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;
int main (int argc, char *argv[])
{
    // queue<long> q;
    // q.push(1);
    // q.push(1);
    // q.push(1);
    // long sum = 3;
    // int mid = 1;
    // for (int i = 4; i <= 20190324; i++) {
    //     q.pop();
    //     q.push(sum);
    //     sum = (q.back() + q.front() + mid) % 10000;
    //     mid = q.back();
    //     // q.pop();
    // }
    // // cout << sum<< endl;
    // cout << q.back() << endl;
    // // cout << sum % 10000 << endl;
    int a = 1, b = 1, c = 1 ;
    for (int i = 4; i <= 20190324; i++) {
        int d = (a + b + c) % 10000;
        a = b;
        b = c;
        c = d;
    }
    cout<< c <<endl;
        

    return 0;
}
