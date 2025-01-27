class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        sm=sum(nums)
        cur_sm=0
        ans=0
        for i in range(len(nums)-1):
            cur_sm+=nums[i]
            rig_sm=(sm-cur_sm)
            if cur_sm>=rig_sm:
                ans+=1
        


        return ans