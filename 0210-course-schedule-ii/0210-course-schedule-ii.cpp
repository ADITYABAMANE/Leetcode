class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        //declaring an adjacency matrix
        vector<vector<int>>adj(n);

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        //built a graph;
        //implementing a topo sort

        vector<int>indegree(n);
        queue<int>q;
        //filling the indegree calculating the no of edges coming to each node

        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }}

        //pushing the node with empty indegree into the queue

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // declare the topo vector and  
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
           topo.push_back(node);
           q.pop();

           //loose all the edes to the node attached to the node popped back 

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }






        }
        if(topo.size()==n)return topo;

        return {};










        




        
        


        
    }
};