# coding=utf8
from partition import partition


def min_k(lt, out, k, left, right):
    st = [(left, right)]
    while st:
        left, right = st.pop()
        p = partition(lt, left, right)
        if p is None:
            return
        if p == k - 1:
            out.extend(lt[left: p + 1])
            return
        elif p > k - 1:
            st.append((left, p - 1))
        else:
            out.extend(lt[left: p + 1])
            st.append((p + 1, right))


if __name__ == '__main__':
    import random
    lt = [random.randint(-2, 10) for a in range(20)]
    print lt
    out = []
    min_k(lt, out, 5, 0, len(lt) - 1)
    print out
    print sorted(lt)
