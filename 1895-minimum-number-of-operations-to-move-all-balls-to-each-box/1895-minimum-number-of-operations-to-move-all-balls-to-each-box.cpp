class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>operations;
        int currbox=0;
        
        int n=boxes.length();
        for(int currbox=0;currbox<n;currbox++){
            int indexmove=0;

            for(int i=0;i<n;i++){
                if(i==currbox){
                    continue;
                }

                if( i!=currbox && boxes[i]!='0'){
                    indexmove+=abs(currbox-i);
                }





            }
            operations.push_back(indexmove);
            
            
        }
        return operations;
        
    }
};