#include <bits/stdc++.h> 

// int f(int i, int j, int m, int n){

// 	//BASE CASE
// 	if(i==n || j==m) return 0;
// 	if(i==n-1 && j == m-1) return 1;

// 	return f(i,j+1,m,n) + f(i+1,j,m,n);
// }

//func for dp
int f(int i, int j, int m, int n,vector<vector<int>> &dp){

	//BASE CASE
	if(i==m || j==n) return 0;
	if(i==m-1 && j == n-1) return 1;

	if(dp[i][j] != -1) return dp[i][j];

	return dp[i][j] = f(i,j+1,m,n,dp) + f(i+1,j,m,n,dp);
}

int uniquePaths(int m, int n) {
	
	//Recursion
	// return f(0,0,m,n);
	//TC = O(exponential)
	//SC = O(Recursion stack space)

	//Dynamic Programming
	vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	int num = f(0,0,m,n,dp);
	if(m==1 && n==1) return num;
	return dp[0][0];

}