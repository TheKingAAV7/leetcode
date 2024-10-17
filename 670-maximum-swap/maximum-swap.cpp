class Solution {
public:


    int maximumSwap(int num) {

        string temp = to_string(num);
        int n = temp.length();
        vector<pair<char,int>> max_char_to_right(n);
        max_char_to_right[n-1] = {temp[n-1],n-1};
        for(int i = n-2; i >= 0; i--){
            if((temp[i]-'0') > (max_char_to_right[i+1].first-'0')){
                max_char_to_right[i] = {temp[i],i};
             }
             else{
                max_char_to_right[i] = max_char_to_right[i+1];
             }
        }
//9532
        
        // for(auto [one,two] : max_char_to_right){
        //     cout << one << " " << two << endl;
        // }
        
        
        for(int i = 0; i < n; i++){
            if(temp[i] != max_char_to_right[i].first){
                swap(temp[i],temp[max_char_to_right[i].second]);
                break;
            }
        }
        int ans = stoi(temp);
        return ans;

    }
};