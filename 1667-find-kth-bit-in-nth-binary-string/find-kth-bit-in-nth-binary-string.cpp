class Solution {



string rev(string t){
	for(int i=0;i<t.length();i++){
     if(t[i]=='1')
     	t[i]='0';
     else t[i]='1';
	}
	reverse(t.begin(), t.end());
	
	
	
	
	return t;
	
	
	
	
	
	
	
}

string f(int n){
	string ans="";
	if(n==1){
		return "0";
	}
	string t=f(n-1);
	string op=rev(t);
	ans=t+"1"+op;
	return ans;
}
public:
    char findKthBit(int n, int k) {
        string ans=f(n);
        return ans[k-1];
    }
};