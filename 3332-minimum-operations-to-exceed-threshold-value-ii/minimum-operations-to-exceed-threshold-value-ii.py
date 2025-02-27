import heapq as hq

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        n=len(nums)
        pq=[]
        for i in nums:
            hq.heappush(pq,i)
        
        if(n<2):
            return pq[0]>=k
        
        cnt=0
        while len(pq)>=2:
            if pq[0]>=k:
                break
            a=hq.heappop(pq)
            b=hq.heappop(pq)
            hq.heappush(pq,min(a,b)*2+max(a,b))
            cnt+=1
            
        
        
        
        return cnt