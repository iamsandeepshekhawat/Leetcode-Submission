class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>mp; int cnt = 0;
        for(int i=1;i<=n;i++){
            int num = i, sum = 0;
            while(num){
                int rem = num % 10;
                num = num/10;
                sum+=rem;
            }
            mp[sum] = mp[sum] + 1;
        }
        // Check the Group which has highest element
        int maxele = 0;
        for(auto it:mp){
             maxele = max(maxele,it.second);
        }
        // We will count how many groups has maxele no of elements
        for(auto it:mp){
            if(it.second==maxele)
            cnt = cnt + 1;
        }

        return cnt;
     }
};

// TC = O(NlogN)
// SC = O(logN)