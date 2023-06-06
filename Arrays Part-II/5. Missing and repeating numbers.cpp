#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int N)
{
	//Optimal
	long long n = arr.size();
    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)y, (int)x};
	// //TC = O(N);
	// //SC = O(1);
	


	// //Brute
	// vector<int> freq(n+1,0);

	// for(int i=0;i<=n;i++){
	// 	freq[arr[i]]++;
	// }

	// int missing=-1, repeating=-1;

	// for(int i=1;i<=n;i++){
	// 	if(freq[i] == 0) missing = i;
	// 	else if(freq[i]== 2) repeating = i;

	// 	if(missing != -1 && repeating != -1) break;
	// }
	// return {missing,repeating};
	// //TC = O(2*N);
	// //SC = O(N);
	
}
