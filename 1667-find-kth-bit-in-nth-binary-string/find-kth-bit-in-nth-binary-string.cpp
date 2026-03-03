class Solution {
public:

    
    char findKthBit(int n, int k) {
        k--;
        function<char(int,int)>f=[&](int n, int k)->char{
            cout<<n<<" "<<k<<endl;
            if(n==1) return '0';
            int len= (1<<n)-1;
            if(k<len/2) return f(n-1,k);
            if(k==len/2) return '1';
            char cur= f(n-1,len-k-1);
            return cur=='0'?'1':'0';
        };

        return f(n,k);

    }
};