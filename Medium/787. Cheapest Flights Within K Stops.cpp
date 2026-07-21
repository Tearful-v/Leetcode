class Solution {
public:
    #define INF 1000000000

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> distance(n, INF);
        distance[src] = 0;
        for (int i = 0; i < k + 1; ++i) { //ограничение k пересадок -> k+1 полетов
            std::vector next = distance;

                for (int j = 0; j < flights.size(); ++j) {

                    int from = flights[j][0];
                    int to = flights[j][1];
                    int cost = flights[j][2];

                    if (distance[from] != INF) {
                        next[to] = std::min(next[to], distance[from] + cost);
                    }
                }

            distance = std::move(next);
        }
        return distance[dst] == INF ? -1 : distance[dst];
    }
};
