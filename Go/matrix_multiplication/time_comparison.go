package main

import (
	"fmt"
	"time"
)

func TimeComparison(matrix1 [][]int, matrix2 [][]int) {
	startTime := time.Now()
	SequentialMultiply(matrix1, matrix2)
	endTime := time.Now()
	fmt.Println("Sequential time: ", endTime.Sub(startTime).Milliseconds(), "ms")

	startTime = time.Now()
	ConcurrentMultiply(matrix1, matrix2)
	endTime = time.Now()
	fmt.Println("Concurrent time: ", endTime.Sub(startTime).Milliseconds(), "ms")
}
