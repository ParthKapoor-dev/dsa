#include <bits/stdc++.h>

using namespace std;

int n = 0, m = 0, ans = 0;
vector<vector<int>> dp;

int dfs(vector<vector<int>>& grid, int i, int j){

    if(i < 0 || i >= n || j < 0 || j >= m) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int left =  grid[i][j] > grid[i][j-1] ? dfs(grid, i, j-1) : 0;
    int right = grid[i][j] > grid[i][j+1] ? dfs(grid, i, j+1) : 0;
    int top = grid[i][j] > grid[i-1][j] ? dfs(grid, i-1, j): 0;
    int bottom = grid[i][j] > grid[i+1][j] ?  dfs(grid, i+1, j) : 0;

   return dp[i][j] = max({left, right, top, bottom}) + 1;

}

int longestDownhillRide(vector<vector<int>>& grid){

    n = grid.size();
    m = grid[0].size();

    dp.resize(n, vector<int>(m,-1));

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            ans = max(ans, dfs(grid,i,j));
    }

    return ans - 1; // we are calculating edges only
}
