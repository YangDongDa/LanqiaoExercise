#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main (int argc, char *argv[])
{
    freopen("ccc.txt", "r", stdin); 
    char c = ' ';
    int count = 0;
    while (cin >> c) {
        if(c == 'U' || c == 'D' || c == 'L' || c == 'R') {
           count += 1; 
            cout << c << endl;
        }
        
    
    }
    fclose(stdin);
    cout << count << endl;
    return 0;
}
