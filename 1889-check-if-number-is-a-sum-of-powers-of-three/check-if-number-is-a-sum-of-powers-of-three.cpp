class Solution {
private:
string f(int decimal) {
    if (decimal == 0) return "0";
    string base3 = "";
    while (decimal > 0) {
        base3 += to_string(decimal % 3);
        decimal /= 3;
    }
    reverse(base3.begin(), base3.end()); 
    return base3;
}

public:
    bool checkPowersOfThree(int n) {

        
        string s=f(n);
        if(s.find('2')!=string::npos) return false;
        return true;
    }
};