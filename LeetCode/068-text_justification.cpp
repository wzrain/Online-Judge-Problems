class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int curlen = words[0].length(), aclen = curlen, first = 0;
    vector<string> res;
    for (int i = 1; i < words.size(); ++i) {
      if (curlen + words[i].length() + 1 > maxWidth) {
        int spnum = i - first - 1, splen = maxWidth - aclen;
        string str;
        for (int sn = spnum; sn > 0; --sn) {
          int tmp = splen / sn;
          if (splen % sn) tmp++;
          splen -= tmp;
          str += words[first + spnum - sn];
          for (int sss = 0; sss < tmp; ++sss) str += " ";
        }
        str += words[i - 1];
        if (!spnum) {
          for (int sss = 0; sss < maxWidth - words[i - 1].length(); ++sss) {
            str += " ";
          } 
        }
        res.push_back(str);
        first = i;
        curlen = aclen = words[i].length();
      }
      else {
        curlen += (words[i].length() + 1);
        aclen += words[i].length();
      }
    }
    string str;
    for (int i = first; i < words.size(); ++i) {
      str += words[i];
      if (str.length() < maxWidth) str += " "; // curlen == maxWidth
    }
    for (int i = 0; i < maxWidth - curlen - 1; ++i) str += " ";
    res.push_back(str);
    return res;
  }
};