#define pii pair<int, int>
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        // Build the adjacency list for the undirected graph.
        // Each element in 'adj' represents a list of pairs (neighbor, edge_length).
        vector<vector<pii>> adj(n);
        for(auto &edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Priority queue for Dijkstra's algorithm.
        // It stores pairs (current_distance, node) so that the node with the smallest distance is processed first.
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});  // Start from node 0 with a distance of 0.
        
        // Initialize the distance vector with a large value (infinity substitute).
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        
        // Dijkstra's algorithm main loop.
        while(!pq.empty()){
            // Extract the node with the smallest current distance.
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // If the current distance does not match the best known distance, skip processing.
            if(dist[node] != d) continue;
            
            // Process each neighbor of the current node.
            for(auto &edge : adj[node]){
                int neigh = edge.first;  // The neighbor node.
                int len = edge.second;     // The time needed to travel to the neighbor.
                
                // Check if a new, shorter distance to the neighbor is found.
                if(dist[neigh] > d + len){
                    // Only update if the arrival time is before the neighbor's disappearance.
                    if(d + len < disappear[neigh]){
                        dist[neigh] = d + len;
                        pq.push({dist[neigh], neigh});  // Push the updated distance and node.
                    }
                }
            }
        }
        
        // Replace any distance that remains as 1e9 (i.e., unreachable nodes) with -1.
        for(auto &d : dist)
            d = (d == 1e9 ? -1 : d);
            
        return dist;
    }
};