class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long total_sum = 0;
        for(int ele : nums)
            total_sum += ele;

            int count = 0;
            long long prefix_sum = 0;
            for(int i=0;i<n-1;i++){
                prefix_sum += nums[i];
                if(prefix_sum >= total_sum-prefix_sum)
                    count++;
                }
               return count;
        }
};

// TC = O(N)
// SC = O(1)