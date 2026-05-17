class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto v: trips) {
            int pass = v[0];
            int from = v[1];
            int to = v[2];

            pq.push({v[1], v[0]});
            pq.push({v[2], -1 * v[0]});

        }

        int curr = 0;

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            curr += p.second;
            if (curr > capacity) {
                return false;
            }
        }
        return true;
    }
};