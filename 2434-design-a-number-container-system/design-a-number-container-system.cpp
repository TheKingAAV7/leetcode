class NumberContainers {
private:
unordered_map<int,int>mp;
set<pair<int,int>>st;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp.find(index)==mp.end()){
            st.insert({number,index});
            mp[index]=number;
        }
        else{
           int id=index;
           int num=mp[index];
           st.erase({num,id}); 
           mp[index]=number;
           st.insert({number,index});

        }
    }
    
    int find(int number) {
        auto it=st.lower_bound({number,-1});
        if(it==st.end()) return -1;
        if(it->first!=number) return -1;
        return it->second;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */