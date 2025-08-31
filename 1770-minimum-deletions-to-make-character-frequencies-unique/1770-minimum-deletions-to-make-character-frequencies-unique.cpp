class Solution {
public:
    int minDeletions(string s) {
        map<char,int>mp;
        set<int>st;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;

        }
        int res=0;
        for(auto it:mp){

        int freq=it.second;

        while( freq > 0 && st.count(freq)  ){

            
            freq--;
            res++;


        }  
        if(freq>0){
            st.insert(freq);
        }         

        }
        return res;




        
        
    }
};