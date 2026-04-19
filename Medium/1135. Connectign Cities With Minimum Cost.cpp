#include <iostream>
#include <vector>

class Edges{
    public:
    int u_;
    int v_;
    int w_;
};

int FindSet(int v, std::vector<int> &parent){
    if(v == parent[v])
        return v;
    return parent[v] = FindSet(parent[v], parent);
}

void UnionSet(int a, int b, std::vector<int> &parent, std::vector<int> &rank){
    a = FindSet(a, parent);
    b = FindSet(b, parent);
    if(a != b){
        if( rank[a] < rank[b])
            parent[a] = b;
        else
            parent[b] = a;
        if(rank[a] == rank[b])
            rank[a]++;
    }
}

int main(){
    int n = 0;
    std::cin >> n;
    int m = 0;
    std::cin >> m;
    std::vector<Edges> edges;
    for(int i = 0; i < m; i++){
        int u, v, w;
        std::cin >> u >> v >> w;
        Edges edge = {.u_ = u, .v_ = v, .w_ = w};
        edges.push_back(edge);
    }
    std::sort(edges.begin(), edges.end(), [](const Edges& e1, const Edges& e2) {
        return e1.w_ < e2.w_;
    });
    std::vector<int> parent(n+1);
    for(int i = 1; i <= n; i++)
        parent[i] = i;
    std::vector<int> rank(n+1, 0);
    int mst_cost = 0;
    int edges_in_mst = 0;
    for(auto e : edges){
        if(FindSet(e.u_, parent) != FindSet(e.v_, parent)){
            UnionSet(e.u_, e.v_, parent, rank);
            mst_cost += e.w_;
            edges_in_mst++;
        }
    }
    if(edges_in_mst == n-1)
        std::cout << mst_cost;
    else
        std::cout << -1;
    return 0;
}
//Kruscal
