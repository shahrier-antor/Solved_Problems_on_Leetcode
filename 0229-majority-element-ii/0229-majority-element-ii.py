class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        freq = defaultdict(int)
        for num in nums:
            freq[num]+=1
        answer=[]
        for key, val in freq.items():
            if(val> len(nums)//3):
                answer.append(key)
        return answer

        