class MyCalendar {
 private:
 vector<pair<int,int>>v;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        end--;
      //  cout<<"************"<<start<<" "<<end<<"***************"<<endl;
        for(auto it: v){
        //   cout<<it.first<<" "<<it.second<<endl;
            if(((start>= it.first and start<=it.second) || (end>=it.first and end<=it.second)) || 
           ( (it.first>=start and it.first<=end) || (it.second>=start and it.second<=end)))  {
             return false;
            }
        }
        v.push_back({start, end});
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */