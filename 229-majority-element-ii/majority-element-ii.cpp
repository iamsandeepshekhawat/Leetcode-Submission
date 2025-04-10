class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() < 2) return nums;

        int potential1 = nums[0], potential2 = nums[0];
        int cnt1 = 1, cnt2 = 0;

        for(int i=1;i<nums.size();i++){
            if(nums[i] == potential1){
                cnt1 = cnt1 + 1;
            }else if(nums[i] == potential2){
                cnt2 = cnt2 + 1;
            }else{
                if(cnt1==0){
                    potential1 = nums[i];
                    cnt1 = cnt1 + 1;
                }else if(cnt2==0){
                    potential2 = nums[i];
                    cnt2 = cnt2 + 1;
                  }else{

                    cnt1--, cnt2--;
                }
            }
        }

        cnt1 = 0, cnt2 = 0;
        for(int i: nums){
            if(i == potential1) cnt1++;
            else if(i == potential2) cnt2++;
        }

        vector<int>ans;
        if(cnt1>nums.size() /3) ans.push_back(potential1);
        if(cnt2>nums.size() /3) ans.push_back(potential2);

        return ans;
    }
};


// TC = O(N)
// SC = O(1)