class Solution {
public:

    int dijkstra(vector<vector<pair<int, int>>>& adj, int src, int dst, int k, int n) {

        multiset<pair<int, pair<int, int>>> st;
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        st.insert({0, {src, 0}});
        while(!st.empty()) {
            pair<int, pair<int, int>> p = *st.begin();
            st.erase(st.begin());
            int w = p.first;
            int node = p.second.first;
            int stops = p.second.second;
            
            for(pair<int, int> xx : adj[node]) {
                int next = xx.first;
                int weight = xx.second;
                if(stops + 1 <= k + 1 && dist[next][stops + 1] > dist[node][stops] + weight ) {
                    dist[next][stops + 1] = dist[node][stops] + weight;
                    st.insert({weight, {next, stops + 1}});
                }
            }
        }
        int res = INT_MAX;
        for(int stops = 0; stops <= k + 1; stops ++) {
            res = min(res, dist[dst][stops]);
        }
        if (res >= INT_MAX) {
            return -1;
        }
        return res;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto v : flights) {
            int x = v[0];
            int y = v[1];
            int w = v[2];
            adj[x].push_back({y, w});
        }
        return dijkstra(adj, src, dst, k, n);
    }
};
