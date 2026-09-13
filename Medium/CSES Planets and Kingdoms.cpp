#include <vector>
#include <iostream>

void dfs(std::vector<int> &order, std::vector<bool> &visited,
        std::vector<std::vector<int>> &graph, int vertex) {
    if (visited[vertex]) {
        return;
    }

    visited[vertex] = true;

    for (auto v : graph[vertex]) {
        dfs(order, visited, graph, v);
    }
    order.push_back(vertex);

    return;
}

void find_components(std::vector<bool> &visited, std::vector<std::vector<int>> &graph,
                    std::vector<int> &components, int vertex, int component) {
    if (visited[vertex]) {
        return;
    }

    visited[vertex] = true;
    components[vertex] = component;

    for (auto v : graph[vertex]) {
        find_components(visited, graph, components, v, component);
    }

    return;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::vector<std::vector<int>> straight(a);
    std::vector<std::vector<int>> reversed(a);

    for (int i = 0; i < b; ++i) {
        int from;
        int to;
        std::cin >> from >> to;

        straight[from - 1].push_back(to - 1);
        reversed[to - 1].push_back(from - 1);
    }

    std::vector<int> order;
    std::vector<bool> visited_st(a, false);
    for (int i = 0; i < a; ++i) {
        dfs(order, visited_st, straight, i);
    }

    std::vector<bool> visited_rv(a, false);
    std::vector<int> component(a, 0);
    int cur_component = 1;
    for (int i = component.size() - 1; i >= 0; --i) {
        if(!visited_rv[order[i]]) {
            find_components (visited_rv, reversed, component, order[i], cur_component);
            ++cur_component;
        }
    }

    std::cout << cur_component - 1 << '\n';
    for (int i = 0; i < a; ++i) {
        std::cout << component[i] << ' ';
    }

    return 0;
}

//problem from https://cses.fi/problemset/task/1683
