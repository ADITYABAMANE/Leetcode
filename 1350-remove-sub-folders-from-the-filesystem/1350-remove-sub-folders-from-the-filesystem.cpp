class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string>st(folder.begin(),folder.end());

        vector<string>res;

        for(auto str: folder){

            res.push_back(str);

            for(int i=1;i<str.length();i++){

                if(str[i]=='/'){
                    string subfold =str.substr(0,i);
                    if(st.count(subfold)){
                        res.pop_back();
                        break;

                    }

                }
            }






        }
        return res;
        
    }
};