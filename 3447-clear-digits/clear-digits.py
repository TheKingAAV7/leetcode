class Solution:
    def clearDigits(self, s: str) -> str:
        st=[]
        n=len(s)
        for i in range(n):
            if s[i]>='0' and s[i]<='9':
                st.pop()
            else:
                st.append(s[i])

        
        return ''.join(st)