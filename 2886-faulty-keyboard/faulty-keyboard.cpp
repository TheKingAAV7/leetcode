class Solution {
public:
    string finalString(string s) {
        // I have seen the solution
        deque<char>dq;
        bool flip=false;
        for(auto ch:s){
            if(ch=='i') flip=!flip;
            else{
                if(flip){
                    dq.push_front(ch);
                }
                else dq.push_back(ch);
            }
        }
        if(flip) return string(rbegin(dq),rend(dq));
        return string(begin(dq),end(dq));
    }
};