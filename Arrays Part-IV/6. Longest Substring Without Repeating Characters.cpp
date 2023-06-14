#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Brute
    // set<char> st;
    // int n = input.size();

    // int maxAns = INT_MIN;

    // for(int i=0;i<n;i++){
    //     unordered_set<int> st;

    //     for(int j=i;j<n;j++){

    //         if(st.find(input[j]) != st.end()){
    //             maxAns = max(maxAns, j-i);
    //             break;
    //         }

    //         st.insert(input[j]);
    //     }
    // }
    // return maxAns;
    //TC = O(N^2);
    //SC = O(N);

    //Optimal 1
    int n = input.size();

    int maxAns = INT_MIN;
    unordered_set<int> st;

    int l = 0;

    for(int r=0;r<n;r++){

        if(st.find(input[r]) != st.end()){
            while(l<r && st.find(input[r]) != st.end()){
                st.erase(input[l]);
                l++;
            } 
        }

        st.insert(input[r]);
        maxAns = max(maxAns,r-l+1);
    }
    return maxAns;
    //TC = O(2*N);
    //SC = O(N);

    //Optimal 2
    

}