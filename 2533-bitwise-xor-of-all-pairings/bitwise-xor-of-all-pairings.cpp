class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        // Find contribution by first array elements
        int m=nums2.size();
        if(m&1){
            for(int ele: nums1)
            ans^=ele;
        }

        // Find Contribution by Second array elements
        int n=nums1.size();
        if(n&1){
            for(int ele: nums2)
            ans^=ele;
        }

        return ans;
    }
};

// TC = O(M+N)
// SC = O(1)