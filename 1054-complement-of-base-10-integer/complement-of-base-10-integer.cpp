class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int sz= log2(n)+1;
      for(int i=sz-1;i>=0;i--){
        n^=(1<<i);
      }
      return n;
    }
};