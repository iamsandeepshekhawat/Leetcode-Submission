class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int length = 0;
        while(s[i]==' '){
            i = i - 1;
        }
        while(i>=0 && s[i]!=' '){
            length = length + 1;
            i = i - 1;
        }

        return length;
    }
};

// TC = O(N)
// SC = O(1)