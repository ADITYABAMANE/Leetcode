class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<vector<int>>adj(n); // adjacency matrix to store the graph
        vector<int>distance(n,-1);
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int>q; // queue to perfrom bfs to calculate distance
        q.push(0);
        distance[0]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto& neighbor:adj[node]){
                if(distance[neighbor]==-1){
                    distance[neighbor]=distance[node]+1;
                    q.push(neighbor);
                }
            }
        }
        int idleTime=0;
        for(int i=1;i<n;++i){
            int firstMsgReceive=distance[i]*2; // time it takes for the first message to get back
            int numberOfExtra=(firstMsgReceive-1)/patience[i]; // number of extra messages that'll be sent
            int lastMsgSent=numberOfExtra*patience[i]; // time at which last message will be sent
            int lastMsgReceive=lastMsgSent+firstMsgReceive; // time at which we will receive reply for last message
            idleTime=max(idleTime,lastMsgReceive);
        }
        return idleTime+1; // idle time would be 1 second afterb we receive last message
    }
};