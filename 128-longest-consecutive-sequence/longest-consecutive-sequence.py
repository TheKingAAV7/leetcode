class Solution(object):
    def longestConsecutive(self, nums):

        ans=1
        tmp=1
        n=len(nums)
        if n==0:
            return 0
        nums=list(set(nums))
        nums.sort()
        n=len(nums)
        for i in range(1,n):
            if nums[i]==nums[i-1]+1:
                tmp+=1
            else:
                ans=max(ans,tmp)
                tmp=1
            
        ans=max(ans,tmp)
        return ans