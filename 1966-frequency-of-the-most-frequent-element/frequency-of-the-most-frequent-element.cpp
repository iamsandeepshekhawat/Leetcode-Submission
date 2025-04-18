class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long n = nums.size();
        sort(nums.begin(),nums.end());
        long l=0,r=0;
        long total = 0,res=0;

        while(r<n){
            total  += nums[r];
            while((nums[r] * (r-l+1)) > (total + k)){
                total -= nums[l];
                l = l + 1;
            }
            res = max(res,(r-l+1));
            r = r + 1;
        }

        return res;
    }
};

// TC = O(NlogN)
// SC = O(1)