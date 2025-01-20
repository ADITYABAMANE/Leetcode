class Solution {
private:
    bool iscycle(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& stack) {
        stack[node] = true;
        if (!visited[node]) {
            visited[node] = true;
            for (auto it : adj[node]) {
                if (!visited[it] && iscycle(it, adj, visited, stack)) {
                    return true;
                }
                if (stack[it]) {
                    return true;
                }
            }
        }
        stack[node] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        vector<vector<int>> adj(numCourses);
        
        
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        
        
        vector<bool> visited(numCourses, false);
        vector<bool> stack(numCourses, false);

        
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && iscycle(i, adj, visited, stack)) {
                return false; 
            }
        }
        return true; 
    }
};
