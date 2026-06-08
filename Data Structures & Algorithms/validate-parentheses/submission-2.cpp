class Solution {
public:
    bool isValid(string s) {
        stack<char> found_brackets;
        for (char bracket : s) {
            if (bracket == '('){
                found_brackets.push(')');
            }
            else if (bracket == '{') {
                found_brackets.push('}');
            }
            else if (bracket == '[') {
                found_brackets.push(']');
            }
            else {
                if (found_brackets.empty()) {
                    return false;
                }
                if (bracket == found_brackets.top()) {
                    found_brackets.pop();
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        if (found_brackets.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
