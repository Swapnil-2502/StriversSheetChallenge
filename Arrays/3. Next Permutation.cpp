#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{   
    int index = -1;

    for(int i=n-2;i>=0;i--){
        if(permutation[i] < permutation[i+1]){
            index = i;
            break;
        }
    }

    if(index == -1){
        reverse(permutation.begin(),permutation.end());
        return permutation;
    } 

    for(int i=n-1;i>=0;i--){
        if(permutation[i]>permutation[index]){
            swap(permutation[i],permutation[index]);
            break;
        }
    }

    reverse(permutation.begin() + index + 1, permutation.end());

    return permutation;

}
//TC = O(3N);
//SC = O(N);

//Step1: Find the break point so we iterated reverse from n-2
//Step2: Then find someone who se greather then the element at breakpoint but the smallest and swap them
//Step3: Reverse the remaining array to get the next greater permutation.