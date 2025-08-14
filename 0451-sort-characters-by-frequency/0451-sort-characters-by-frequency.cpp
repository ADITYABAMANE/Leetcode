class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();

        priority_queue<pair<int,int>> pq;

        map<char,int>mp;

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string res="";
        
        while(!pq.empty()){
            char ch=pq.top().second;
            int num=pq.top().first;
            pq.pop();
            for(int i=0;i<num;i++){
                res.push_back(ch);
            }
        }
        return res;
    }
};