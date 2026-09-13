class Solution {
public:
    int flag = 1;

    void dfs(std::vector<std::vector<int>>& graph, std::vector<int>&inwork, int vertex) {
        if (inwork[vertex] == 1) {
            flag = 0;
            return;
        }

        if (inwork[vertex] == 2) {
            return;
        }

        inwork[vertex] = 1;
        for (auto& v : graph[vertex]) {
            dfs(graph, inwork, v);
        }

        inwork[vertex] = 2;
        return;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses);
        for (auto& pair : prerequisites) {
            graph[pair[0]].push_back(pair[1]);
        }
        std::vector<int> inwork(numCourses, 0);
        for (int i = 0; i < numCourses && flag; ++i) {
            dfs(graph, inwork, i);
        }

        return flag;
    }
};
