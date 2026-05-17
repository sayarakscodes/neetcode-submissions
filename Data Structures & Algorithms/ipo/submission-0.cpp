class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> pairs;
        int n = profits.size();
        for(int i = 0; i < n; i ++) {
            pairs.push_back({capital[i], profits[i]});
        }
        sort(pairs.begin(), pairs.end());
        priority_queue<int> pq;
        int ans = 0;
        
        for(int i = 0; i < n; i ++) {
            cout << w << " " << pairs[i].first << endl;
            if(pairs[i].first <= w) {
                pq.push(pairs[i].second);
            } else{
                if(k == 0) break;
                while(w < pairs[i].first) {
                    
                    if(!pq.empty() && k != 0) {
                        k --;
                        w += pq.top();
                        pq.pop();
                    } else {
                        break;
                    }

                }
                if(w >= pairs[i].first) {
                    pq.push(pairs[i].second);
                }

            }
            cout << w << " " << pairs[i].first << endl;
        }
        while(k --) {
            if(!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
        }

        return w;
    }
};