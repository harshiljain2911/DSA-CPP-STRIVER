class Solution {
public:
    int LIS(vector<int>& nums) {
      
        int n = nums.size();

        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);

        for(int i=n-1;i>=0;i--)
        {
            for(int pi=i-1;pi>=-1;pi--)
            {
                int len = next[pi+1];

                if(pi==-1 || nums[i]>nums[pi])
                    {
                        len = max(len,1+next[i+1]);  
                    } 

                curr[pi+1]=len;

            }

            next = curr;
        }

        return curr[0];
    }    
};
