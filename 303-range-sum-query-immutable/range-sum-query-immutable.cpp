class NumArray {
private:
    vector<int> segtree;
    vector<int>nums;
    int n;
   int bt(int i, int lef, int rig ){
    if(lef==rig){
        segtree[i]=nums[lef];
        return segtree[i];
    }

    int mid=(lef+rig)/2;
    int left=bt(2*i+1,lef,mid);
    int right=bt(2*i+2,mid+1,rig);
    segtree[i]=left+right;
    return segtree[i];
   }

    int query(int i, int lef, int rig, int l, int r ){
        if(lef==l and rig==r) return segtree[i];
        int mid=(lef+rig)/2;
        if(r<=mid){
            return query(2*i+1,lef, mid, l, r);
        }
        else if((mid+1)<=l){
            return query(2*i+2,mid+1,rig,l,r);
        }
        int left= query(2*i+1,lef, mid, l,mid);
        int right=query(2*i+2,mid+1, rig,mid+1, r);
        return left+right;
    }

public:
    NumArray(vector<int>& nums1) {
         n = nums1.size();
         nums=nums1;
        segtree.resize(4 * n, 0);
        bt(0, 0, n - 1);
    }

    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */