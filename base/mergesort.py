#coding=utf8
import random


def merge(lt, s, mid, t):
    # 合并2个已排好序的数组
    # 这2个数组是 [s-mid] [mid+1 - t]  下标都是包含的意义
    t = min(t, len(lt) - 1)
    temp = []
    i = s
    j = mid + 1
    while i <= mid and j <= t:
        if lt[i] < lt[j]:
            temp.append(lt[i])
            i += 1
        else:
            temp.append(lt[j])
            j += 1
    if i > mid:
        temp.extend(lt[j: t + 1])
    else:
        temp.extend(lt[i: mid + 1])
    lt[s: t + 1] = temp


def mergesort(lt):
    if not lt:
        return lt
    step = 0
    while step + 1 < len(lt):
        s1 = 0
        # 从子数组只有一个元素开始，两两合并
        while s1 + step + 1 < len(lt):  # s1 + step + 1也就是第二组的下标开始，起码要第二组数据非空才可以合并嘛
            merge(lt, s1, s1 + step, s1 + 2 *step + 1)
            s1 = s1 + 2*step + 2
        step = step * 2 + 1


if __name__ == '__main__':
    lt = list(range(11))
    random.shuffle(lt)
    mergesort(lt)
    for i in range(1, len(lt)):
        if lt[i] < lt[i - 1]:
            print 'error'
            break
    else:
        print 'ok'
        print lt
