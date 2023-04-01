// D.迷宫
// 【问题描述】
//
// 下图给出了一个迷宫的平面图，其中标记为 1 的为障碍，标记为 0 的为可 以通行的地方。
//
// 010000
//
// 000100
//
// 001001
//
// 110000
//
// 迷宫的入口为左上角，出口为右下角，在迷宫中，只能从一个位置走到这 个它的上、下、左、右四个方向之一。 对于上面的迷宫，从入口开始，可以按DRRURRDDDR 的顺序通过迷宫， 一共 10 步。其中 D、U、L、R 分别表示向下、向上、向左、向右走。 对于下面这个更复杂的迷宫（30 行 50 列），请找出一种通过迷宫的方式， 其使用的步数最少，在步数最少的前提下，请找出字典序最小的一个作为答案。 请注意在字典序中D<L<R<U。
//
#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
//地图大小
int h = 30, w = 50;
int mape[30][50];
//方向数组
int dir[5][2] = {{0,0},{1,0},{0,-1},{0,1},{-1,0}};
int dir_inv[5][2] = {{0,0},{-1,0},{0,1},{0,-1},{1,0}};
char dire_w[5] = {' ' ,'D','L','R','U'};
//记录路径
int from[30][50] = {0};
//记录是否访问过
int visited[30][50] = {0};
//状态类
class State{
public:
    int x;
    int y;
    int step;
    string path;
    State(int x, int y , int step, string path){
        this->x = x;
        this->y = y;
        this->step = step;
        this->path = path;
    };
    void set(int x, int y){
        this->x = x;
        this->y = y;
    };
};
//从文件中读取地图
void input(){
    freopen("map.txt","r",stdin); 
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char c = ' ';
            while(c != '0'&& c != '1'){
                cin >> c;
            }
            mape[i][j] = (int)(c - '0');
            
        }
    }
    fclose(stdin);
}
//输出地图
void output(int mape[30][50]){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << mape[i][j];
        }
        cout << endl;
    }
}
//深度优先搜索
void bfs(){
    queue<State> q; 
    from[0][0] = -1;
    visited[0][0] = 1;
    q.push(State(0,0,0,""));
    while(!q.empty()){
        State s = q.front();
        q.pop();
        for(int i = 1; i <= 4; i++ ){
            int x = s.x + dir[i][0];
            int y = s.y + dir[i][1];
            if(x < 0 || x >= h || y < 0 || y >= w || mape[x][y] == 1 || visited[x][y] == 1){
                continue;
            }
            visited[x][y] = 1;
            from[x][y] = i;
            q.push(State(x,y,s.step+1,s.path + dire_w[i]));
            if(visited[h-1][w-1] == 1){
                break;
            }
        }
        
    }

    // cout << "step : " << q.back().step << endl;
    // cout << "path : " << q.back().path << endl;
    
}

//输出路径
void output_path(){
    vector<char> path;
    int x = h - 1, y = w - 1;
    while ( from[x][y] != -1){
        int d = from[x][y];
        path.push_back(dire_w[d]);
        x = x + dir_inv[d][0];
        y = y + dir_inv[d][1];
        
        
    }
    // cout << path.size() << endl;
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i];
    }
    cout << endl;
    // freopen("path.txt","w",stdout);
    // for(int i = path.size() - 1; i >= 0; i--){
    //     cout << path[i];
    // }
    // fclose(stdout);
    // cout << endl;
}

int main (int argc, char *argv[])

{
    input();
    bfs();
    output_path();

    return 0;
}
