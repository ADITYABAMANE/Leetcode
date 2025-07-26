class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi=0;
        int left=0;
        int right=0;
        int n=s.length();

        for(int i=0;i<n;i++){

            if(s[i]=='('){
                left++;
            }
            if(s[i]==')'){
                right++;
            }
            if(right>left){
                left=0;
                right=0;
            }
             if(left==right){
                maxi=max(maxi,2*left);

            }


        }

        left=0;
        right=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                right++;
            }
             if(s[i]=='('){
                left++;
            }
            if(left>right){
                left=0;
                right=0;
            }
            if(left==right){

                maxi=max(maxi,2*left);


            }

        }
        return maxi;
        
    }
};