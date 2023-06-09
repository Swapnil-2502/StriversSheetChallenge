bool searchMatrix(vector<vector<int>>& mat, int target) {

    //Optimal (Binary Search)
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = n*m - 1;

    while(low<=high){
        int mid = (low + (high - low)/2);

        if(mat[mid/m][mid%m] == target) return true;

        if(mat[mid/m][mid%m] < target) low = mid + 1;
        else high = mid - 1;
    }

    return false;
    //TC = O(log(m*n))
    //SC = O(1)



    // //Brute
    // int n = mat.size();
    // int m = mat[0].size();

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(mat[i][j] == target) return true;
    //     }
    // }
    // return false;
    // //TC = O(N*N);
    // //SC = O(1);
}