from concurrent.futures import ThreadPoolExecutor, wait
from multiprocessing import Pool


def multiply(arg):
    matrix1, matrix2, result, i, j = arg
    for k in range(len(matrix2)):
        result[i][j] += matrix1[i][k] * matrix2[k][j]


def concurrent_multiplication1(matrix1, matrix2):
    result = [[0 for _ in range(len(matrix2[0]))] for _ in range(len(matrix1))]

    with ThreadPoolExecutor(max_workers=None) as executor:
        futures = [
            executor.submit(multiply, matrix1, matrix2, result, i, j)
            for i in range(len(matrix1))
            for j in range(len(matrix2[0]))
        ]
        wait(futures)


def concurrent_multiplication2(matrix1, matrix2):
    result = [[0 for _ in range(len(matrix2[0]))] for _ in range(len(matrix1))]

    with Pool() as pool:
        args = [
            (matrix1, matrix2, result, i, j)
            for i in range(len(matrix1))
            for j in range(len(matrix2[0]))
        ]
        pool.map(multiply, args)
