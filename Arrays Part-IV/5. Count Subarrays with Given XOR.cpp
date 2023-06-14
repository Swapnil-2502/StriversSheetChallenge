#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //Optimal
    int n = arr.size();
    int Xor = 0;
    map<int,int> mp;
    mp[Xor]++;
    int count = 0;

    for(int i=0;i<n;i++){

        Xor = Xor ^ arr[i];

        int res = Xor^x;

        count += mp[res];

        mp[Xor]++;
    }
    return count;
    //TC = O(NlogN);
    //SC = O(N);

    // //Better
    // int n = arr.size();
    // int totalSubarray = 0;

    // for(int i=0;i<n;i++){

    //     int XORValue = 0;

    //     for(int j=i;j<n;j++){
    //         XORValue ^= arr[j];


    //         if(XORValue == x){
    //             totalSubarray++;

    //         }
    //     }
    // }
    // return totalSubarray;
    // //TC = O(N^2);
    // //SC = O(1);

}