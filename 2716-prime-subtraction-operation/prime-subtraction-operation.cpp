class Solution {
private:
bool isPrime(int n){
    if(n==1) return false;
if(n==2) return true;
for(int i=2;i*i<=n;i++){
    if(n%i==0) return false;
    
}
return true;

}
public:
    bool primeSubOperation(vector<int>& nums) {
        int n= nums.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty() || st.top()>nums[i]) st.push(nums[i]);
            else{
                int tmp=st.top();
                bool f=false;
                for(int j=st.top()-1;j>=1;j--){
                  int diff= nums[i]-j;
                  if(isPrime(diff)){
                    f=true;
                    st.push(j);
                    break;
                  }
                }
                if(!f) return false;
            }
        }
        return true;
    }
};