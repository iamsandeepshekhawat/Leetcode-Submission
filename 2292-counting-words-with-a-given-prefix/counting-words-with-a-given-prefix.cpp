class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(auto word: words){
            bool isPrefix=true;
            for(int i=0;pref[i];i++){
                if(word[i]!=pref[i]){
                    isPrefix=false;
                    break;
                }
            }
            if(isPrefix==true)
               count++;
        }
        return count;
    }
};

// TC = O(N*K)
// SC = O(1)