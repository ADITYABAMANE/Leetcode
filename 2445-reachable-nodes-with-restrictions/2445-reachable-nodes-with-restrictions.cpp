class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // Step 1: Create a visited array of size 'n' and initialize all to false.
        // This keeps track of which nodes we've visited during BFS.
        vector<bool> visited(n, false);
        // Step 2: Mark all restricted nodes as 'visited' so BFS will never enter them.
        // This prevents any path from going through these restricted nodes.
        for(int ele:restricted) visited[ele] = true;
        // Step 3: Create an adjacency list to represent the tree structure.
        // Since this is an undirected tree, add both directions for each edge.
        vector<vector<int>> v(n);
        for(int i=0; i<edges.size(); i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        // Step 4: Initialize a queue for Breadth-First Search (BFS)
        queue<int> q;
        // Step 5: Start BFS from node 0 (as guaranteed in the problem)
        // Mark it visited and push it into the queue
        q.push(0);
        visited[0] = true;
        // Step 6: Start counting reachable nodes — we already visited node 0
        int ans = 1;
        // Step 7: Run the BFS loop until all reachable nodes are processed
        while(!q.empty()){
            // Get the current node from the queue
            int node = q.front();
            q.pop();
            // Step 8: Visit all child of the current node
            for(int child:v[node]){
                // If the child hasn't been visited and is not restricted
                if(!visited[child]){
                    // Mark it as visited so we don't visit it again
                    visited[child] = true;
                    // Add it to the queue to process its neighbors later
                    q.push(child);
                    // Increment the reachable node count
                    ans++;
                }
            }
        }
        // Step 9: After BFS finishes, return the total number of reachable nodes
        return ans;
    }
};