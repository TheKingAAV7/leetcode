class Solution(object):
    def isArraySpecial(self, nums):
        n=len(nums)
        for i in range(1,n):
            if (nums[i-1]&1)^(nums[i]&1)==0:
                return False

        return True
        