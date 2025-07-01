class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
        for(auto a:asteroids){

           
            while(!st.empty() && a<0 && st.top()>0){
                 int sum=a+st.top();

            if(sum<0){
                st.pop();


            }
            else if(sum>0){
                a=0;

            }
            else{
                st.pop();
                a=0;

            }




        }
        if(a!=0){
            st.push(a);
        }
        
        }  
       
        int s=st.size();
        vector<int>res(s);
        int end=s-1;
        while(!st.empty()  ){
            res[end]=st.top();
            st.pop();
            end--;
        }
    return res;
        

    }
};