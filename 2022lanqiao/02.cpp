#include<iostream>
#include<bits/stdc++.h>
using namespace std;
map<string,bool> m;
bool judge(string s){
    int cnt = 0;
    for (auto i:s){
        if( i == 'O' ) cnt++;
    }
    if(cnt == 1) return true;
    else return false;
}
bool dfs(string s){
    if(m.count(s)) return m[s];
    if(judge(s)) return m[s] = false;
    //模拟一步
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'O'){
            string temp = s;
            temp[i] = 'X';
            if(!dfs(temp)){
                return m[s] = true;
            }
        }
    }
    //模拟两步
    for( int i = 0; i < s.size() - 1;i++){
        if(s[i] == 'O' && s[i + 1] == 'O' && i != 3){
            string temp = s;
            temp[i] = 'X';
            temp[i + 1] = 'X';
            if(!dfs(temp)){
                return m[s] = true;
            }
        }
    }

    //如果都不能赢，那么就是输


    return m[s] = false;


}
int main (int argc, char *argv[])
{
    string s[4] = {"XOOOOOOO","XXOOOOOO","OXOOOOOO","OXXOOOOO"};
    for(int i = 0; i < 4; i++){
        if(dfs(s[i])) cout << "L" << endl;
        else cout << "V" << endl;
    }
    return 0;
}
