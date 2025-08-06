class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool>vis(n,false);
        int cnt=n;

        for(int i=0;i<fruits.size();i++){

            for(int j=0;j<baskets.size();j++){

                if(!vis[j] && fruits[i]<=baskets[j]){
                    vis[j]=true;
                    cnt--;
                    break;

                }
            }
        }
        return cnt;

        
    }
};