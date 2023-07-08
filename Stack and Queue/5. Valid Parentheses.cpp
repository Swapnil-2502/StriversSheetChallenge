bool isValidParenthesis(string expression)
{
    stack<int> s;

    for(auto it : expression){

        if(it == '(' || it == '[' || it == '{') s.push(it);

        else{
            if(s.empty()) return false;
            char ch = s.top(); 
            s.pop(); 
            if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
            else return false;
        }
    }
    return true;
    //TC = O(N);
    //SC = O(N);
}