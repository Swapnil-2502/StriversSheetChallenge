
bool isSafe(int row,int col, vector<vector<int>> &ds,int n){
    int r = 0,c = 0;

    //Left Checking
    while(c<n){
        if(c==col){
            c++;continue;
        }

        if(ds[row][c] == 1) return false;

        c++;
    }

    r=row,c=col;

    //Upper diagonal Checking
    while(r>=0 && c>=0){
        if(ds[r][c] == 1) return false;

        r--;c--;
    }

    r=row,c=col;
    while(r<n && c>=0){
        if(ds[r][c] == 1) return false;

        r++;c--;
    }

    return true;

}

void solve(int col,vector<vector<int>> &ds, vector<vector<int>> &ans, int n){

    //Base Case
    if(col == n){
        vector<int> temp;
        for(auto it:ds){
            for(int i=0;i<it.size();i++){
                temp.push_back(it[i]);
            }
        }
        
        ans.push_back(temp);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,col,ds,n)){
            ds[row][col] = 1;
            solve(col+1,ds,ans,n);
            ds[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    
    vector<vector<int>> ds(n,vector<int>(n,0));
    vector<vector<int>> ans;

    solve(0,ds,ans,n);   
    return ans;
    //TC = O(N! * N);
    //SC = O(N^2);
}