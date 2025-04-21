class Solution(object):
    def productExceptSelf(self, nums):
        pos=-1
        n=len(nums)
        cnt=0
        prod=1
        for i in range(0,n):

            if nums[i]==0:
                pos=i
                cnt+=1
            else:
                prod*=nums[i]
        
        if cnt>=2:
            return [0]*n
        
        if cnt==1:

            ans=[0]*n
            ans[pos]=prod
            return ans

        ans=[]
        for i in nums:
            ans.append(prod/i)
        return ans

        
        
            

        