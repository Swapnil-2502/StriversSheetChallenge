int romanToInt(string s) {
    unordered_map<char,int> mp;

    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int value = 0;

    for(int i=0;i<s.size();i++){
        
        if(i<s.size()-1 && mp[s[i]] < mp[s[i+1]]) value -= mp[s[i]];
        else value += mp[s[i]];
    }

    return value;

    //TC = O(N);
    //SC = O(1);
}