class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        mp1={}
        mp2={}
        ans=[]
        n=limit+1
        for x, y in queries:
            if x not in mp1:
                mp1[x]=y
                mp2[y]=mp2.get(y,0)+1
            else:
                col=mp1[x]
                mp2[col]-=1
                if mp2[col]==0:
                    del mp2[col]
                mp1[x]=y
                mp2[y]=mp2.get(y,0)+1
            ans.append(len(mp2))


        return ans
        