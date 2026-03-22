class Solution {
public:
    int findMin(vector<int> &arr)  {
      int left = 0;
      int mid;
      int right = arr.size()-1;
      while(left<right)
      {
        mid = (left+right)/2;
        if(arr[mid]>arr[right])
        {
            left = mid + 1;
        }
        else{
            right = mid;
        }

        return arr[left];


      }
    }
};
