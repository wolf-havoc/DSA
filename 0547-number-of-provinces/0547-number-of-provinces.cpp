class Solution {
public:
    void dfs(int v,vector<vector<int>>& isConnected,vector<int>& visited){
        visited[v] = 1;
        for(int u = 0; u < isConnected.size(); u++){
           if(isConnected[v][u] == 1 && !visited[u]){
                dfs(u, isConnected, visited);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int m  = isConnected.size();
        vector<int> visited(m,0);
        for(int i = 0; i < m; i++){
           if(!visited[i]){
                dfs(i, isConnected, visited);
                count++;
            }      
        }
        return count;

    }
};