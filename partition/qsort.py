# coding=utf8
from partition import partition


def qsort_r(lt, left, right):
    """递归版快排"""
    p = partition(lt, left, right)
    if p is not None:
        qsort_r(lt, left, p - 1)
        qsort_r(lt, p + 1, right)


def qsort(lt, left, right):
    """非递归版快排"""
    st = [(left, right)]
    while st:
        i, j = st.pop()  # last
        p = partition(lt, i, j)
        if p is not None:
            st.append((i, p - 1))
            st.append((p + 1, j))


if __name__ == '__main__':
    import random
    lt = [random.randint(-2, 10) for a in range(20)]
    print lt
    qsort(lt, 0, len(lt) - 1)
    print lt
