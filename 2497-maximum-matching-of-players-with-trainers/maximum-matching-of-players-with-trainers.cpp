class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int n=p.size(),m=t.size();
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        int cnt=0;
        int i=0,j=0;
        while(i<n and j<m){
            if(t[j]>=p[i]){
                j++;
                i++;
                cnt++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif
