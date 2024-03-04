import random

fileName = "Input.txt"
count = 0


def create_random_matrix(rows, columns):
    matrix = []
    for _ in range(rows):
        matrix.append([])
        for _ in range(columns):
            matrix[-1].append(random.randint(0, 1000))
    return matrix


def add_matrix_to_text_file(matrix):
    global count
    count += 1
    with open(fileName, "a") as file:
        for row in matrix:
            file.write(" ".join(map(str, row)) + "\n")
        if count == 1:
            file.write("\n")


def main():
    print("Matrix Multiplication: M1 (m*n) X M2 (n*p) = M3 (m*p)")

    m = int(input("Enter the number m: "))
    n = int(input("Enter the number n: "))
    p = int(input("Enter the number p: "))

    matrix1 = create_random_matrix(m, n)
    add_matrix_to_text_file(matrix1)
    matrix2 = create_random_matrix(n, p)
    add_matrix_to_text_file(matrix2)


if __name__ == "__main__":
    main()
