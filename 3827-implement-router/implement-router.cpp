class Router {

    deque<array<int,3>>dq;
    set<array<int,3>>st;
    unordered_map<int,vector<int>>mp;
    int n;
     int lowerBound(vector<int>& list, int target) {
        return (int)(lower_bound(list.begin(), list.end(), target) - list.begin());
    }

    int upperBound(vector<int>& list, int target) {
        return (int)(upper_bound(list.begin(), list.end(), target) - list.begin());
    }
    public:
    Router(int memoryLimit) {
        n=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        array<int,3> tmp={timestamp,source,destination};
        auto it=st.find(tmp);
        if(it!=st.end()) return false;
        if(dq.size()>=n){
           forwardPacket();
        }
        
        dq.push_back({source,destination,timestamp});
        
        st.insert(tmp);
        mp[destination].push_back(timestamp);
       // for(auto it:st) cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        return true;
    }
    
    vector<int> forwardPacket() {
        if(dq.size()==0) return {};
        array<int,3> ans=dq.front();
        vector<int>res={ans[0],ans[1],ans[2]};
        array<int,3>tmp={ans[2],ans[0],ans[1]};
        auto it=st.find(tmp);
       
        st.erase(it);
        dq.pop_front();
        mp[ans[1]].erase(mp[ans[1]].begin());
     
        return res;
    }
    
    int getCount(int dest, int st, int et) {
        auto it = mp.find(dest);
        if (it == mp.end() || it->second.empty())
            return 0;

        vector<int>& list = it->second;

        int left = lowerBound(list, st);
        int right = upperBound(list, et);

        return right - left;

    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */