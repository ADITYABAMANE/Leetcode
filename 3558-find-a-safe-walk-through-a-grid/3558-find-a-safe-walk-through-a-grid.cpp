#define F first 
#define S second 
class Solution {
public:
    using state = pair<int,int> ; 
    using vvi = vector<vector<int>> ; 
    using vi = vector<int> ;  
    const int INF = 1e9 ;
    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}} ;

    vvi dist,visi ; 

    bool check(int x, int y, int m, int n ){
        return x>=0 && x<m && y>=0 && y<n ; 
    }


    void bfs(state  st , vector<vector<int>>&grid, int health ,int m, int n ){

        dist = vector<vector<int>>(m,vector<int>(n,INF)) ; 
        visi =  vector<vector<int>>(m,vector<int>(n,0)) ; 

        deque<state> dq ; 

        dq.push_front(st) ; 

        dist[st.F][st.S] = (grid[st.F][st.S]==1) ? 1 : 0; 
        // visi[st.F][st.S] = 1 ;


        while(!dq.empty()){
            auto curr = dq.front();
            int curx = curr.F ; 
            int cury = curr.S ; 
            dq.pop_front(); 

            // cout<<"Taking element"<<curx<<" "<<cury<<endl;

            if(visi[curx][cury]==1) continue ; 
            visi[curx][cury]=1 ;

            for(int i=0;i<4;i++){
                // cout<<"HEY"<<endl;
                int newx = curx +  dir[i][0]; 
                int newy = cury +  dir[i][1] ; 
                

                if(check(newx,newy,m,n)){
                    // cout<<"neightbouts of "<<curx<<" "<<cury<<" : ";
                    // cout<<newx<<" "<<newy<<endl;
                    int edgewt = (grid[newx][newy]==1) ? 1 : 0 ;
                    if(dist[newx][newy] > dist[curr.F][curr.S] + edgewt){
                        //edge wt relaxing
                        dist[newx][newy]  =  dist[curr.F][curr.S] + edgewt ; 
                        if(edgewt ==  0){
                            dq.push_front({newx,newy} ); 
                        }
                        else{
                            dq.push_back({newx,newy}) ; 
                        }
                    }   

                }



            }
        }
        


    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() ; 
        int n = grid[0].size() ; 
        bfs({0,0} , grid, health,m,n) ; 

        cout<<dist[m-1][n-1]<<endl;
        if(health - dist[m-1][n-1] > 0 ){
            return true ;
        }
        else{
            return false ;
        }
    }
};