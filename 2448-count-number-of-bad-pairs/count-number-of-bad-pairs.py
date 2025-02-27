class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n=len(nums)
        mp={}
        ans=0
        tmp=n*(n-1)//2
        for i in range(n):
            x=i-nums[i]
            if x in mp:
                ans+=mp[x]
            mp[x]= mp.get(x,0)+1


        return tmp-ans
            

        