class Solution {
public:
    int LIS(vector<int>& nums) {
      
      int n = nums.size();

      int len = 1;
      
      vector<int> temp;
      
      temp.push_back(nums[0]);

      for(int i=1;i<n;i++)
      {
        if(nums[i]>temp.back())
        {
            temp.push_back(nums[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
      }

      return len;

    }    
};
