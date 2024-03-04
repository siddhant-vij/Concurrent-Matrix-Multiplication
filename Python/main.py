from time_comparison import time_comparison


matrix1 = []
matrix2 = []
dim = []
fileName = "Input.txt"


def get_matrix_dimensions():
    with open(fileName, "r") as file:
        dim = [0, 0, 0]
        count = 0
        matrix1_reading = True
        for line in file:
            row = line.split()
            if matrix1_reading:
                if dim[1] == 0:
                    dim[1] = len(row)
                dim[0] += 1
                if len(row) == 0:
                    matrix1_reading = False
                    dim[0] -= 1
            else:
                if dim[2] == 0:
                    dim[2] = len(row)
                count += 1

        if dim[0] == 0:
            raise Exception(
                "This is a matrix multiplication - not a scalar. Need more elements in matrix form for the first matrix.")
        if count != dim[1]:
            raise Exception(
                "The number of rows in the second matrix does not match the number of columns in the first matrix. Multiplication is not possible.")
    return dim


def get_matrices_from_text_file():
    dim = get_matrix_dimensions()
    matrix1 = [[0 for _ in range(dim[1])]
               for _ in range(dim[0])]
    matrix2 = [[0 for _ in range(dim[2])]
               for _ in range(dim[1])]

    with open(fileName, "r") as file:
        count = 0
        matrix1_reading = True
        for line in file:
            row = line.split()
            if matrix1_reading:
                if count != dim[0]:
                    for i in range(len(row)):
                        matrix1[count][i] = int(row[i])
                count += 1
                if len(row) == 0:
                    matrix1_reading = False
                    count = 0
            else:
                for i in range(len(row)):
                    matrix2[count][i] = int(row[i])
                count += 1
    return matrix1, matrix2


def run():
    matrix1, matrix2 = get_matrices_from_text_file()
    time_comparison(matrix1, matrix2)


if __name__ == "__main__":
    run()

# M1: 1000 * 1000
# M2: 1000 * 1000
# Sequential:  244.34002041816711
# Using concurrent.futures:  355.02501487731934
# Using multiprocessing: 54.10430383682251
