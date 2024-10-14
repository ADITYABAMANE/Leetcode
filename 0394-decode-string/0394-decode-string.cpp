class Solution {
public:
    string decodeString(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){

            if(s[i]==']'){
                string ans="";
                while(st.size()>0 && st.top()!='['){
                   ans=st.top()+ans;
                   st.pop();



                    }
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                //extracting the number
                string number="";
                while(st.size()>0 && isdigit(st.top())){
                    number=st.top()+number;
                    st.pop();
                }
                int nomber=stoi(number);
                string temp=ans;
                for(int j=1;j<nomber;j++){
                    ans=ans+temp;

                    
                }
                for(char c:ans){
                    st.push(c);
                }
                ans="";



            }
            else{
                st.push(s[i]);
            }














        }
        string res="";
        while(st.size()>0){
            res=st.top()+res;
            st.pop();
        }
        return res;
       
        
        


    }
};