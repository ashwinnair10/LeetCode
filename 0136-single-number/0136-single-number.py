class Solution(object):
    def singleNumber(self, nums):
        s=0
        for i in nums:
            s=s^i
        return s
        