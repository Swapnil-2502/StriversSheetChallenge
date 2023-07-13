#include<queue>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    
    //{{r,c},time}
    queue< pair<pair<int,int>,int>> q;

    int vis[n][m];
    // int cntFresh = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }

            // if(grid[i][j] == 1) cntFresh++;
        }
    }

    int Mintime = 0;

    int deltaRow[] = {-1,0,1,0};
    int deltaCol[] = {0,1,0,-1};
    int cnt;
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();

        Mintime = max(Mintime,time);

        for(int i=0;i<4;i++){
            int nrow = deltaRow[i] + row;
            int ncol = deltaCol[i] + col;

            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 
            && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                q.push({{nrow,ncol},time+1});
                vis[nrow][ncol] = 2;
                // cnt++;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]!=2 && grid[i][j]==1)return -1;
        }
    }
    // if(cnt != cntFresh) return -1;
    return Mintime;

    //TC = O(N*N)*4;
    //SC = O(N*N);
}