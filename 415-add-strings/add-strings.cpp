class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while(i>=0 || j>=0 || carry){
            if(i>=0){
                carry+=num1[i--]-'0';
            }
            if(j>=0){
                carry+=num2[j--]-'0';
            }
            ans+=carry%10 + '0';
            carry/=10;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// TC = O(max(n,m))
// SC = O(max(n,m))