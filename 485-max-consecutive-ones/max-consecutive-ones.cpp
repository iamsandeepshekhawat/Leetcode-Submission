class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count = 0;
            }
            else{
                count = count + 1;
                ans  = max(ans,count);
            }
        }

        return ans;
    }
};

// TC = O(N)
// SC = O(1)