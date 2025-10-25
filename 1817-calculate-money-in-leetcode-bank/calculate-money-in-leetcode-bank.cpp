class Solution {
public:
    int totalMoney(int n) {
        // 1 2 3 4 5 6 7    2 3 4 5 6 7 8
        int sm=0;
        int mond=0;
        int prev=0;
        for(int i=0;i<n;i++){
            if(i%7==0){
                sm+=(mond+1);
                mond++;
                prev=mond;
            }
            else{
                sm+=(prev+1);
                prev++;
            }

        }
        return sm;
    }
};