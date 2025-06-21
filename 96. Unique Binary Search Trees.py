class Solution(object):
    def numTrees(self, n):
        res = 1
        for i in range(n + 1, 2*n + 1):
            res = res * i
        for i in range(1, n + 1):
            res = res / i
        res = res / (n + 1)
        return res
        
        