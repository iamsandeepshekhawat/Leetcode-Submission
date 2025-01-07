class Solution {
    void precompute_LPS(vector<string>& words,vector<vector<int>>& lps){
        for(string word: words){
            int m=word.size();
            vector<int> word_lps(m);

            // Two Pointer Appraoch
            int i=1,j=0;
            while(i<m){
                if(word[i]==word[j]){
                    word_lps[i] = j+1;
                    i++;
                    j++;
                }else if(j>0){
                    j = word_lps[j-1];
                }else{
                    i++;
                }

            }
            lps.push_back(word_lps);
        }
    }
    bool stringMatcher(string& pattern,vector<int>& pattern_lps,string& text){
        int pattern_size = pattern.size();
        int text_size = text.size();
        int i=0; // pattern pointer
        int j=0; // text pointer
        while(i<pattern_size and j<text_size){
            if(pattern[i]==text[j]){
                i++;
                j++;
            }
            if(i==pattern_size)
            return true;

            if(text_size and pattern[i]!=text[j]){
                if(i>0){
                    i = pattern_lps[i-1];
                }else{
                    j++;
                }
            }

        }
        return false;
    }
    static bool comparator(string& word1, string& word2){
        return word1.size()<=word2.size();
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();

        // STEP 1.Sort by word size (Pattern must be of smaller size)
        sort(words.begin(),words.end(),comparator);

        // STEP 2.Precompute LPS for all words
        vector<vector<int>> lps;
        precompute_LPS(words,lps);

        // STEP 3.Match all O(N^2) combination of words
        vector<string> res;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(stringMatcher(words[i],lps[i],words[j])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};

// TC = O(N²M)                   // N = Number of Words             
// SC = O(NM)                    // M = Length of Each Words