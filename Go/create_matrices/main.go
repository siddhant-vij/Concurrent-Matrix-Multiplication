package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewReader(os.Stdin)
	fmt.Println("Matrix Multiplication: M1 (m*n) X M2 (n*p) = M3 (m*p)")

	fmt.Print("Enter the number m: ")
	mStr, err := scanner.ReadString('\n')
	if err != nil {
		panic(err)
	}
	mInt, err := strconv.Atoi(strings.TrimSpace(mStr))
	if err != nil {
		panic(err)
	}

	fmt.Print("Enter the number n: ")
	nStr, err := scanner.ReadString('\n')
	if err != nil {
		panic(err)
	}
	nInt, err := strconv.Atoi(strings.TrimSpace(nStr))
	if err != nil {
		panic(err)
	}

	fmt.Print("Enter the number p: ")
	pStr, err := scanner.ReadString('\n')
	if err != nil {
		panic(err)
	}
	pInt, err := strconv.Atoi(strings.TrimSpace(pStr))
	if err != nil {
		panic(err)
	}

	matrix1 := createMatrix(mInt, nInt)
	addMatrixToFile(matrix1)
	matrix2 := createMatrix(nInt, pInt)
	addMatrixToFile(matrix2)
}
