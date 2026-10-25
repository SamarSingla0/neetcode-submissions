
class MyHashMap {
    unordered_map<int, int> mpp;

public:
    MyHashMap() {
    }

    void put(int key, int value) {
        mpp[key] = value;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            return mpp[key];
        }
        return -1;
    }

    void remove(int key) {
        mpp.erase(key);
    }
};
