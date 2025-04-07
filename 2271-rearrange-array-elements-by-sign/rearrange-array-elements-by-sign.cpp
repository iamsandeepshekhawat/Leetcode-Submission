class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        int posindex = 0, negindex = 1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                res[posindex] = nums[i];
                posindex+=2;
            }else{
                res[negindex] = nums[i];
                negindex+=2;
            }
        }

        return res;
    }
};

// TC = O(N)
// SC = O(N)