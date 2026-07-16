class LRUCache {
public:
    vector<pair<int, int>> vec;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        for(int i = 0 ; i < vec.size() ; i++) {
            if(vec[i].first == key) {
                pair<int, int> temp = vec[i];
                vec.erase(vec.begin()+i);
                vec.push_back(temp);
                return temp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0 ; i < vec.size() ; i++) {
            if(vec[i].first == key) {
                vec.erase(vec.begin() + i);
                vec.push_back({key, value});
                return ;
            }
        }
        if(vec.size() == capacity) {
           vec.erase(vec.begin());
        }
        vec.push_back({key, value});
    }
};
