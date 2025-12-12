class NumArray {
public:
    vector<int>st,arr;
    int n;

    int query(int idx, int lef, int rig, int l, int r){
        if(lef==l and rig==r) return st[idx];

        int mid= (lef+rig)>>1;
        if(r<=mid) return query(2*idx+1,lef,mid,l,r);
        if((mid+1)<=l) return query(2*idx+2,mid+1,rig,l,r);
        int left= query(2*idx+1,lef,mid,l,mid);
        int right= query(2*idx+2,mid+1,rig,mid+1,r);
        return left+right;
    }

    void up(int idx, int lef, int rig, int i, int val){
        if(lef==rig){
            arr[lef]=val;
            st[idx]=val;
            return;
        }
        int mid=(lef+rig)>>1;
        if(i<=mid) up(2*idx+1,lef,mid,i,val);
        else up(2*idx+2,mid+1,rig,i,val);
        st[idx]= st[2*idx+1] + st[2*idx+2];
        return;
    }

    void build(int idx, int lef, int rig){
        if(lef==rig){
            st[idx]=arr[lef];
            return;
        }
        int mid=(lef+rig)>>1;
        build(2*idx+1,lef,mid);
        build(2*idx+2,mid+1,rig);
        st[idx]=st[2*idx+1] + st[2*idx+2];
        return;
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        arr=nums;
        st.resize(4*n);
        build(0,0,n-1);
    }
    
    void update(int index, int val) {
        up(0,0,n-1,index,val);
        return;
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */