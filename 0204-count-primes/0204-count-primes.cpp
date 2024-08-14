class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isprime(n+1,1);
        isprime[0]=0;
        isprime[1]=0;
        for(int i=2;i<sqrt(n);i++){
            if(isprime[i]){
                for(int j=2*i;j<n;j+=i){
                    isprime[j]=0;
                }
            }
        }
        int primecount=0;

        for(int k=2;k<n;k++){
            if(isprime[k]==1)
            {primecount++;
            }
        }

        return primecount;


        
    }
};