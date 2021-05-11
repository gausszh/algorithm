# coding=utf8
import random

def p(lt, start, end):
    """
    start end 包含关系， 
    """
    base = lt[start]
    i = start + 1
    j = end
    while 1:
        while i < end and lt[i] < base:
            i += 1
        while j > start and lt[j] >= base:
            j -= 1
        if i < j:
            lt[i], lt[j] = lt[j], lt[i]
        else:
            break
    lt[start], lt[j] = lt[j], lt[start]
    return j

def quicksort(lt):
    if not lt or len(lt) <= 1:
        return lt
    st = [(0, len(lt) - 1)]
    while st:
        start, end = st.pop()
        if start < end:
            idx = p(lt, start, end)
            if idx is not None:
                st.append((start, idx - 1))  # 扣除掉这个比较的基值,可以不用参与以后的排序的
                st.append((idx + 1, end))

if __name__ == '__main__':
    lt = list(range(10))
    random.shuffle(lt)
    quicksort(lt)
    for i in range(1, len(lt)):
        if lt[i] < lt[i - 1]:
            print 'error'
            break
    else:
        print 'ok'
        print lt
