class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

         int n=stones.size();
        //pushing all elemnts in maxheap so that i get largest 2 elements 
        //on top
        

        priority_queue<int>pq;
        for(auto stone:stones){
            pq.push(stone);
        }

        while( pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();

            

            if(first!=second){pq.push(first-second);
            }
        }

        if(pq.empty()){return 0;
        }return pq.top();
        
    }
};