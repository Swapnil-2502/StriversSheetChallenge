
bool isPossible(int node,vector<vector<int>> &mat,int i,vector<int> &col){

    for(int j=0;j<mat.size();j++){
        if(mat[node][j] == 1 && col[j] == i) return false;
    }
    return true;
}

bool solve(int node, vector<vector<int>> &mat, int n, int m,vector<int> &col){

    //Base Case
    if(node == n){
        return true;
    }

    for(int i=1;i<=m;i++){
        if(isPossible(node,mat,i,col)){
            col[node] = i;
            if(solve(node+1,mat,n,m,col)) return true;
            col[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    
    int n = mat.size();

    vector<int> col(n,0);
    int node = 0;

    if(solve(node,mat,n,m,col)) return "YES";
    return "NO";

    //TC = O(N^M);
    //SC = O(N);
}