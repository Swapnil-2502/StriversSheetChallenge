string longestPalinSubstring(string str)
{
    int n = str.length();
    string res = "";
    int resLen = 0;
    int left,right;
    for(int i=0;i<str.length();i++){
        left = i;
        right = i;

        //odd Length
        while(left>=0 && right<n && str[left]==str[right]){
            
            if(right-left+1 > resLen){
                res = str.substr(left,right-left+1);
                resLen = right-left+1;
            }
            left -=1;
            right +=1;
        }

        //odd Length
        left = i;
        right = i+1;
        while(left>=0 && right<n && str[left]==str[right]){
            if(right-left+1 > resLen){
                res = str.substr(left,right-left+1);
                resLen = right-left+1;
            }
            left -=1;
            right +=1;
        }
    }
    return res;
    //TC = O(N^2);
    //SC = O(1);
}