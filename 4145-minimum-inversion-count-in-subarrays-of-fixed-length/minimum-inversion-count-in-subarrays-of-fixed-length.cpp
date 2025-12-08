#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>





using namespace std;

#define ll long long


namespace __gnu_pbds{
    typedef tree<int,
            null_type,
            less_equal<int>,
            rb_tree_tag,
            tree_order_statistics_node_update> ordered_set;
}


using namespace __gnu_pbds;



/*

RULES:

1) Read the problem CLEARLY.
2) Read AGAIN.
3) DO NOT jump on coding.
4) Prepare a SOLUTION
5) Verify Once/Twice/Thrice
6) Submit.


*/

namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}



void Insert(ordered_set &s,int x){ //this function inserts one more occurrence of (x) into the set.

     s.insert(x);

}


bool Exist(ordered_set &s,int x){ //this function checks weather the value (x) exists in the set or not.

     if((s.upper_bound(x))==s.end()){
        return 0;
     }
     return ((*s.upper_bound(x))==x);

}


void Erase(ordered_set &s,int x){ //this function erases one occurrence of the value (x).

     if(Exist(s,x)){
        s.erase(s.upper_bound(x));
     }

}


int FirstIdx(ordered_set &s,int x){ //this function returns the first index of the value (x)..(0 indexing).

    if(!Exist(s,x)){
        return -1;
    }
    return (s.order_of_key(x));

}


int Valuex(ordered_set &s,int idx){ //this function returns the value at the index (idx)..(0 indexing).

   return (*s.find_by_order(idx));

}


int LastIdx(ordered_set &s,int x){ //this function returns the last index of the value (x)..(0 indexing).

    if(!Exist(s,x)){
        return -1;
    }
    if(Valuex(s,(int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return FirstIdx(s,*s.lower_bound(x))-1;

}


int Count(ordered_set &s,int x){ //this function returns the number of occurrences of the value (x).

     if(!Exist(s,x)){
        return 0;
     }
     return LastIdx(s,x)-FirstIdx(s,x)+1;

}


void Clear(ordered_set &s){ //this function clears all the elements from the set.

     s.clear();

}


int Size(ordered_set &s){ //this function returns the size of the set.

     return (int)(s.size());

}





class Solution {
public:
    long long minInversionCount(vector<int>& arr, int k) {
        int n=arr.size();
        ordered_set s;


ll ans=0;
for(int i=0;i<k;i++){
    s.insert(arr[i]);
    int m=s.size();
    int idx= LastIdx(s,arr[i]);
    ans+=(m-idx-1);
}

ll res=ans;


// for(int i:s ) cout<<i<< " ";
//     cout<<endl;

for(int i=k;i<n;i++){
    int tormv= arr[i-k];
  
    
    // tormv -> how many elements are less than this..
    
    int id1= FirstIdx(s,tormv);
    int cnt1= (id1);
    ans-=cnt1;
    Erase(s,tormv);
    s.insert(arr[i]);
    int m=s.size();
    int idx= LastIdx(s,arr[i]);
    //cout<<cnt1<<" sdf "<<(m-idx-1)<<endl;
    ans+=(m-idx-1);
    
    res= min(res,ans);
    //   cout<<tormv<<" s "<<arr[i]<<endl;
    // for(int i:s) cout<<i<<" ";
    //     cout<<endl;
}


 return res;


    }
        
};