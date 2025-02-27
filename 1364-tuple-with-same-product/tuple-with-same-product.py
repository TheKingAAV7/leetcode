class Solution(object):
    def tupleSameProduct(self, nums):
        n=len(nums)
        mp={}
        
        ans=0
        for i in range(n):
            for j in range(i+1,n):
                sm=nums[i]*nums[j]
                mp[sm]=mp.get(sm,0)+1


        for x in mp:
            if mp[x]>1:
                tmp=(mp[x]*(mp[x]-1))/2
                ans+=(tmp*8)

        return ans

        