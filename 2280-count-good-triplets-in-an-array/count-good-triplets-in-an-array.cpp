class Solution {
public:
    class BIT {
        vector<int> tree;
        int n;
    public:
        BIT(int size) : n(size), tree(size + 1, 0) {}
        
        void update(int i, int val) {
            for (++i; i <= n; i += i & -i)
                tree[i] += val;
        }
        
        int query(int i) {
            int res = 0;
            for (++i; i > 0; i -= i & -i)
                res += tree[i];
            return res;
        }

        int queryRange(int l, int r) {
            return query(r) - query(l - 1);
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[nums2[i]] = i;

        vector<int> mapped(n);
        for (int i = 0; i < n; ++i)
            mapped[i] = pos[nums1[i]];

        vector<int> leftSmaller(n), rightLarger(n);
        BIT bit(n);

        for (int i = 0; i < n; ++i) {
            leftSmaller[i] = bit.query(mapped[i] - 1);
            bit.update(mapped[i], 1);
        }

        bit = BIT(n);

        for (int i = n - 1; i >= 0; --i) {
            rightLarger[i] = bit.query(n - 1) - bit.query(mapped[i]);
            bit.update(mapped[i], 1);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans += 1LL * leftSmaller[i] * rightLarger[i];
        
        return ans;
    }
};
