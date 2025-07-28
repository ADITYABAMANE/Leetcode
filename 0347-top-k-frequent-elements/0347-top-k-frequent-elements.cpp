class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int>mp;

        //calculting the frequency

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        for(auto num : mp){

            pq.push({num.second,num.first});


            if(pq.size()>k){
                pq.pop();
            }




        }
        vector<int>top_k_frequent_elements;

        while(!pq.empty()){

            int number=pq.top().second;
            top_k_frequent_elements.push_back(number);
            pq.pop();


        }
        return top_k_frequent_elements;

        
    }
};