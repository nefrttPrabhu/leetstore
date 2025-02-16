// class MedianFinder {
// private:
//     priority_queue<int> left; // Max heap for the smaller half
//     priority_queue<int, vector<int>, greater<int>> right; // Min heap for the larger half
//     vector<int> arr; // Stores numbers

// public:
//     MedianFinder() {}

//     void addNum(int num) {
//         arr.push_back(num); // Store the number
//         int n = arr.size();

//         // Push all elements into the right heap
//         for (int i = 0; i < n; i++) {
//             right.push(arr[i]);
//         }

//         // Move half of the elements from right heap to left heap
//         while (left.size() < n / 2) {
//             left.push(right.top());
//             right.pop();
//         }
//     }

//     double findMedian() {
//         int n = arr.size();
//         if (n % 2 == 0) {
//             return (left.top() + right.top()) / 2.0; // Floating-point division
//         } else {
//             return left.top();
//         }
//     }
// };



class MedianFinder {
private:
    priority_queue<int> left; 
    priority_queue<int, vector<int>, greater<int>> right; 

public:
    MedianFinder() {}

    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    //global declare kiye coz addnum toh void hi toh return nhi karega and findmedian he return karega toh global acessable hi toh udhar se he operations karke return kardega
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top(); 
        } 
        return (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */