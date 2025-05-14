class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string result = "";

        while(columnNumber > 0){
            columnNumber = columnNumber - 1;
            char letter = 'A' + columnNumber % 26;
            result = letter + result;
            columnNumber /= 26;
        }

        return result;
    }
};

// TC = O(log n)
// SC = O(log n)