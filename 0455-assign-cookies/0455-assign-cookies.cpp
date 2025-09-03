class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        vector<bool>vis(g.size(),false);
        int cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i=0;
        //children's greed

        int j=0;
        //cookie size


        while(i<n && j<m){

            int cookie_size=s[j];

            if(cookie_size>=g[i]){
                i++;
                cnt++;
            }
            j++;


        }
        return cnt;



       
        


        
        
    }
};