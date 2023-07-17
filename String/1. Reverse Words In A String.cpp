#include<bits/stdc++.h>

string reverseString(string &s){
	// int n = str.length();
	// string temp = "";

	// string str2 = "";
	// stack<string> s2;

	// for(int i=0;i<n;i++){
	// 	string word = "";

	// 	if(str[i] == ' ') continue;

	// 	while(i<n && str[i] != ' '){
	// 		word += str[i];
	// 		i++;
	// 	}
	// 	s2.push(word);
	// }

	// while(s2.size() != 1){
	// 	str2 += s2.top() + " ";
	// 	s2.pop();
	// }
	// str2 += s2.top();

	// return str2;
	//TC = O(N);
	//SC = O(N);

	  if(s.size() == 0) 
            return s;
        stack<string> st;
        string ans;
        for(int i=0; i<s.size(); i++) 
        {
            string word="";
            
               if(s[i] == ' ') 
                   continue; 
            while(i < s.size() && s[i] != ' ' ) { 
                word += s[i]; 
                i++;
            }
            
            st.push(word);
            }
        while(st.empty()==0)
            {
            ans += st.top(); 
            st.pop();
        
        if(!st.empty()) 
            {
                ans += ' ';
            }
        }
        return ans;
	
}