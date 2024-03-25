package main

func main() {
	matrix1, matrix2 := GetMatricesFromTextFile()
	TimeComparison(matrix1, matrix2)
}

// Matrix Multiplication: M1 (m*n) X M2 (n*p) = M3 (m*p)
// Enter the number m: 2500
// Enter the number n: 2500
// Enter the number p: 2500

// Sequential time:  194319 ms
// Concurrent time:  62884 ms
