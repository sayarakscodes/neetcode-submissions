class Solution {
public:
    bool detectCycle(int z, vector<vector<int>> & adj, vector<int>&vis) {
        vis[z] = 1;
        bool hasCycle = false;
        for(int x: adj[z]) {
            if(vis[x] == 1) return true;
            hasCycle |= detectCycle(x, adj, vis);
        }
        vis[z] = 2;
        return hasCycle;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto v : prerequisites) {
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(numCourses, 0);
        for(int i = 0; i < numCourses; i ++) {
            if (vis[i] == 0) {
                if (detectCycle(i, adj, vis)) {
                    return false;
                }
            }
        }
        return true;
    }
};
