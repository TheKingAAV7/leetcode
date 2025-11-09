class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt=0;
        while(num1!=0 and num2!=0){
            if(num2>=num1) num2-=num1;
            else num1-=num2;
            cnt++;
        }
        return cnt;
    }
};