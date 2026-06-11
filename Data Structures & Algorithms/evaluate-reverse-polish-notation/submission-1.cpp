class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tokens_found;
        int left, right;
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                left = tokens_found.top();
                tokens_found.pop();
                right = tokens_found.top();
                tokens_found.pop();

                if (token == "+") {
                tokens_found.push(right + left);
                }
                else if (token == "-") {
                    tokens_found.push(right - left);
                }
                else if (token == "*") {
                    tokens_found.push(right * left);
                }
                else if (token == "/") {
                    tokens_found.push(right / left);
                }
            }
            else {
                tokens_found.push(stoi(token));
            }
        }
        return tokens_found.top();
    }
};
