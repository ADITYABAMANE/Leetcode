class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto num:mp){
            pq.push({num.second,num.first});

            if(pq.size()>k){
                pq.pop();
            }



        }
        vector<int>res;
        while(!pq.empty()){
           
            res.push_back(pq.top().second);
            pq.pop();


        }
        return res;



        
    }
};