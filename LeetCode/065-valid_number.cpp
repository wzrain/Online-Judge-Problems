// Finite Automation solution
// When sliding through the string, if the string is a number, 
// there are only finite numbers of "legal" states, only some 
// of which are "final" states. So if we encounter an illegal
// state, the string cannot be a number. After the whole visit,
// the string is a number iff the state is a final state.

// <__blank              <__digit
// |  /                  |  /
// | /                   | /
// 0 _______digit______> 1 ___________e________> 5 _______sign______> 6
// |\                    ^\__ ______             ^ \                  |
// | \                   |   \      \            |  \               digit
// |  \                digit  \      \           |   \               \|/
// |   \                 |     \      \          |    \____digit____> 7 ______digit
// |    \___sign_______> 2      \      \         |                    | <___  /
// |                     |      dot   blank      e                  blank   \/
// |                     |        \      \       |                   \|/
// |                    dot        \      \______|__________________> 8 ______blank
// |                     |          \___         |                    ^ <__  /
// |                    \|/             \        |                    |    \/
//  \_______dot________> 3 _______digit__\_____> 4 _________blank_____|
//                                            __>|
//                                           /   |
//                                          /____digit

// The good thing is we can accommodate the arrow directions to the specific 
// demands of the problem. Say we can change 1->4 to 1->3 if something like
// "19." is not regarded as a number.

class Solution {
public:
  bool isNumber(string s) {
    int state = 0;
    vector<unordered_map<char, int>> fa(9);
    fa[0] = {make_pair(' ', 0), make_pair('0', 1), make_pair('+', 2), make_pair('.', 3)};
    fa[1] = {make_pair('0', 1), make_pair('e', 5), make_pair('.', 4), make_pair(' ', 8)};
    fa[2] = {make_pair('0', 1), make_pair('.', 3)};
    fa[3] = {make_pair('0', 4)};
    fa[4] = {make_pair('0', 4), make_pair('e', 5), make_pair(' ', 8)};
    fa[5] = {make_pair('0', 7), make_pair('+', 6)};
    fa[6] = {make_pair('0', 7)};
    fa[7] = {make_pair('0', 7), make_pair(' ', 8)};
    fa[8] = {make_pair(' ', 8)};
    for (auto c : s) {
      if (c >= '0' && c <= '9') c = '0';
      else if (c == '-') c = '+';
      if (fa[state].find(c) == fa[state].end()) return false;
      state = fa[state][c];
    }
    return state == 1 || state == 4 || state == 7 || state == 8;
  }
};