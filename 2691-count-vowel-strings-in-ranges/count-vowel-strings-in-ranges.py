class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        v={'a','e','i','o','u'}
        n=len(words)
        pref=[0]*n
        cnt=0
        for i in range(len(words)):
            if words[i][0] in v and words[i][-1] in v:
                cnt+=1
            pref[i]=cnt
        ans=[]
        for it in queries:
            lef=it[0]
            rig=it[1]
            if lef==0:
                ans.append(pref[rig])
            else:
                ans.append(pref[rig]-pref[lef-1])
        

        return ans



                
            
      

        