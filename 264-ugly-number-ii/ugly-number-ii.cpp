class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> st;
        
        pq.push(1);
        st.insert(1);

        long top = 1;
        for(int i = 0; i < n; ++i) {
            top = pq.top();
            pq.pop();

            if(st.insert(top * 2).second)
                pq.push(top * 2);
            if(st.insert(top * 3).second)
                pq.push(top * 3);
            if(st.insert(top * 5).second)
                pq.push(top * 5);
        }

        return (int)top;
    }
};
