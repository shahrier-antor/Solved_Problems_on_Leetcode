class MyCalendarTwo:

    def __init__(self):
        self.bookings = SortedDict()

    def book(self, startTime: int, endTime: int) -> bool:
        self.bookings[startTime] = self.bookings.get(startTime,0)+1
        self.bookings[endTime] = self.bookings.get(endTime,0)-1
        totalBookings = 0

        for booking in self.bookings:
            totalBookings+=self.bookings[booking]
            if totalBookings>2:
                self.bookings[startTime]-=1
                self.bookings[endTime]+=1
                if self.bookings[startTime]==0:
                    del self.bookings[startTime]
                if self.bookings[endTime]==0:
                    del self.bookings[endTime]
                return False
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(startTime,endTime)