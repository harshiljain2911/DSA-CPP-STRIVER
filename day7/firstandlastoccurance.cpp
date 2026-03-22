class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int ansl=-1;
        int ansr=-1;
        int left = 0;
        int right = nums.size()-1;
        int mid;

        if(nums.empty()){
            return {ansl,ansr};
        }

        while(left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid]==target){
                ansl = mid;
                right = mid-1;
            }
            else if(nums[mid]>target)
            {
                right = mid-1;
            }
            else{
                left = mid+1;
            }

        }

    left = 0;
    right = nums.size()-1;

          while(left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid]==target){
                ansr = mid;
                left = mid+1;
            }
            else if(nums[mid]>target)
            {
                right = mid-1;
            }
            else{
                left = mid+1;
            }

        }


        return {ansl,ansr};
    }
};
