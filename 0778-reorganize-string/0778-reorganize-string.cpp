class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();

        map<char,int>mp;

        //calculating the freq of each character and storing in the map
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        //calculating the maxfrq and maxchar
        int maxfreq=0;
        char maxchar;

        for(auto it:mp){
            if(it.second>maxfreq){
                maxfreq=it.second;
                maxchar=it.first;
            }


        }
        
        //checking if the string can be organized

        if(maxfreq>(n+1)/2)return "";
        vector<char>res(n);
        //distribute the maxchar at alternate places i.e at even places

        int idx=0;
        while(maxfreq-->0){
            res[idx]=maxchar;
            idx+=2;
        }

        for(auto entry:mp){
            int freq_of_rest_characters=entry.second;
            char res_char=entry.first;

            if(res_char==maxchar)continue;

            while(freq_of_rest_characters-->0){

                if(idx>=res.size())idx=1;

                res[idx]=res_char;
                idx+=2;
            }
        }




        return string(res.begin(),res.end());







        
    }
};