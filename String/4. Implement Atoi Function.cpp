#include <bits/stdc++.h> 
int atoi(string str) {
    
    int n = str.size();
    int value = 0;

    for(int i=0;i<n;i++){
      if (str[i] >= '0' && str[i] <= '9') {
        value = value * 10 + (str[i] - '0');
      }
    }

    if (str[0] == '-')
      return -value;
    return value;

    // TC = O(N);
    // SC = O(1);
}
