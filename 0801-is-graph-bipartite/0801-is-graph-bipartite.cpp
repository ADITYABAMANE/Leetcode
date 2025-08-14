class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();

        vector<int>colour(v,-1);

        for(int i=0;i<v;i++){
           
           if(colour[i]==-1){
            queue<int>q;
            colour[0]=0;

            q.push(i);


            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(auto it:graph[node]){

                    if(colour[it]==-1){
                        colour[it]=1-colour[node];
                        q.push(it);

                    }
                    else if(colour[it]==colour[node]){
                        return false;

                    }
                }
            }



           }
            




        }
        return true;
        
    }
};