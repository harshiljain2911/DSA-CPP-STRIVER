class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowsize = n - k;
        int windowsum = 0;
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        for(int i=0;i<windowsize;i++)
        {
            windowsum+=cardPoints[i];
        }

        int minsum = windowsum;

        for(int i = windowsize;i<n;i++)
        {
            
            windowsum+=cardPoints[i];
            windowsum-=cardPoints[i-windowsize];

            minsum = min(minsum,windowsum);
        }

        return sum-minsum;
    }
};
