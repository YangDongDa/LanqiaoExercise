// RSA 是一种经典的加密算法。它的基本加密过程如下。
//       首先生成两个质数 p, q，令 n = p · q，设 d 与 (p − 1) · (q − 1) 互质，则可找到 e 使得 d · e 除 (p − 1) · (q − 1) 的余数为 1。n, d, e 组成了私钥，n, d 组成了公钥。当使用公钥加密一个整数 X 时（小于 n），计算 C = Xd mod n，则 C 是加密后的密文。
// 当收到密文 C 时，可使用私钥解开，计算公式为 X = Ce mod n。例如，当 p = 5, q = 11, d = 3 时，n = 55, e = 27。若加密数字 24，得 243 mod 55 = 19。解密数字 19，得 1927 mod 55 = 24。现在你知道公钥中 n = 1001733993063167141, d = 212353，同时你截获了别人发送的密文 C = 20190324，请问，原文是多少？
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, d, C;
ll quick_pow(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    cin >> n >> d >> C;
    cout << quick_pow(C, d, n) << endl;
    return 0;
}

