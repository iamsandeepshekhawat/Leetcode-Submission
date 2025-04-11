class Solution {
public:
    void merge(vector<int>& nums,vector<int>& v1,vector<int>& v2){
        int i =0,j=0,k=0;
        int n = v1.size();
        int m = v2.size();
        while(i<n && j<m){
            if(v1[i]>=v2[j]){
                nums[k++]=v2[j++];
            }else{
                nums[k++]=v1[i++];
            }
        }
        if(i==n){
            while(j<m){
                nums[k++]=v2[j++];
            }
        }
        else{
            while(i<n) nums[k++]=v1[i++];
        }
    }
    void mergeSort(vector<int>& nums,int& ans) {
        int n = nums.size();
        if(n<=1) return;
        int n1 = n/2;
        int n2 = n-n/2;
        vector<int>v1(n1),v2(n2);
        for(int i=0;i<n;i++){
            if(i<n1) v1[i]=nums[i];
            else v2[i-n1]=nums[i];
        }

        mergeSort(v1,ans);
        mergeSort(v2,ans);

        int i=0,j=0;
        while(i<n1 && j<n2){
            if(v1[i]>(long long)2*v2[j]){
                ans+=n1-i;
                j = j + 1;;
            }else
                i = i + 1;
        }

        merge(nums,v1,v2);
    }
    int reversePairs(vector<int>& nums) {
        int ans  = 0;
        mergeSort(nums,ans);
        return ans;
    }
};

// TC = O(NlogN)
// SC = O(N)