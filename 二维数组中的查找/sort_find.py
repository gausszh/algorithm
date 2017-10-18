# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        i, j = len(array) - 1, 0
        while i >= 0 and j < len(array[i]):
            if array[i][j] > target:
                i -= 1
            elif array[i][j] < target:
                j += 1
            else:
                return True
        return False

if __name__ == '__main__':
    s = Solution()
    print s.Find(16,[[]])
