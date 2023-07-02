#include <bits/stdc++.h> 

bool isSafe(int row, int col, vector<vector<int> > &vis,vector<vector<int> > &maze,
int n){
  if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && 
  maze[row][col] == 1) return true;

  return false;
}

void solve(int row,int col,vector<vector<int> > &maze,vector<vector<int> > &ans,
vector<vector<int> > &vis,int n){
  
  //Base Case
  if(row == n-1 && col == n-1){
    
    vis[row][col] = 1;
    vector<int> temp;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        temp.push_back(vis[i][j]);
      }
      
    }
    ans.push_back(temp);
    vis[row][col] = 0;
    return;
  }

  //Down
  int nRow = row+1;
  int nCol = col; 
  if(isSafe(nRow,nCol,vis,maze,n)){
    vis[row][col] = 1;
    solve(row+1,col,maze,ans,vis,n);
    vis[row][col] = 0;
  } 

  //Left
  nRow=row;
  nCol=col-1;
  if(isSafe(nRow,nCol,vis,maze,n)){
    vis[row][col] = 1;
    solve(row,col-1,maze,ans,vis,n);
    vis[row][col] = 0;
  }

  //Right
  nRow=row;
  nCol=col+1;
  if(isSafe(nRow,nCol,vis,maze,n)){
    vis[row][col] = 1;
    solve(row,col+1,maze,ans,vis,n);
    vis[row][col] = 0;
  }  

  //Up
  nRow=row-1;
  nCol=col;
  if(isSafe(nRow,nCol,vis,maze,n)){
    vis[row][col] = 1;
    solve(row-1,col,maze,ans,vis,n);
    vis[row][col] = 0;
  } 
  
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  
  vector<vector<int>> ans;
  vector<vector<int>> vis(n,vector<int>(n,0));

  if(maze[0][0]==1) solve(0,0,maze,ans,vis,n);

  return ans;
  //TC = O(4^(N+N));
  //SC = O(N*N)

}