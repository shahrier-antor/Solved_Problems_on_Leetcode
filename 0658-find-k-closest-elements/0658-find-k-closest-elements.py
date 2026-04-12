class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        pq = []
        
        for num in arr:
            heapq.heappush(pq, (-abs(num - x), -num))
        while(len(pq)>k):
            heapq.heappop(pq)
        
        ans = []
        while(pq):
            ans.append(-pq[0][1])
            heapq.heappop(pq)
        return sorted(ans)



