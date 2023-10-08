class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n=nums.size() , maxFreq=0,ans=n;
        unordered_map<int,int>freq,left,right;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            maxFreq=max(maxFreq,freq[nums[i]]);
            if(left.find(nums[i]) == left.end())  left[nums[i]]=i;
            right[nums[i]] = i;
        }

        for(auto&p :freq)
        if(p.second==maxFreq)
        ans=min(ans,right[p.first] -left[p.first]+1);
        return ans;
    }
};
