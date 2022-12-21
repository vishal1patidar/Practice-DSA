class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto x : nestedList) {
            makeFlat(x);
        }
    }
    
    int next() {
        return flat[i++];
    }
    
    bool hasNext() {
        return i < flat.size();
    }
    
private:
    void makeFlat(NestedInteger x) {
        if (x.isInteger()) {
            flat.push_back(x.getInteger());
        }
        else {
            for (auto y : x.getList())
                makeFlat(y);
        }
    }
    
    vector<int> flat;
    int i = 0;
};