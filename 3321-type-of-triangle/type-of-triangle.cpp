class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c= nums[2];
        if(a==b && b==c) return "equilateral";
        if(a+b > c && b+c > a && c+a > b){
            if(a==b || b==c || c==a)  return "isosceles";
            else return "scalene";
        }

        return "none";
    }
};

// TC = O(1)
// SC = O(1)