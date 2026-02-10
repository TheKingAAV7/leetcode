class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n=len(nums)
        ans= 0
        for i in range(0,n):
            ev,od= set(),set()
            for j in range(i,n):
                if nums[j]&1:
                    ev.add(nums[j])
                else:
                    od.add(nums[j])
                if len(ev)== len(od):
                    ans=max(ans,j-i+1)
        
        return ans


