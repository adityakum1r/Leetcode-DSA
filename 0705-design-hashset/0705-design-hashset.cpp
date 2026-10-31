class MyHashSet {
public:
    vector<int>myset;
    MyHashSet() {
        
    }
    
    void add(int key) {
       if(!contains(key)){
        myset.push_back(key);
       } 
    }
    
    void remove(int key) {
    for (int i = 0; i < myset.size(); i++) {
        if (myset[i] == key) {
            myset.erase(myset.begin() + i);
            break;
        }
    }
    }
    
    bool contains(int key) {
        for(int i=0;i<myset.size();i++){
            if(myset[i]==key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */