class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>digitFreq(10,0);
            for(int&num:digits){
                digitFreq[num]++;
            }
            vector<int>ans;
            int i = 100;
            while(i<999){
                int num = i;
                vector<int>tempFreq = digitFreq;
                bool found = true;
                while(num>0){
                    int digit = num%10;
                    if(tempFreq[digit] == 0){
                        found  = false;
                        break;
                    }
                    else{
                        tempFreq[digit]--;
                    }

                    num/=10;
                }

                if(found){
                    ans.push_back(i);
                }

                i+=2;
            }

            return ans;

    }
};


// TC = O(N)
// SC = O(1)