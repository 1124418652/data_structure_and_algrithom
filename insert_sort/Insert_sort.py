# -*- coding: utf-8 -*-
from time import time

def insert_sort(list_A):
    for key, value in enumerate(list_A):
        j = key - 1
        while j >= 0  and list_A[j] > value:
            list_A[j+1] = list_A[j]
            j = j - 1
        list_A[j+1] = value

if __name__ == "__main__":
    A = [23,12,4,2,42,122,41]
    B = A[:]
    C = A[:]

    begin = time()
    insert_sort(B)
    end = time()
    print(B, end)

    begin = time()
    C = sorted(C)
    end = time()
    print(C, end - begin)
