class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;

        // 2-Pointer: Variable size sliding window
        int max_window_size = 0;
        int xor_sum = 0;
        int curr_sum = 0;  
        while(right<n){
            curr_sum += nums[right];
            xor_sum ^= nums[right];
        while(xor_sum!=curr_sum){
             curr_sum -= nums[left];
             xor_sum ^= nums[left];
             left = left + 1;
          }
        max_window_size = max(max_window_size,right-left+1);
        right = right + 1;
       }

      return max_window_size;
    }
};

// TC = O(N)
// SC = O(1)