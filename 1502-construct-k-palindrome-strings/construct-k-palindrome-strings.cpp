class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;

        // STEP1 Count Character frequencies
        vector<int> freq(26);
        for(char c: s)
        freq[c-'a']++;

        // STEP2 Count odd frequency characters
        int odd_freq=0;
        for(int i=0;i<26;i++)
            if(freq[i]&1)
            odd_freq++;
        
        return odd_freq<=k;
    }
};

// TC = O(N)
// SC = O(1)