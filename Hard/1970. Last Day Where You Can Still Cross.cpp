class Solution {

    class DSU{
        public:

        std::vector<int>parent;
        DSU(int n){
            parent.resize(n);
            for(int i = 0; i < n; i++)
                parent [i] = i;
        }

        int find(int x){
            if(parent[x] == x)
                return x;
            return find(parent[x]);
        }

        void unite(int x, int y){
            int a = find(x);
            int b = find(y);
            if(a == b)
                return;
            else
                parent[b] = a;
            return;
        }
    };

public:

    int getid(int row, int col, int c){
        return (row * c + col + 1);
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int top = 0;
        int bottom = row * col + 1;
        DSU dsu(row * col + 2);
        std::vector<std::vector<int>>grid(row, std::vector<int>(col, 1));
        for(int i = cells.size()-1; i >= 0; i--){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 0;
            int id = getid(r, c, col);
            for(int k = 0; k < 4; k++){
                int nr = r + dirs[k][0];
                int nc = c + dirs[k][1];
                if(nr >=0 && nr < row && nc >=0 && nc < col && grid[nr][nc] == 0){
                    int neighbour_id = getid(nr, nc, col);
                    dsu.unite(id, neighbour_id);
                }
            }
            if(r == 0) dsu.unite(top, id);
            if(r == row-1) dsu.unite(bottom, id);
            if(dsu.find(top) == dsu.find(bottom))
            return i;
        }
        return 0;
    }
};