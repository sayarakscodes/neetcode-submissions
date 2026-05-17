class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";

        while(!pq.empty()) {
            auto frst = pq.top();
            pq.pop();
            if(ans.size() >= 2 && ans[ans.size() - 1] == frst.second
             && ans[ans.size() - 2] == frst.second) {
                if (pq.size() == 0) break;
                auto scnd = pq.top();
                pq.pop();
                ans.push_back(scnd.second);
                if(scnd.first - 1 > 0) {
                    pq.push({scnd.first - 1, scnd.second});
                } 
                pq.push(frst);

             } else {
                ans.push_back(frst.second);
            
                if(frst.first - 1 > 0) {
                    pq.push({frst.first - 1, frst.second});
                }
             }
            
        }
        return ans;
    }
};