class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int  n=numCourses;

        vector<vector<int>>adj(n);

        //build adjacency list
        for(auto it:prerequisites )
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(n);
        //calculating indegree of each element
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }}

        //the elemts with indegree 0 are alreday push out from the queue
        queue<int>q;
        for(int i=0;i<n;i++) {
            if(indegree[i]==0){
                q.push(i);
            }
        } 
        //creating topo vcetor
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

        if(topo.size()==n)return topo;
        return {};





        

        
    }
};