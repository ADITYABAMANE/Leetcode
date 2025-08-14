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

                //extracting the number;
                string number="";
                while(!st.empty() &&  isdigit(st.top())){
                    number=st.top()+number;
                    st.pop();

                }//created the number

                //coverting the number from string tominteger

                int num=stoi(number);
                //creating the repeated string

                string repeated="";
                for(int i=0;i<num;i++){
                    repeated=repeated+temp;
                }

                //pushing the repeated string i have again into the stack;

                for(int i=0;i<repeated.length();i++){
                    st.push(repeated[i]);
                }


            }
            else{
                st.push(s[i]);
            }





        }
        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
        
    }
};