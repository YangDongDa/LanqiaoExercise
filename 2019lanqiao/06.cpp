// “饱了么”外卖系统中维护着 N 家外卖店，编号 1 ∼ N。每家外卖店都有一个优先级，初始时 (0 时刻) 优先级都为 0。
// 每经过 1 个时间单位，如果外卖店没有订单，则优先级会减少 1，最低减到 0；
// 而如果外卖店有订单，则优先级不减反加，每有一单优先级加 2。
// 如果某家外卖店某时刻优先级大于 5，则会被系统加入优先缓存中；如果优先级小于等于 3，则会被清除出优先缓存。
// 给定 T 时刻以内的 M 条订单信息，请你计算 T 时刻时有多少外卖店在优先缓存中。
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main (int argc, char *argv[])
{
    int n, m ,t;
    cin >> n >> m >> t;
    int order[t + 1][n + 1];
    memset(order, 0, sizeof(order));
    int left[n + 1];
    memset(left, 0, sizeof(left));
    for(int i = 1; i <= m ; i++){
        int a, b;
        cin >> a >> b;
        order[a][b] = 1 + order[a][b];
    }
    int priority[n + 1];
    memset(priority,0,sizeof(priority));
    for (int i = 1; i <= t; i++) {
        for (int j = 1;  j <= n; j++) {
            if (priority[j] > 0) {
                if (order[i][j] == 0) {
                    priority[j] -= 1;
                    if (priority[j] <= 3 && left[j] == 1) {
                        left[j] = 0;
                    }
                } else {
                    priority[j] += 2 * order[i][j];
                    if(priority[j] > 5 && left[j] == 0){
                        left[j] = 1;
                    }
                }

            }else{
                if (order[i][j] == 0) {
                    priority[j] = 0;
                } else {
                    priority[j] += 2 * order[i][j];
                    if (priority[j] > 5) {
                        left[j] = 1;
                    }
                }
            }

        }

    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (left[i] == 1) {
            count++;
        }
    }
    cout <<count << endl;
    // for(int i = 1; i <= n; i++){
    //     cout << i << " :";
    //     for(int j = 1; j <= t; j++ ){
    //         cout << order[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    
    return 0;
}
