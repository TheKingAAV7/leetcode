class Solution(object):
    def longestMonotonicSubarray(self, nums):
        ans=1
        n=len(nums)
        cnt=1
        cnt1=1
        for i in range(1,n):
            if nums[i]>nums[i-1]:
                cnt+=1
            else:
                ans=max(cnt,ans)
                cnt=1
                
            if nums[i]<nums[i-1]:
                cnt1+=1
            else:
                ans=max(cnt1,ans)
                cnt1=1
            
        ans=max(ans,max(cnt1,cnt))
        return ans
        

        