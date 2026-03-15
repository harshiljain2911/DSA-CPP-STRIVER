class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        for (int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]<nums[i])
                {
                    int temp = nums[j];
                    nums[j]=nums[i];
                    nums[i] = temp;
                }
            }
        }
        return nums;
    }
};
