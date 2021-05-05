# coding=utf8


def partition(lt, left, right):
    """
    我们用left下标的数字作为基准，从小到大排 返回重排后基准的下标
    @param {list} lt, 待排序的数组
    @param {int} left, 待排序的数组左下标 【包含】
    @param {int} right, 待排序的数组右下标【包含】
    @return  重排后基准的下标
    """
    if left >= right:
        return None
    pivot = lt[left]
    i, j = left + 1, right
    while True:
        while lt[i] < pivot and i < right:
            i += 1
        while lt[j] >= pivot and j > left:
            j -= 1
        if i < j:
            lt[i], lt[j] = lt[j], lt[i]
        else:
            lt[j], lt[left] = lt[left], lt[j]
            return j
