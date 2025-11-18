class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
      int n=bits.size();
      int i=0;
      while(i<n){
        if(i==n-1){
            
         return bits[i]==0;
        }
        if(bits[i]==1 and bits[i+1]==0){
            i+=2;
        }
        else if(bits[i]==1 and bits[i+1]==1){
            
         i+=2;
        }
        else i++;
      }  
      return false;
      
    }
};