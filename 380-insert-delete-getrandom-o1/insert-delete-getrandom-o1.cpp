class RandomizedSet {
unordered_map<int,int>mp;
vector<int>v;
public:
    RandomizedSet() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        v.push_back(val);
        mp[v.back()]=v.size()-1;
       // mp.erase(v.back());
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        int last_ele=v.back();
        v.pop_back();
        v.push_back(val);
        int idx=mp[val];
        v[idx]=last_ele;
        mp[last_ele]=idx;
        v.pop_back();
        mp.erase(val);
        return true;
        
    }
    
    int getRandom() {
      return v[rand()%v.size()];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */