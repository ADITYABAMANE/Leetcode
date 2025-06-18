class Solution {
public:
    string decodeString(string s) {

        stack<string>st;

        for(int i=0;i<s.length();i++){
            //push everthing onto the stack until you get ']'

           if( s[i]!=']' ){
                st.push(string(1,s[i]));}
            //storing the string inside the brackets into substr
            
            else
            {
                string substr="";
                while(!st.empty() && st.top()!="["){
                substr=st.top()+substr;
                st.pop();

            }
            //popping out the '['
            if(!st.empty() && st.top()=="["){
                st.pop();
            }
            //now we go for the digits
            string number="";
            while(!st.empty() && isdigit(st.top()[0])){
                number=st.top()+number;
                st.pop();}

            //covert string number to integer
            int num=stoi(number);
            //construct the repeated string
            string repeated="";
            for(int i=0;i<num;i++){
                repeated+=substr;


            }    
            //push back the repeated string into the stack again
            st.push(repeated);



            








            }

        }
        //we have our answer in repeated string inside the stack;
        string result="";
        while(!st.empty()){
            result=st.top()+result;
            st.pop();
        }
        return result;
        
    }
};