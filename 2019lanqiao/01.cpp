// 小明对数位中含有2、0、1、9的数字很感兴趣，在1到40中这样的数包
// 括12、9、10至32、39和40，共28个，他们的和是574，平方和是14362。
// 注意，平方和是指将每个数分别平方后求和。
// 请问，在1到2019中，所有这样的数的平方和是多少？
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int isContain(int i){
    while (i > 0){
        if(i % 10 == 2 || i % 10 == 0 || i % 10 == 1 || i % 10 ==9){
            return 1;
        }
        i = i / 10;
    }
    return 0;
}
int main (int argc, char *argv[])
{
    //记录平方和
    long sum = 0;
    
    for(int i = 1; i <= 2019; i++){
        if (isContain(i)) {
            sum += i * i;
        
        }
        

    }
    cout << sum << endl;
    return 0;
}
