class Solution {
public:
    bool isPalindrome(string s) {
        int f = 0;
        int e = s.length() - 1;
        while(f<=e){
            if(isalnum(s[f]) == 0){
                f = f + 1;
                continue;
            }
            if(isalnum(s[e]) == 0){
                e = e - 1;
                continue;
            }
            if(tolower(s[f]) != tolower(s[e])){
                return false;
            }else{
                f = f + 1;
                e = e - 1;
            }
        }

        return true;
    }
};

// TC = O(N)
// SC = O(1)