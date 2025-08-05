class Solution {
public:
    int solve(vector<int>& weights , int capacity) {

        int daysneeded=1;
        int load=0;

        for(int i=0;i<weights.size();i++){

            load+=weights[i];

            if(load>capacity){
                load=weights[i];
                daysneeded++;
            }


        }
    return daysneeded;

    

    
}

            

        

        




    
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        int maxele=*max_element(weights.begin(),weights.end());

        int l=maxele;
        int r=sum;

        while(l<r){
            int mid=l+(r-l)/2;

            int mydays=solve(weights,mid);

            if(mydays<=days){
                r=mid;
            }
            else{
                l=mid+1;
            }


        }

        return l;


        

        
        
    }
};