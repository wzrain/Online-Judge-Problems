class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand((unsigned)time(NULL)); 
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int idx = vec.size();
        vec.push_back(val);
        bool res = false;
        if (idxes.find(val) == idxes.end()) res = true;
        idxes[val].insert(idx);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (idxes.find(val) == idxes.end()) return false;
        int idx = *(idxes[val].begin());
        idxes[val].erase(idx);
        if (idxes[val].empty()) idxes.erase(val);
        if (idx != vec.size() - 1) {
            int last = vec.back(), lastidx = vec.size() - 1;
            idxes[last].erase(lastidx);
            swap(vec[idx], vec[lastidx]);
            idxes[last].insert(idx);
        }
        vec.pop_back();
        return true;
     }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int idx = rand() % (vec.size());
        return vec[idx];
    }
private:
    vector<int> vec;

    // The reason why using hash table instead of vector is that when an element is deleted, the last element 
    // will be swapped to that place, which makes the idxes[last] vector not sorted anymore. So the next 
    // time when we try to delete another element, we don't know where the last idx (vec.size() - 1) lies 
    // in the idxes[last] vector (because it's not necessarily the idxes[last].back()).
    // Another solution is to track the indexes of idxes[val] along with vec (so the elements in vec store 
    // the val as well as its index in the idxes[val]). So when deleting an element val, get its idx by idxes
    // [val].back(), let the vec[idx] = {vec.back().first, vec.back().second}, idxes[vec.back().first]
    // [vec.back().second] = idx (here we can use vec.back().second to directly find the corresponding 
    // index without worring about the order; vec.back().second is not necessarily idxes[last].back() because 
    // idxes[last] is ordered by time, while newer elements might be swapped to front so indexes after 
    // last might be smaller).
    unordered_map<int, unordered_set<int>> idxes;
    
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */