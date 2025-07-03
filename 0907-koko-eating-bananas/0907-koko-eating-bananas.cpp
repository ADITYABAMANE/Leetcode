class Solution {
public:

    bool caneatall(vector<int>&piles,int mid,int h){
        long long actualhrs=0;

        for(auto  it:piles){
            actualhrs+=it/mid;
            if(it%mid!=0){
                actualhrs++;

            }

        }
        return actualhrs<=h;


    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int mid=l+(r-l)/2;
            if(caneatall(piles,mid,h)){
                r=mid;


            }
            else{
                l=mid+1;
            }

        }
        return l;

        
    }
};