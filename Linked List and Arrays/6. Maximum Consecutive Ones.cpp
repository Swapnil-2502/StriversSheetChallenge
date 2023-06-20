int longestSubSeg(vector<int> &arr , int n, int k){
    
    int maxi = 0;
    int countzeros = 0;

    for(int i=0,j=0;i<n;i++){

        if(arr[i] == 0){
            countzeros++;
        }

        while(countzeros > k){
            if(arr[j] == 0) countzeros--;

            j++;
        }

        maxi = max(maxi,i-j+1);
    }
    return maxi;
    //TC = O(N);
    //SC = O(1);
}
