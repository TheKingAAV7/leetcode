class Solution:
    
    
    def maximumSum(self, nums: List[int]) -> int:
        def f(num):
            sm=0
            while(num>0):
                sm+=(num%10)
                num//=10
            return sm
        
        mp={}
        ans=-1
        n=len(nums)

        for i in range(n):
            x=f(nums[i])
          #  print(x)
            if x in mp:
                ans=max(ans,nums[i]+mp[x])
                mp[x]=max(mp[x],nums[i])
            else:
                mp[x]=nums[i]

        
        return ans

        