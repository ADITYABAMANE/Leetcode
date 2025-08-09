class Solution {
public:

    vector<vector<int>>updatingimage(vector<vector<int>>& image,int ir,int ic,int color){
        int n=image.size();
        int m=image[0].size();
         
        int original_color=image[ir][ic];
        if (image[ir][ic] == color) return image;
        image[ir][ic]=color;
       


        queue<pair<int,int>>q;
        q.push({ir,ic});

        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};

        while(!q.empty()){
            int crow=q.front().first;
            int ccol=q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int nrow=crow+delrow[i];
                int ncol=ccol+delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&  image[nrow][ncol]==original_color){
                    image[nrow][ncol]=color;

                    q.push({nrow,ncol});
                }

                
            }
        }
        return image;





    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {


        return updatingimage(image, sr,sc,color);
        
    }
};