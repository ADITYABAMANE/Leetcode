class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
       vector<vector<int>>adj(n);
        
        //make the adjacency list
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);

        }

        //implement topo sort and then store the topo sort
        vector<int>indegree(n,0);
        //fill the indegree in the below step;

        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            //after the node is removed from the queue reduce the indegree of the adjacent nodes of the node
            for(auto it:adj[node]){
                indegree[it]--;

                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==n)return true;

        return false;





        
    }
};