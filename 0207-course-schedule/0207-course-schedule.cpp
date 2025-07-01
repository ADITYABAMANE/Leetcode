class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n=numCourses;
        vector<vector<int>>adj(n);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(n);
        for(int i=0;i<n;i++){
            for(auto num:adj[i ]){
                indegree[num]++;

            }
        }

        queue<int>q;
        vector<int>topo;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();

            topo.push_back(node);
            q.pop();
              for(auto z: adj[node]){
                indegree[z]--;
                if(indegree[z]==0){
                    q.push(z);
                }
              }

        }
        if(topo.size()==n)return true;
        return false;



        
    }
};