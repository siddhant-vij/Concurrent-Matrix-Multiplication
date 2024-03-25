package main

import "math/rand"

func createMatrix(mInt, nInt int) [][]int {
	result := make([][]int, mInt)

	for i := 0; i < mInt; i++ {
		result[i] = make([]int, nInt)
		for j := 0; j < nInt; j++ {
			result[i][j] = rand.Intn(1000)
		}
	}

	return result
}
