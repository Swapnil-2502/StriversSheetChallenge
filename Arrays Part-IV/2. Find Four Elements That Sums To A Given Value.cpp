#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    
    //Optimal
    sort(arr.begin(),arr.end());
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if (sum == target) {
                    return "Yes";
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }
    return "No";
    //TC = O(N^3);
    //SC = O(1);

    // //Better 
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         set<long long> st;

    //         for(int k=j+1;k<n;k++){

    //             long long sum = arr[i] + arr[j];
    //             sum += arr[k];

    //             long long fourth = target - sum;

    //             if(st.find(fourth) != st.end()){
    //                 return "Yes";
    //             }

    //             st.insert(arr[k]);
    //         }
    //     }
    // }
    // return "No";
    //TC = O(N^3logN) 
    //SC = O(N);

    // //BRUTE SOLUTION
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         for(int k=j+1;k<n;k++){
    //             for(int l=k+1;l<n;l++){
    //                 long long sum = arr[i] + arr[j];
                   
    //                 sum += arr[k];
    //                 sum += arr[l];

    //                 if(sum == target){
    //                     return "Yes";
    //                 }
    //             }
    //         }
    //     }
    // }
    // return "No";

    //TC = O(N^4);
    //SC = O(1);

}
