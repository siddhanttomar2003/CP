class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;

        for (int i = 0; i < s.size(); i++) {
            char openingBracket = s[i];
            // pushing all the opening brackets in stack
            if (openingBracket == '(' || openingBracket == '{' ||
                openingBracket == '[') {
                bracketStack.push(s[i]);
            } else {
                if (!bracketStack.empty()) {
                    char top = bracketStack.top();
                    if (top == '(' && s[i] == ')' ||
                        top == '{' && s[i] == '}' ||
                        top == '[' && s[i] == ']') {
                        bracketStack.pop();
                    } else
                        return false;
                } else
                    return false;
            }
        }

        if (bracketStack.empty())
            return true;
        return false;
    }
};
