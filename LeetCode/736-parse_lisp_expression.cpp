class Solution {
public:
    int evaluate(string expression) {
        int len = expression.length();
        vector<int> last(len, 0), stk;
        for (int i = 0; i < len; ++i) {
            if (expression[i] == '(') stk.push_back(i);
            else if (expression[i] == ')') {
                last[stk.back()] = i;
                stk.pop_back();
            }
        }
        // A variable might have different values in different scopes.
        // Use a stack (vector) to trace its values through the scopes.
        unordered_map<string, vector<int>> vars;
        return dfs(expression, 1, len - 2, last, vars);
    }
    int stoi(int& i, int j, string& exp) {
        int sign = 1;
        int val = 0;
        if (exp[i] == '-') {
            i++;
            sign = -1;
        }
        while (i <= j && exp[i] != ' ') {
            val *= 10;
            val += (exp[i++] - '0');
        }
        i++;
        return val * sign;
    }
    int valFromVar(int& i, int j, string& exp, unordered_map<string, vector<int>>& vars) {
        string rightvar;
        while (i <= j && exp[i] != ' ') rightvar += exp[i++];
        i++;
        return vars[rightvar].back();
    }
    int dfs(string& exp, int i, int j, vector<int>& last, unordered_map<string, vector<int>>& vars) {
        vector<string> changed;
        int res;
        if (exp[i] == 'l') {
            i += 4;
            while (i <= j) {
                string curvar;
                if (exp[i] == '(') { // the to-return expression
                    res = dfs(exp, i + 1, last[i] - 1, last, vars);
                    break;
                }
                else if (exp[i] == '-' || (exp[i] >= '0' && exp[i] <= '9')) { // the to-return value
                    res = stoi(i, j, exp);
                    break;
                }
                while (i <= j && exp[i] != ' ') {
                    curvar += exp[i++];
                }
                if (i > j) {
                    res = vars[curvar].back();
                    break;
                }

                // calculate the right value of curval
                i++;
                int val = 0;
                if (exp[i] == '(') {
                    val = dfs(exp, i + 1, last[i] - 1, last, vars);
                    i = last[i] + 2;
                }
                else if (exp[i] == '-' || (exp[i] >= '0' && exp[i] <= '9')) {
                    val = stoi(i, j, exp);
                }
                else {
                    val = valFromVar(i, j, exp, vars);
                }
                vars[curvar].push_back(val);
                changed.push_back(curvar);
            }
            for (auto& str : changed) {
                vars[str].pop_back();
            }
        }
        else if (exp[i] == 'a') {
            i += 4;
            res = 0;
            while (i <= j) {
                if (exp[i] == '(') {
                    res += dfs(exp, i + 1, last[i] - 1, last, vars);
                    i = last[i] + 2;
                }
                else if (exp[i] == '-' || (exp[i] >= '0' && exp[i] <= '9')) {
                    res += stoi(i, j, exp);
                }
                else {
                    res += valFromVar(i, j, exp, vars);
                }
            }
        }
        else if (exp[i] == 'm') {
            i += 5;
            res = 1;
            while (i <= j) {
                if (exp[i] == '(') {
                    res *= dfs(exp, i + 1, last[i] - 1, last, vars);
                    i = last[i] + 2;
                }
                else if (exp[i] == '-' || (exp[i] >= '0' && exp[i] <= '9')) {
                    res *= stoi(i, j, exp);
                }
                else {
                    res *= valFromVar(i, j, exp, vars);
                }
            }
        }
        return res;
    }
};