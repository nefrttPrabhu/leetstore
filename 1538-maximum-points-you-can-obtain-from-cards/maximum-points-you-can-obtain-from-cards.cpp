class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int a = cardPoints.size();
        int n = a - k;
        int sumR = 0;

        for (int i = 0; i < n; i++) {
            sumR += cardPoints[i];
        }

        int j = n;
        int i = 0;
        int mini = sumR;

        while (j < a) {
            sumR += cardPoints[j];
            sumR -= cardPoints[i];
            i++;
            j++;
            mini = min(mini, sumR);
        }

        int sumT = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        return sumT -  mini;
    }
};
