#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {

        /*
        for each range of dist-1, for  2<=i<n-1
        find sum of k-2  minimum elements

        */
        multiset<int>kst,st;
        int n=nums.size();
        int sz= k-2;
        ll sm=0;
        vector<ll>v(n,LLONG_MAX);
        int l=2;
        int i;
        int pos=1;
        int todel=2;
        for(i=2;i<2+dist;i++){
            if(kst.size()<sz){
                kst.insert(nums[i]);
                sm+=nums[i];
            }
            else{
                auto lst= prev(kst.end());
                if(nums[i]<*lst){
                    int tost= *lst;
                    kst.erase(lst);
                    sm-=tost;
                    st.insert(tost);
                    kst.insert(nums[i]);
                    sm+=nums[i];
                }
                else{
                    st.insert(nums[i]);
                }
            }
        }

        // record only if current window has enough elements
        if ((int)(kst.size() + st.size()) >= sz) v[pos] = sm;
        pos++;

        for(int j=i;j<n;j++){
            // delete prev
            int del= nums[todel++];

            auto it= kst.find(del);
            if(it!=kst.end()){
                // erase from kst and promote only if st non-empty
                kst.erase(it);
                sm-=del;
                if(!st.empty()){
                    int tokst= *st.begin();
                    kst.insert(tokst);
                    sm+=tokst;
                    st.erase(st.begin());
                }
            }
            else{
                // erase from st only if found
                auto it1= st.find(del);
                if(it1 != st.end()) st.erase(it1);
            }

            // insert new ele
            int nele= nums[j];

            // if kst isn't full yet, insert directly to avoid prev(kst.end()) on empty
            if(kst.empty() || (int)kst.size() < sz){
                kst.insert(nele);
                sm += nele;
            } else {
                auto lst= prev(kst.end());
                if(nele < *lst){
                    int tost= *lst;
                    kst.erase(lst);
                    sm-=tost;
                    st.insert(tost);
                    kst.insert(nele);
                    sm+=nele;
                }
                else{
                    st.insert(nele);
                }
            }

            // record only if current window has enough elements
            if ((int)(kst.size() + st.size()) >= sz) v[pos] = sm;
            pos++;
        }

        // tail: we've reached the end and can still remove leftmost elements;
        // this produces windows that are shorter than dist (but still valid if size >= sz)
        while(todel < n){
            int del = nums[todel++];

            auto it = kst.find(del);
            if(it != kst.end()){
                kst.erase(it);
                sm -= del;
                if(!st.empty()){
                    int tokst = *st.begin();
                    kst.insert(tokst);
                    sm += tokst;
                    st.erase(st.begin());
                }
            } else {
                auto it1 = st.find(del);
                if(it1 != st.end()) st.erase(it1);
            }

            if ((int)(kst.size() + st.size()) >= sz) v[pos] = sm;
            pos++;
        }

        // compute answer exactly like you did
        ll ans=LLONG_MAX;
        for(int j=1;j<v.size();j++){
            if( v[j]<LLONG_MAX){
                ll curval= v[j]+nums[0]+nums[j];
                ans=min(ans,curval);
            }
        }
        return ans;
    }
};
