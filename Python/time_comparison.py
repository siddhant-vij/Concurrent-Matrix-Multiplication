import time
from concurrent_multiply import concurrent_multiplication1, concurrent_multiplication2
from sequential_multiply import sequential_multiplication


def time_comparison(matrix1, matrix2):
    start = time.time()
    sequential_multiplication(matrix1, matrix2)
    end = time.time()
    print("Sequential:", end - start)

    start = time.time()
    concurrent_multiplication1(matrix1, matrix2)
    end = time.time()
    print("Using concurrent.futures:", end - start)

    start = time.time()
    concurrent_multiplication2(matrix1, matrix2)
    end = time.time()
    print("Using multiprocessing:", end - start)
