class Solution {
    void calculatorLPS(string& part,int& n,vector<int>& lps){
        int i = 0, j = 1;

        while(j<n){
            if(part[i]==part[j]){
                lps[j] = 1 + i;
                i = i+1;
                j =j+1;
            }else{
                if(i>0)        i=lps[i-1];
                else            j = j+1;
            }
        }
    }
    void removeSubstrings(string& s,string& part,vector<int>& lps){
        int m = s.size();
        int n = part.size();
        int i = 0;  //For s
        int j = 0; //For part

        while(i<m){
            if(s[i]==part[j]){
                i = i+1;
                j= j+1;
            }
            if(j==n){ //Found part match
            s = s.substr(0,i-n) + s.substr(i); //Remove substring
            m = s.size(); // Size of string will change
            i = max(0,i-2*n); //Update start point
            j = 0;
            }
            if(s[i]!=part[j]){
                if(j==0)    i =i+1;
                else         j =lps[j-1];
            }
        }
    }
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        vector<int> lps(n,0);

        calculatorLPS(part,n,lps);
        removeSubstrings(s,part,lps);
        return s;
        
    }
};

// TC = O(M+N)
// SC = O(N)