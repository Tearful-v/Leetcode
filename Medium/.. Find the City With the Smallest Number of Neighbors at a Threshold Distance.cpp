class Solution {
public:

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {//для нахождения всех расстояний
        std::vector<std::vector<int>> graph(n, std::vector<int>(n, INT_MAX/2)); //юзаю Флойда Уоршела

        for (int i = 0; i < n; ++i) { // из самого себя 0
            graph[i][i] = 0;
        }

        for (auto edge : edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2]; // дороги двусторонние
        }

        for (int k = 0; k < n; ++k) {
            for (int a = 0; a < n; ++a) {
                for (int b = 0; b < n; ++b) {
                    graph[a][b] = std::min(graph[a][b], graph[a][k] + graph[k][b]);
                }
            }
        } //Заполнили матрицу, теперь кратчайшие расстояния уже в ней, осталось обработать и дать ответ

        int answer = -1;
        int min = INT_MAX; //просто за квадрат проходимся по матрице
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (graph[i][j] <= distanceThreshold) {
                    count += (i == j) ? 0 : 1;
                }
            }
            if (count <= min) {
                min = count;
                answer = i;
            }
        }

        return answer;
    }
};
