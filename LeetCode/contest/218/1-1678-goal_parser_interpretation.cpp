// only count at the end when a possible substitution happens
class Solution {
public:
    string interpret(string command) {
        string res;
        int len = command.length();
        for (int i = 0; i < len; ++i) {
            if (command[i] == 'G') res += 'G';
            else if (command[i] == ')' && command[i - 1] == '(') res += 'o';
            else if (command[i] == ')' && command[i - 1] == 'l') res += "al";
        }
        return res;
    }
};