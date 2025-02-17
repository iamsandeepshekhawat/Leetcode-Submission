class Solution {
    int buildString(vector<int>& freq){
        int ways = 0;
        // Any char can be at current position
        for(int i=0;i<26;i++){
            if(freq[i]>0){ // We can use curr char
            freq[i] = freq[i] - 1;
            ways += 1 + buildString(freq);
            freq[i] = freq[i] + 1;

            }
        }

        return ways;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(char c: tiles)
            freq[c-'A'] = freq[c-'A'] + 1;
        return buildString(freq);
    }
};

// TC = O(26^N)
// SC = O(N)
