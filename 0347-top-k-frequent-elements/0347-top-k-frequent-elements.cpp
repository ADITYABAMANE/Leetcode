class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        map<int,int>mp;
        for(auto num:nums){
            mp[num]++;

        }
        for(auto it:mp){
             pq.push({it.second,it.first});

            if(pq.size()>k){
                pq.pop();
            }
           
            
        }
        vector<int>top_k;
        while(!pq.empty()){
            top_k.push_back(pq.top().second);
            pq.pop();


        }
        return top_k;









        


        
    }
};