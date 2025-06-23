class Solution {
public:

    bool isprime(int n){
        
            if(n<=1)return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)return false;
        }

        return true;


    }


    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int>freqs;

        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto num:mp){
            freqs.push_back(num.second);
        }

        for(auto nu:freqs){
            if(isprime(nu)){return true;
            break;}
        }
        return false;







        
    }
};