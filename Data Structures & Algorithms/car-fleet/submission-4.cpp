class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        stack<double> st;
        for (auto& p : pair) {
            double time = (double)(target - p.first) / p.second;
            if (!st.empty() && st.top() < time)
                st.push(time);
            else if (st.empty()) {
                st.push(time);
            }
            
        }
        return st.size();

    }

};
