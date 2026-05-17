class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
    
      
    }
    
    void addNum(int num) {
        if (!minHeap.empty() && num > minHeap.top()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }

        if (abs((int)minHeap.size() - (int)maxHeap.size()) > 1) {
            if(minHeap.size() > maxHeap.size()) {
               int x =  minHeap.top();
               minHeap.pop();
               maxHeap.push(x);
            } else {
                int x = maxHeap.top();
                maxHeap.pop();
                minHeap.push(x);
            }
        }
    }
    
    double findMedian() {
        if((minHeap.size() + maxHeap.size()) % 2) {
            if(maxHeap.size() > minHeap.size()) {
                return maxHeap.top();
            }
            else {
                return (double)minHeap.top();
            }
        } else {
            int x = minHeap.top();
            int y = maxHeap.top();
            return (double) (x + y) / 2.0;
        }
    }
};
