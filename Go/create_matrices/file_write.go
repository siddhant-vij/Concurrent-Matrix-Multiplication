package main

import (
	"os"
	"strconv"
)

const fileName = "../input.txt" // relative to module

var matrixCount int = 0

func addMatrixToFile(matrix [][]int) {
	matrixCount++
	if matrixCount == 1 {
		_, err := os.Stat(fileName)
		if err == nil {
			err = os.Truncate(fileName, 0)
			if err != nil {
				panic(err)
			}
		} else if os.IsNotExist(err) {
			_, err := os.Create(fileName)
			if err != nil {
				panic(err)
			}
		} else {
			panic(err)
		}
	}

	file, err := os.OpenFile(fileName, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		panic(err)
	}
	defer file.Close()

	for _, row := range matrix {
		for _, element := range row {
			if _, err := file.WriteString(strconv.Itoa(element) + " "); err != nil {
				panic(err)
			}
		}
		if _, err := file.WriteString("\n"); err != nil {
			panic(err)
		}
	}
	if matrixCount == 1 {
		if _, err := file.WriteString("\n"); err != nil {
			panic(err)
		}
	}
}
