class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        int res = 0;
        while(ss>>s){
            res += 1;
        }

        return res;
    }
};

// TC = O(N)
// SC = O(N)