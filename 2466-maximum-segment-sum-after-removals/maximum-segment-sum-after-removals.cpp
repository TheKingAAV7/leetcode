#define ll long long
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& q) {
        int n=nums.size();
        vector<ll>pref(n);
        vector<ll>ans;
        set<vector<ll>>st;
        multiset<ll>sms;
        ll sm=0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            pref[i]=sm;
        }   

        sms.insert(sm);
        st.insert({0,n-1,sm});
        for(int x:q){
            auto it=st.lower_bound({x,0,0});
            
            if(it==st.end() || (*it)[0]>x) it--;
               
                ll si=(*it)[0];
                ll ei=(*it)[1];
                ll sum=(*it)[2];
                auto it1 = sms.find(sum);  
                if(it1!=sms.end())
                 sms.erase(it1);
                // if si==x and ei==x

                if(si==x and ei==x){
                    st.erase(it);
                   // sms.erase(sum);
                }
                else if(si==x || ei==x){
                    if(si==x){
                     //   sms.erase(sum);
                        ll ns=si+1;
                        ll ne=ei;
                        ll newsum=pref[ne]-pref[ns]+nums[ns];
                        st.erase(it);
                        st.insert({ns,ne,newsum});
                        sms.insert(newsum);
                      
                    }
                    else{
                        //sms.erase(sum);
                        ll ns=si;
                        ll ne=ei-1;
                        ll newsum=pref[ne]-pref[ns]+nums[ns];
                        st.erase(it);
                        st.insert({ns,ne,newsum});
                        sms.insert(newsum); 
                    }
                }
                else{
                 
                // int si=(*it)[0];
                // int ei=(*it)[1];
                // int sum=(*it)[2];
                st.erase(it);
               // sms.erase(sum);
                
                ll lsi=si;
                ll lei=x-1;
                ll rsi=x+1;
                ll rei=ei;
                ll lefsm=pref[lei]-pref[lsi]+nums[lsi];
                ll rigsm=pref[rei]-pref[rsi]+nums[rsi];
                
                st.insert({lsi,lei,lefsm});
                st.insert({rsi,rei,rigsm});
                sms.insert(lefsm);
                sms.insert(rigsm);
                }
                
                
            // for(auto aa:sms) cout<<aa<<" ";
            // cout<<endl;
            if(sms.empty()) ans.push_back(0);
            else ans.push_back(*sms.rbegin());

        }
        return ans;
        
    }   
};