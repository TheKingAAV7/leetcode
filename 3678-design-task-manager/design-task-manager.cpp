class TaskManager {
public:  // , 2 102 8, ,  4 104 5
    map<int,set<pair<int,int>>>mp;
    map<int,int>tp;
    TaskManager(vector<vector<int>>& tasks) {
        // priority, taskid, userid
        for(auto it:tasks){
         mp[it[2]].insert({it[1],it[0]});
         tp[it[1]]=it[2];
        }


    }
    //tid is unq
    void add(int userId, int taskId, int prio) {
        mp[prio].insert({taskId,userId});
        tp[taskId]=prio;

        // for(auto it:mp){
        //     cout<<it.first<<" ";
        //     for(auto i:it.second) cout<<i.first<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    
    void edit(int taskId, int np) {
        int prepri=tp[taskId];
        // for(auto it:mp[prepri]) cout<<it.first<<" "<<it.second<<"l ";
        // cout<<endl;
        auto it=mp[prepri].lower_bound({taskId,0});
        if(it!=mp[prepri].end()){
           
        int uid= (*it).second;
        mp[prepri].erase(it);
        if(mp[prepri].size()==0) mp.erase(prepri);
        mp[np].insert({taskId,uid});
        tp[taskId]=np;
        }
        //  for(auto it:mp){
        //     cout<<it.first<<" ";
        //     for(auto i:it.second) cout<<i.first<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        
    }
    
    void rmv(int taskId) {
      int pri=tp[taskId];
      auto it=mp[pri].lower_bound({taskId,0});
      if(it!=mp[pri].end()){
        mp[pri].erase(it);
        if(mp[pri].size()==0) mp.erase(pri);
        tp.erase(taskId);
      }
    }
    
    int execTop() {
        if(mp.size()==0) return -1;
        int lst= mp.rbegin()->first;
        auto it1=prev(mp[lst].end());
        int tid=it1->first;
        int uid=it1->second;
        mp[lst].erase({tid,uid});
        if(mp[lst].size()==0) mp.erase(lst);
        tp.erase(tid);
        return uid;

    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */