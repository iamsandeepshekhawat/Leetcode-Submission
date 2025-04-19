class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n = nums.size();

        int prefixSum = nums[0];

        //longestsequential prefixsum
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1] +1){
                prefixSum += nums[i];
            }
            else
                break;
        }

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(nums[i] == prefixSum){
                prefixSum = prefixSum + 1;
            }
        }

        return prefixSum;
    }
};

// TC = O(NlogN)
// SC = (N)