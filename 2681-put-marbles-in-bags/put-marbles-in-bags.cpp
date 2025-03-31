class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long>boundary_weight;
        int n = weights.size();

        for(int i=0;i<n-1;i++){
            boundary_weight.push_back(weights[i]+=weights[i+1]);
        }
        sort(boundary_weight.begin(),boundary_weight.end());
        long long maxi = 0;
        long long mini = 0;

        for(int i=0;i<k-1;i++){
            mini += boundary_weight[i];
            maxi += boundary_weight[n-2-i];
        }

       
        return maxi-mini;
    }
};

// TC = O(NlogN)
// SC = O(N)