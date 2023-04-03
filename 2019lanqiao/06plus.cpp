// “饱了么”外卖系统中维护着 N 家外卖店，编号 1 ∼ N。每家外卖店都有一个优先级，初始时 (0 时刻) 优先级都为 0。
// 每经过 1 个时间单位，如果外卖店没有订单，则优先级会减少 1，最低减到 0；
// 而如果外卖店有订单，则优先级不减反加，每有一单优先级加 2。
// 如果某家外卖店某时刻优先级大于 5，则会被系统加入优先缓存中；如果优先级小于等于 3，则会被清除出优先缓存。
// 给定 T 时刻以内的 M 条订单信息，请你计算 T 时刻时有多少外卖店在优先缓存中。
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main (int argc, char *argv[])
{
    int n, m ,t;
    int last_time = 0;
    int priority = 0;
    int count = 0;
    cin >> n >> m >> t;
    // int order[t + 1][n + 1];
    // memset(order, 0, sizeof(order));
    vector<int> order[n + 1];
    for (int i = 1; i <= m; i++ ){
        int a,b;
        cin >> a >> b;
        order[b].push_back(a);
    }

    for(int i = 1 ; i <= n; i++){
        sort(order[i].begin(), order[i].end());
        int left = 0;
        last_time = 0;
        priority = 0;
        for (int j = 0; j < order[i].size(); j++) {
            int ts = order[i][j];
            if(ts - last_time > 1){
                priority -= (ts - last_time - 1);
                if(priority < 0){
                    priority = 0;
                }
                if(priority <= 3 && left == 1){
                    left = 0;
                }
            }
            priority += 2;
            if(priority > 5 && left == 0){
                left = 1;
            }
            last_time = ts;
            cout << priority << " ";

        }
        if(t > last_time){
            priority -= (t - last_time);
            if(priority < 0){
                priority = 0;
            }
            if(priority <= 3 && left == 1){
                left = 0;
            }

        }
        // cout << priority << endl;
        if(left == 1){
            count++;
        }

    }
    // cout << count << endl;
    //     for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < order[i].size(); j++) {
    //         cout << order[i][j] << " ";
    //     }
        cout << endl;
    // }


    return 0;
}
