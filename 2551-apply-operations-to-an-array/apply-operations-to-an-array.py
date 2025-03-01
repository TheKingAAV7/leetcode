class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n=len(nums)
        for i in range(1,n):
            if nums[i-1]==nums[i]:
                nums[i-1]*=2
                nums[i]=0
        
        pos=0
       # print(nums)
        while pos<n and nums[pos]>0:
            pos+=1

        i=pos
        while i<n:
            if nums[i]>0:
                nums[i],nums[pos]=nums[pos],nums[i]
                pos+=1
            i+=1

        return nums


        