class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n));
        // (SubProblem) dp[x][y]: Longest fib chain length ending at 'y' with 'x' being with the previous item

        int longest = 0;
        for(int sum=2;sum<n;sum++){
            int a = 0;
            int b = sum-1;
            // Two-Sum Apporach
            while(a<b){
                if(arr[a]+arr[b]<arr[sum])      a = a + 1;
                else if(arr[a]+arr[b]>arr[sum]) b = b - 1;
                else{
                    dp[b][sum] = 1 + dp[a][b];
                    longest = max(longest,dp[b][sum]);
                    a = a + 1;
                    b = b - 1;
                }
            }
        }

        return longest == 0? 0 : 2+longest;





    }
};

// TC = O(N²)
// SC = O(N²)