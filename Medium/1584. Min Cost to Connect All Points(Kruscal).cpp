/*воспользуюсь алгоритмом краскаля для построения минимального остовго дерева, для этого:
        1) реализую union-find структуру
        2) строю граф и сортирую по ребрам
        3) начинаю жадно строить остовое дерево */

class Solution {
public:

    struct UnionFind {
        UnionFind(int n) {
            components.resize(n);
            for (int i = 0; i < n; ++i) {
                components[i] = i;
            }
            size.resize(n);
            for (int i = 0; i < n; ++i) {
                size[i] = 1;
            }
        }

        int Find(int x) { //пользуюсь сжатием путей
            if (x == components[x]) {
                return x;
            }
            return components[x] = Find(components[x]); // так как = это операция, а не инструкция можно сделать так
        }

        bool IsSame(int a, int b) {
            return Find(a) == Find(b);
        }

        void Unite(int a, int b) {
            a = Find(a);
            b = Find(b); //ищем представителей
            if (size[a] > size[b]) {
                std::swap(a, b);
            }
            size[b] += size[a];
            components[a] = b;
        }

        std::vector<int> components;
        std::vector<int> size;
    };

    struct Edge {
        int weight;
        int from;
        int to;
    };

    int ManhattanDistance(int x1, int y1, int x2, int y2) {
        return (abs(x1-x2) + abs(y1-y2));
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        std::vector<Edge> edges;
        edges.reserve(n * (n-1)/2);
        for (int from = 0; from < n; ++from) {
            for (int to = from + 1; to < n; ++to) {
                int distance = ManhattanDistance(
                    points[from][0],
                    points[from][1],
                    points[to][0],
                    points[to][1]
                );
                edges.push_back({distance, from, to});
            }
        }

        std::sort(edges.begin(), edges.end(), [](Edge& first, Edge& second) {
            return first.weight < second.weight;
        });

        int cost = 0;
        int used = 0;
        UnionFind uni(n);
        for (const Edge& e : edges) {
            if (!uni.IsSame(e.from, e.to)) {
                cost += e.weight;
                uni.Unite(e.from, e.to);
                ++used;
                if (used == n - 1) {
                    break;
                }
            }
        }

        return cost;
    }
};
