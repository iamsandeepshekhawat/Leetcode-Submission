class Solution {
public:
    int maxDistance(string s, int k) {
        unordered_map<char, int> freq;
        int maxDist = 0;

        for(char c : s){
            freq[c]++;

            int vertical = abs(freq['N'] - freq['S']);
            int horizontal = abs(freq['E'] - freq['W']);
            int currDist = vertical + horizontal;

            int eastWestChanges = min({k, freq['E'], freq['W']});
            int remainingK = k - eastWestChanges;
            int northSouthChanges = min(remainingK, min(freq['N'], freq['S']));

            maxDist = max(maxDist, currDist + 2 * (eastWestChanges + northSouthChanges));
        }

        return maxDist;
    }
};

// TC = O(N)
// SC = O(1)