class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
         int n=pushed.size(),m=popped.size();
         if(n!=m) return false;
         set<int>st;
         stack<int>v;
         int pos2=0,pos1=0;
         while(pos2<n){
            while(pos1<n and st.find(popped[pos2])==st.end()){
                st.insert(pushed[pos1]);
                v.push(pushed[pos1]);
                pos1++;

            }
            if(st.find(popped[pos2])==st.end()) return false;
            if(v.top()==popped[pos2]){
                st.erase(v.top());
                v.pop();
                pos2++;
                if(pos2==n) return true;
            }
            else return false;
         }
        
        return false;
    }
};