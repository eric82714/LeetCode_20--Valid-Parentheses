char match(char c)
{
    if(c == '(') return ')';
    if(c == '{') return '}';
    if(c == '[') return ']';
    
    return '\0';
}

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack{};
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') stack.push_back(s[i]);
            else{
                if(i == 0) return false;
                if(stack.empty() || match(stack.back()) != s[i]) return false;
                stack.pop_back();
            }
        }
        if(stack.empty()) return true;
        else return false;
    }
};
