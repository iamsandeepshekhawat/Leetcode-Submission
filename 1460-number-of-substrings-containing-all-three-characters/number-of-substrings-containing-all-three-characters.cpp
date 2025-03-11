class Solution {
public:
    int numberOfSubstrings(string s) {
        int n =s.size();
        int subarrays = 0;
        vector<int> freq(3,0);

        int left = 0,right = 0;
        while(right<n){
            freq[s[right]-'a']++;

            // Slide Window from left by 1 char (Don't slide until you find a valid window)
            while(freq[0]>0 and freq[1]>0 and freq[2]>0){
                subarrays += n-right;
                freq[s[left]-'a']--;
                left++;
            }
            right++;
        }

        return subarrays;

    }
};


// TC = O(N)
// SC = O(1)