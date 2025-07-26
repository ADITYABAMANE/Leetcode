class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        
        // int min_ele=*min_element(piles.begin(),piles.end());
        int max_ele=*max_element(piles.begin(),piles.end());
        int ns=0;

        for(int i=1;i<max_ele;i++){
            long long cnh=0;

            for(int j=0;j<piles.size();j++){
                cnh+= (piles[j] +  i- 1) / i;

            }
             if(cnh<=h){
               return i;

             }


            


        }
        return max_ele;
       
        
        
    }
};