class MedianFinder {
public:
    priority_queue<int> left; //max heap
    priority_queue<int, vector<int>, greater<int>> right; //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num < left.top()){
            left.push(num);
        }

        else{
            right.push(num);
        }
        //ya toh left right ka size equal ho yab fir left mai zyda ho right se
        if(abs((int)left.size() - (int)right.size()) > 1){
            right.push(left.top());
            left.pop();
        }
        else if(left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            double mean = (left.top() + right.top()) / 2.0;
            return mean;
        }
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */