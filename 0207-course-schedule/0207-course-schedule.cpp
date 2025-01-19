class Solution {

    private: 
    bool dfscheck(int node,vector<int> adj[] ,vector<int>&pathvis,vector<int>&vis){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfscheck(it,adj,pathvis,vis)){
                    return true;
                }
               

            }
             else if(pathvis[it]){
                    return true;

                }


        }






        pathvis[node]=0;
        return false;


    }





public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
         vector<int>pathvis(numCourses,0);
         vector<int> adj[numCourses];
         for(auto it:prerequisites){
             adj[it[1]].push_back(it[0]);
         }


         for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfscheck(i,adj,vis,pathvis))return false;
            }
         }
         return true;

    }
};