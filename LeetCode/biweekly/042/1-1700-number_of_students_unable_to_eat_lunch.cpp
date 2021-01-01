// There is actually no need to calculate the numbers of sandwiches, because it will be implicitly done when we 
// traverse through the sandwich stack, so even if the number of one type of sandwich is really small, we can 
// find out when we run out of students of the other type. Therefore we can just treat the queue as a "set" 
// and if students of the type at the stack top have run out, the process will be over.
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int sz = students.size();
        vector<int> st(2, 0);
        for (int i = 0; i < sz; ++i) {
            st[students[i]]++;
        }
        
        int idx = 0;
        while (idx < sz && st[sandwiches[idx]]--) idx++;
        return sz - idx;
    }
};