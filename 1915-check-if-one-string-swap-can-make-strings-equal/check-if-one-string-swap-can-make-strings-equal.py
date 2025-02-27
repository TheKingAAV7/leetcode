class Solution(object):
    def areAlmostEqual(self, s1, s2):
        s=""
        t=""
        n=len(s1)
        for i in range(n):
            if s1[i]!=s2[i]:
                s+=s1[i]
                t+=s2[i]
            
        if len(s)==0:
            return True
        if len(s)!=2:
            return False
        
        print(s)
        rev=''.join(reversed(t))
        return True if rev==s else False
        
        