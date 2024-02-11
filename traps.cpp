#include <iostream>  
#include <vector>  
  
using namespace std;  
  
// 定义八个方向的偏移量  
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};  
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};  
  
// 函数原型声明  
void dfs(vector<vector<char>>& grid, int x, int y, int M, int N);  
  
int numWaterTraps(vector<vector<char>>& grid) {  
    if (grid.empty() || grid[0].empty()) return 0;  
  
    int M = grid.size();  
    int N = grid[0].size();  
    int waterTraps = 0;  
  
    // 遍历整个土地  
    for (int i = 0; i < M; ++i) {  
        for (int j = 0; j < N; ++j) {  
            // 如果当前位置是水洼，则进行深度优先搜索  
            if (grid[i][j] == 'w') {  
                dfs(grid, i, j, M, N);  
                ++waterTraps; // 发现一个新的水洼  
            }  
        }  
    }  
  
    return waterTraps;  
}  
  
// 深度优先搜索函数  
void dfs(vector<vector<char>>& grid, int x, int y, int M, int N) {  
    // 检查边界和是否访问过  
    if (x < 0 || x >= M || y < 0 || y >= N || grid[x][y] != 'w') {  
        return;  
    }  
  
    // 标记当前位置为已访问  
    grid[x][y] = '.';  
  
    // 对八个方向进行递归搜索  
    for (int i = 0; i < 8; ++i) {  
        int nx = x + dx[i];  
        int ny = y + dy[i];  
        dfs(grid, nx, ny, M, N);  
    }  
}  
  
int main() {  
    int num = 0;
    int width, height;
    cin >> width;
    cin >> height;

    vector<vector<char>>grid;
    vector<char>line;
    for(int i = 0; i < height; i++){
        for(int j = 0; j <= width; j++){
            line.push_back(cin.get());
        }
        grid.push_back(line);
        line.clear();
    }
    
    // 计算水洼数量  
    int numWater = numWaterTraps(grid);  
  
    // 输出结果  
    cout << "Number of water traps: " << numWater << endl;  
  
    return 0;  
}
