class Solution {
public:
    string removeStars(string s) {
        string newstr="";
        for(char ch:s){
            if(ch=='*'){
                if(!newstr.empty()){
                newstr.pop_back();}

            }
            else{
            newstr+=ch;}
        }
        return newstr;
    }
};