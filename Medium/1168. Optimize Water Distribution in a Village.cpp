#include <vector>

using PII = std::pair<int, int>; // пари виду <будинок, кошта до нього>

class Solution {
public:
    int minCostToSupplyWater(int n, std::vector<int>& wells, std::vector<std::vector<int>>& pipes) {
        std::vector<std::vector<PII>>graph(wells.size() + 1); // будiвля графу
        for (int i = 1; i <= wells.size(); ++i) {
            graph[0].push_back({i, wells[i - 1]});
            graph[i].push_back({0, wells[i - 1]});
        }

        for (auto& pipe : pipes) {
            int from = pipe[0];
            int to = pipe[1];
            int cost = pipe[2];
            graph[from].push_back({to, cost});
            graph[to].push_back({from, cost});
        }

        std::priority_queue <PII, std::vector<PII>, std::greater<PII>> heap; // важливо робити <вартiсть вершина>
        std::vector<bool> visited(wells.size() + 1, false);
        int total_cost = 0;

        heap.push({0, 0});
        while (!heap.empty()) {
            auto x = heap.top();
            heap.pop();
            if (visited[x.second]) {
                continue;
            }
            visited[x.second] = true;
            total_cost += x.first;
            for (auto &[next, cost] : graph[x.second]) {
                if (!visited[next]) {
                    heap.push({cost, next});
                }
            }
        }

        return total_cost;
    }
};
