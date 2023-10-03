class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=nums.size(),ans=s;
        for(int i=0;i<s;i++)
            ans=ans^i^nums[i];
            return ans;
        }
    
};
