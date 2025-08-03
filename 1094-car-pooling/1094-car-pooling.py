class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        passengers = [0]*1002
        for trip in trips:
            passengers[trip[1]]+=trip[0]
            passengers[trip[2]]-=trip[0]
        
        totalPassenger=0
        for passenger in passengers:
            totalPassenger+=passenger
            if totalPassenger>capacity:
                return False
        return True