class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
 long long maskA = 0, maskB = 0; 
    vector<int> result;
    
    for (int i = 0; i < A.size(); ++i) {
        
        maskA |= (1LL << (A[i] - 1)); 
        maskB |= (1LL << (B[i] - 1)); 

       
        long long commonMask = maskA & maskB;
        int commonCount = __builtin_popcountll(commonMask); 

        result.push_back(commonCount); 
    }
    
    return result;
    }
};