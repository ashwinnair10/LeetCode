class Solution(object):
    def minDifference(self, nums):
        n=len(nums)
        if n<=4:
            return 0
        nums.sort()
        ans=nums[n-1]-nums[0]
        for i in range(4):
            if nums[n+i-4]-nums[i]<ans:
                ans=nums[n+i-4]-nums[i]
        return ans