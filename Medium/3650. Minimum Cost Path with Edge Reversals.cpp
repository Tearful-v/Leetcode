class Solution {
public:

    using PII = std::pair<int, int>;

    int minCost(int n, vector<vector<int>>& edges){
        std::vector<std::vector<PII>>g(n);
        for(int i = 0; i < edges.size(); i++){
            int x = edges[i][0], y = edges[i][1], z = edges[i][2];
            g[x].push_back({y, z});
            g[y].push_back({x, 2*z});
        }
        std::vector<bool>visited(n, false);
        std::vector<int>sum(n, INT_MAX);
        priority_queue<PII, std::vector<PII>, greater<PII>>q;
        sum[0] = 0;
        q.emplace(0, 0);
        while(!q.empty()){
            int x = q.top().second;
            if(x == n-1)
                return sum[x];
            q.pop();
            if(visited[x])
                continue;
            visited[x] = true;
            for(auto& [y, z] : g[x]){
                int traversesum = sum[x] + z;
                if(sum[y] > traversesum){
                    sum[y] = traversesum;
                    q.emplace(sum[y], y);
                }
            }
        }
        return -1;
    }
};