// 给定一个长度为入的数组A=[A1.A2,…•Av]，数组中有可能有重复出现
// 的整数。
// 现在小明要按以下方法将其修改为没有重复整数的数组。小明会依次修改A2,Ag,...,Av。
// 当修改A;时，小明会检查A，是否在A~A;-1中出现过。
// 如果出现过，则 小明会给A;加上1
// 如果新的A，仍在之前出现过，小明会持续给A，加1，直到4，没有在A～A-1中出现过。
// 当Av也经过上述修改之后，显然A数组中就没有重复的整数了。
// 现在给定初始的A数组，请你计算出最终的A数组。
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main (int argc, char *argv[])
{
   int N = 0;
    cin >> N;
    // int A[N];
    set<int> A;
    for (int i = 0; i < N; i++)
    {
        int temp = 0;
        cin >> temp;
        while (A.find(temp) != A.end())
        {
            temp++;
        }
        A.insert(temp);
        cout << temp << " ";
    }


    return 0;
}
