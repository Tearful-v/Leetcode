class Solution {
public:

    void dfs(std::vector<std::vector<int>>a, std::vector<bool>&v, int start){
        if(v[start])
            return;
        v[start] = 1;
        for(int i = 0; i < a.size(); i++)
            if(a[start][i] == 1 && !v[i])
                dfs(a, v, i);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        std::vector<bool> visited(isConnected.size(), false);
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                dfs(isConnected, visited, i);
                count++;
            }
        }
        return count;
    }
};