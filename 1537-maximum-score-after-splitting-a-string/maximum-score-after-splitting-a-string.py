class Solution:
    def maxScore(self, s: str) -> int:
        one=0
        zero=0
        tone=0
        tzero=0
        ans=0
        for i in s:
            if i=='0':
                tzero+=1
            else:
                tone+=1
        
        for i in range(len(s)-1):
            if s[i]=='0':
                zero+=1
            else:
                one+=1
            ans=max(ans,zero+(tone-one))

        return ans