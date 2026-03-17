class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
       

        nums1.insert(nums1.end(),nums2.begin(),nums2.end());

        for(int i=0;i<nums1.size();i++)
        {
            s.insert(nums1[i]);
        }

        vector<int> v(s.begin(),s.end());
        return v;
    }
};
