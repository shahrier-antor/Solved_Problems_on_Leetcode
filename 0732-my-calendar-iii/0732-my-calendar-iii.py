class MyCalendarThree:

    def __init__(self):
        self.bookings = SortedDict()

    def book(self, startTime: int, endTime: int) -> int:
        ans=float("-inf")
        self.bookings[startTime] = self.bookings.get(startTime,0)+1
        self.bookings[endTime] = self.bookings.get(endTime,0)-1
        totalBookings = 0
        for booking in self.bookings:
            totalBookings += self.bookings[booking]
            ans = max(ans, totalBookings)
        return ans


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(startTime,endTime)