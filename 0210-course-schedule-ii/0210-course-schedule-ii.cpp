class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
       

        //building the adjacency list
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        //calculate indegrre of each node
        vector<int>indegree(n);
       for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
       }
       //check if indegree zero,,,then push the node into the ququq
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();


            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
         if (topo.size() == numCourses) 
    return topo;
else 
    return {};
        
    }
};