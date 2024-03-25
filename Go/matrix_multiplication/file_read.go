package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

const fileName = "../input.txt" // relative to module

func GetMatricesFromTextFile() ([][]int, [][]int) {
	matrix1 := make([][]int, 0)
	matrix2 := make([][]int, 0)
	matrixCount := 0

	file, err := os.Open(fileName)
	if err != nil {
		panic(err)
	}

	reader := bufio.NewReader(file)

	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			break
		}

		line = strings.TrimSpace(line)
		if len(line) == 0 {
			matrixCount++
			continue
		}

		rowElements := strings.Split(line, " ")
		row := make([]int, 0)
		for _, element := range rowElements {
			if element == "" {
				continue
			}
			elementInt, err := strconv.Atoi(element)
			if err != nil {
				panic(err)
			}
			row = append(row, elementInt)
		}

		if matrixCount == 0 {
			matrix1 = append(matrix1, row)
		} else if matrixCount == 1 {
			matrix2 = append(matrix2, row)
		} else {
			break
		}
	}

	return matrix1, matrix2
}
