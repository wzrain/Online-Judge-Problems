// O(n^2) solution
class OrderedStream {
public:
    OrderedStream(int n) {
        total = n;
        next = 0;
        chunk = vector<string>(n, "");
        // lf = vector<int>(n, -1);
        rt = vector<int>(n, -1);
    }
    
    vector<string> insert(int id, string value) {
        id--;
        chunk[id] = value;
        rt[id] = (id == total - 1 || rt[id + 1] == -1) ? id : rt[id + 1];
        for (int i = id - 1; i >= 0; --i) {
            if (rt[i] == -1) break;
            rt[i] = rt[id];
        }
        if (id > next) {
            return {};
        }
        next = rt[id] + 1;
        return vector<string>(chunk.begin() + id, chunk.begin() + rt[id] + 1);
    }
private:
    int total, next;
    vector<string> chunk;
    vector<int> rt;
};

// O(n) solution
// not necessary to traverse back everytime to update 
// something related to information that can be 
// calculated when traversing along the way.
// just update the "next" pointer with iteration rather
// than using a rt array
class OrderedStream {
public:
    OrderedStream(int n) {
        total = n;
        next = 0;
        chunk = vector<string>(n, "");
    }
    
    vector<string> insert(int id, string value) {
        id--;
        chunk[id] = value;
        vector<string> res;
        if (id == next) {
            while (next < total && chunk[next].length() > 0) {
                res.push_back(chunk[next++]);
            } 
        }
        return res;
    }
private:
    int total, next;
    vector<string> chunk;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */