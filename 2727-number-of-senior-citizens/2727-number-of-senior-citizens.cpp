class Solution {
public:

     vector<int> citizens(vector<string>&strings) {
        vector<int> ages;
        for (auto detail : strings) {
            int n = detail.size();
            
            string ageStr = detail.substr(n - 4, 2); 
            int age = stoi(ageStr); 
            ages.push_back(age); 
        }
        return ages;
    }

    int countSeniors(vector<string>& details) {
        vector<int>result=citizens(details);
        int count=0;
        for(int i=0;i<result.size();i++){
            if(result[i]>60)count++;
        }
        return count;
        
    }
};