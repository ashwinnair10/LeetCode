class Solution(object):
    def numWaterBottles(self, n, e):
        drink=n
        empty=n
        while empty>=e:
            a=empty/e
            empty-=e*a
            drink+=a
            empty+=a
        return drink