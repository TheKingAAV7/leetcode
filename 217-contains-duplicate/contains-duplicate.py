class Solution(object):
    def containsDuplicate(self, nums):
        mp={}
        for i in nums:
            if i in mp:
                return True
            else:
                mp[i]=1
        return False