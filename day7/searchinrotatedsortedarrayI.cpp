class Solution {
public:
    int search(vector<int> &nums, int k) {
       int ans = -1;
    int left = 0;
    int right = nums.size()-1;
    int mid;

    while(left<=right)
    {
        mid = (left+right)/2;
        if(nums[mid]==k)
        {
            ans = mid;
        }

        if(nums[left]<=nums[mid])
        {
            if(nums[left]<= k && k <nums[mid])
            {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        else{
            if(k<=nums[right] && k >nums[mid])
            {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }



       return ans;
    }
};
