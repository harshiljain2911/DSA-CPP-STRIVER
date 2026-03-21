class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums.size(); // default (agar nahi mila toh)

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(nums[mid] >= x)
            {
                ans = mid;          // possible answer
                right = mid - 1;    // left side check karo
            }
            else
            {
                left = mid + 1;     // right side jao
            }
        }

        return ans;
    }
};
