class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mp;
        int maxlen=INT_MIN;

        int i=0;
        int j=i;
        while(j<fruits.size()){
            mp[fruits[j]]++;

            if(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;

            }

            maxlen=max(maxlen,j-i+1);
            j++;





        }
        return maxlen;
        
    }
};