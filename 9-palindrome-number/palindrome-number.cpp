class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)   return false;
        
        int revNum = 0, dup = x;
        while(x>0){
            int id = x%10;
            
            if(revNum > (INT_MAX/10) || (revNum == INT_MAX / 10 && id>7)){
                return false;
            }

            revNum = (revNum * 10) + id;
            x = x / 10;
        }
        return dup == revNum;

     }
};

// TC = O(logX)
// SC = O(1)