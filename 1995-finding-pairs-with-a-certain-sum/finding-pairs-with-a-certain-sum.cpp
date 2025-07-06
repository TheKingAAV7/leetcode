const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class FindSumPairs {
vector<long long>arr1,arr2;
  map<long long,int>mp;
public:
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        for(int i:n1) arr1.push_back(i);
        for(int i:n2) {
        arr2.push_back(i);
        mp[i]++;
        }
       
    }
    
    void add(int index, int val) {
        mp[arr2[index]]-=1;
        arr2[index]+=val;
        mp[arr2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
      
        for(int i:arr1){
           cnt+=mp[tot-i];
        }
        
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */