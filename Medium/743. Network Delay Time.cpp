class Solution {
public:
    #define INF 1000000000
    using PII = std::pair<int, int>; // воспользуюсь дейкстрой

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<std::vector<PII>> graph(n+1);
        for (int i = 0; i < times.size(); ++i) {
            int from = times[i][0];
            int to = times[i][1];
            int cost = times[i][2];

            graph[from].push_back({to, cost});
        }

        std::vector<int> distance(n+1, INF); // заполнение начального стостояния
        distance[k] = 0;
        std::priority_queue <PII, std::vector<PII>> heap;

        heap.push({0, k});
        while (!heap.empty()) {
            auto edge = heap.top();
            heap.pop();
            if(edge.first != -distance[edge.second]) {
                continue;
            }

            for (auto e : graph[edge.second]) {
                if (distance[e.first] > distance[edge.second] + e.second) {
                    distance[e.first] = distance[edge.second] + e.second;
                    heap.push({-(distance[edge.second] + e.second), e.first});
                }
            }
        }

        distance[0] = -INF; //костылек)
        int answer = *(std::max_element(distance.begin(), distance.end()));
        return (answer == INF) ? -1 : answer;
    }
};
