class Solution(object):
    def passThePillow(self, n, time):
        k=time/(n-1)
        l=time%(n-1)
        if k%2==0:
            return l+1
        return n-l
        