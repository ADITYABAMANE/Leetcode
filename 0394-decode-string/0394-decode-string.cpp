class Solution {
public:
    string decodeString(string s) {
        int n=s.length();

        stack<char>st;

        for(int i=0;i<n;i++){

            if(s[i]==']'){
                string temp="";
                while(!st.empty() && st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                string num="";

                while(!st.empty() && isdigit(st.top())){
                    num=st.top()+num;
                    st.pop();
                }
                int number=stoi(num);

                // genarate repeated string;
                string repeated="";

                for(int i=0;i<number;i++){
                    repeated=repeated+temp;

                }

                for(int i=0;i<repeated.size();i++){
                    st.push(repeated[i]);
                    
                }


            }
            else{
                st.push(s[i]);
            }
        }

        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
        
    }
};