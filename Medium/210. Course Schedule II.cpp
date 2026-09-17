class Solution {
public:

    int flag = 1;

    void dfs(std::vector<int> &res, const std::vector<std::vector<int>> &graph,
        std::vector<int> &process, int vertex) {

        if (process[vertex] == 2) {
            return;
        }
        if (process[vertex] == 1) {
            flag = 0;
            return;
        }

        process[vertex] = 1;
        for(int v : graph[vertex]) {
            dfs(res, graph, process, v);
        }

        process[vertex] = 2;
        res.push_back(vertex);
        return;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses);
        for (size_t i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        std::vector<int> res;
        std::vector<int> process(numCourses, 0);
        for (size_t vertex = 0; vertex < graph.size(); ++vertex) {
            dfs(res, graph, process, vertex);
        }
        if (!flag) {
            return {};
        }
        return res;
    }
};
