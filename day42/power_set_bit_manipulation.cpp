class Solution {
public:	
    vector<vector<int> > powerSet(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        int total = (1 << n);

        for(int mask = 0;mask<total;mask++)
        {
            vector<int> ans;
            for(int i = 0;i<n;i++)
            {
                if(mask & (1<<i))
                    {
                        ans.push_back(nums[i]);
                    }
            }
            result.push_back(ans);
        }

        return result;
    }
};
