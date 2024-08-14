class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isprime(n+1,true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2;i<sqrt(n);i++){
            if(isprime[i]){
                for(int j=2*i;j<n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        int primecount=0;

        for(int k=2;k<n;k++){
            if(isprime[k])
            {primecount++;
            }
        }

        return primecount;


        
    }
};