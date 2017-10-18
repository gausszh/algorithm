# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表

    def binary_search(self, target, lt):
        first, end = 0, len(lt) - 1
        while first <= end:
            mid = (first + end) // 2
            if lt[mid] == target:
                return True
            elif lt[mid] < target:
                first = mid + 1
            else:
                end = mid - 1

    def Find(self, target, array):
        # write code here
        for lt in array:
            if self.binary_search(target, lt):
                return True

if __name__ == '__main__':
    s = Solution()
    print s.Find(7, [[1, 2, 8, 9], [2, 4, 9, 12], [4, 7, 10, 13], [6, 8, 11, 15]])
