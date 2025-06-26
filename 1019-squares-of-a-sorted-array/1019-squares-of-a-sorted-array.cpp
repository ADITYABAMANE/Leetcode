class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>squares;
        for(int i=0;i<n;i++){
            int sq=nums[i]*nums[i];
            squares.push_back(sq);


        }
        sort(squares.begin(),squares.end());
        return squares;
        
    }
};