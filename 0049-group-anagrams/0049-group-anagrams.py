class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashMap = {}

        for string in strs:
            sortedstr = ''.join(sorted(string))
            if sortedstr not in hashMap:
                hashMap[sortedstr] = []
            hashMap[sortedstr].append(string)
        ans = []
        for key, val in hashMap.items():
            ans.append(val)
        return ans
