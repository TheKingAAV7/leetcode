class CustomStack {
vector<int>v;
int n=0;
public:
    CustomStack(int maxSize) {
       n=maxSize; 
    }
    
    void push(int x) {
        if(v.size()==n) return;
        v.push_back(x);
        return;
    }
    
    int pop() {
        if(v.empty()) return -1;
        int tmp=v.back();
        v.pop_back();
        return tmp;        
    }
    
    void increment(int k, int val) {
        int l=v.size();
        for(int i=0;i<min(k,l);i++)v[i]+=val;
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */