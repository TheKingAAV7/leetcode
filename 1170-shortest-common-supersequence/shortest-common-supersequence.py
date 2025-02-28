class Solution:
    def shortestCommonSupersequence(self, s: str, t: str) -> str:
        n=len(s)
        m=len(t)
        dp=[[0]*m for i in range(n)]
        for i in range(n):
            for j in range(m):
                if s[i]==t[j]:
                    if i-1>=0 and j-1>=0:
                        dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j])
                    else:
                        dp[i][j]=max(dp[i][j],1)
                
                if i-1>=0:
                        dp[i][j]=max(dp[i][j],dp[i-1][j])
                if j-1>=0:
                        dp[i][j]=max(dp[i][j],dp[i][j-1])
        
        
        i1=n-1
        j1=m-1
        v1=[]
        v2=[]
        while i1>=0 and j1>=0:
            if s[i1]==t[j1]:
                v1.append(i1)
                v2.append(j1)
                i1-=1
                j1-=1
            else:
                if i1-1>=0 and dp[i1-1][j1]==dp[i1][j1]:
                    i1-=1
                else:
                    j1-=1
            
        v1=list(reversed(v1))
        v2=list(reversed(v2))
        lef=""
        rig=""
        if len(v1)!=0:
            for i in range(v1[0]):
                lef+=s[i]
            for i in range(v2[0]):
                lef+=t[i]
            
            l=v1[0]
            r=v2[0]
            lef+=s[v1[0]]

            for i in range(1,len(v1)):
                pos1=v1[i]
                pos2=v2[i]
                while l+1<pos1:
                    lef+=s[l+1]
                    l+=1
                while r+1<pos2:
                    lef+=t[r+1]
                    r+=1
                lef+=s[pos1]
                l=pos1
                r=pos2

            for i in range(v1[-1]+1,n):
                rig+=s[i]
            for i in range(v2[-1]+1,m):
                rig+=t[i]
        
        else:
            ans=""
            for ch in s:
                ans+=ch
            for ch in t:
                ans+=ch
            return ans
                
        
        return lef+rig