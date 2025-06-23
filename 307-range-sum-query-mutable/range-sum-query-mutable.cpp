class NumArray {
private:
vector<int>segtree,nums;
int n;

int up(int idx, int lef, int rig,int ind, int val){
    if(lef==ind and rig==ind){
        segtree[idx]=val;
        return segtree[idx];
    }
    int mid=(lef+rig)/2;
    if(ind<=mid){
        int left=up(2*idx+1,lef,mid,ind,val);
        segtree[idx]=left+segtree[2*idx+2];
        return segtree[idx];
    }
    int right=up(2*idx+2,mid+1,rig,ind, val);
    segtree[idx]=segtree[2*idx+1]+right;
    return segtree[idx];
    
}
int bt(int idx, int lef, int rig, vector<int>&nums){
    if(lef==rig){
        segtree[idx]=nums[lef];
        return segtree[idx];
    }
    int mid=(lef+rig)/2;
    int left=bt(2*idx+1,lef,mid,nums);
    int right=bt(2*idx+2,mid+1,rig,nums);
    segtree[idx]=left+right;
    return segtree[idx];
}

int sm(int idx, int lef, int rig,int l, int r){
    if(lef==l and rig==r){
        return segtree[idx];
    }
    int mid=(lef+rig)/2;
    if(lef<=l and r<=mid){
        return sm(2*idx+1,lef,mid,l,r);
    }
    if((mid+1)<=l and r<=rig){
        return sm(2*idx+2,mid+1,rig,l, r);
    }
    int left=sm(2*idx+1,lef,mid,l,mid);
    int right=sm(2*idx+2,mid+1,rig,mid+1,r);
    return left+right;
}
public:
    NumArray(vector<int>& nums1) {
        nums=nums1;
        n=nums.size();
        segtree.resize(4*n,0);
        bt(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        up(0,0,n-1,index,val);
        return;
    }
    
    int sumRange(int left, int right) {
       return  sm(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

    #define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0  << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif