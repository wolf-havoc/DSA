class Solution {
public:
    void dfs(int v,int u,vector<vector<char>>& grid,vector<vector<int>>& visited){
        visited[v][u] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr = v + dr[i];
            int nc = u + dc[i];

            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && !visited[nr][nc] && grid[nr][nc] == '1'){
                dfs(nr,nc,grid,visited);
            }
            
            
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    dfs(i,j,grid,visited);
                    
                }
            }
        }
        
        return count;
    }
};