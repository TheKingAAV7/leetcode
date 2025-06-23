class NumArray {
private:
    vector<int> segtree;
    vector<int>nums;
    int n;
    int bt(int idx, int lef, int rig, vector<int>& nums) {
        if (lef == rig) {
            segtree[idx] = nums[lef];
            return segtree[idx];
        }
        int mid = (lef + rig) / 2;
        int left = bt(2 * idx + 1, lef, mid, nums);
        int right = bt(2 * idx + 2, mid + 1, rig, nums);
        segtree[idx] = left + right;
        return segtree[idx];
    }

    int query(int idx, int lef, int rig, vector<int>& nums, int l, int r) {
        if (lef == l and rig == r) {
            return segtree[idx];
        }
        int mid = (lef + rig) / 2;
        // three cases
        if (lef <= l and r <= mid) {
            return query(2 * idx + 1, lef, mid, nums, l, r);
        } else if ((mid + 1) <= l and r <= rig) {
            return query(2 * idx + 2, mid + 1, rig, nums, l, r);
        }
        int left = query(2 * idx + 1, lef, mid,nums,l,mid);
        int right= query(2 * idx + 2, mid + 1, rig,nums, mid+1,r);
        return left+right;
    }

public:
    NumArray(vector<int>& nums1) {
         n = nums1.size();
         nums=nums1;
        segtree.resize(4 * n, 0);
        bt(0, 0, n - 1, nums);
    }

    int sumRange(int left, int right) {
        return query(0,0,n-1,nums,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */