class DSU {
private:
    vector<int> siz;
    vector<int> parent;
public:
    DSU(int n) {
        siz.resize(n, 1);
        parent.resize(n);
        for(int i = 0 ; i < n; i ++) {
            parent[i] = i;
        }
    }

    int getParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = getParent(parent[x]);
    }

    void merge(int x, int y) {
        int par_x = getParent(x);
        int par_y = getParent(y);

        if(siz[par_x] < siz[par_y]) {
            parent[par_x] = par_y;
            siz[par_y] += siz[par_x];
        } else{
            parent[par_y] = par_x;
            siz[par_x] += siz[par_y];
        }
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<pair<int, pair<int, int>>> adj;
        int n = points.size();
        for(int i = 0; i < points.size(); i ++ ) {
            for(int j = i + 1; j < points.size(); j ++) {
                int xx = points[i][0];
                int xy = points[i][1];
                int yx = points[j][0];
                int yy = points[j][1];
                int dist = abs(xx - yx) + abs(xy - yy);
                adj.push_back({dist, {i, j}});
            }
        }

        sort(adj.begin(), adj.end());

        DSU* dsu = new DSU(n);
        int ans = 0;

        for(auto p : adj) {
            int weight = p.first;
            int x = p.second.first;
            int y = p.second.second;
            if(dsu->getParent(x) != dsu->getParent(y)) {
                dsu->merge(x, y);
                ans += weight;
            }

        }
        return ans;
    }

};
