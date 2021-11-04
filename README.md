# sudoku_solver

A command line efficient sudoku solver written in C.

## Table of Contents
* [Installation](#installation)
* [Usage](#usage)
* [Notes](#notes)

## Installation

```
git clone https://github.com/Antabuse-does-something/sudoku_solver.git
cd ./sudoku_solver/src
make
```

## Usage

Your file has to follow this format :
```
... ... ...
... ... ...
... ... ...

... ... ...
... ... ...
... ... ...

... ... ...
... ... ...
... ... ...
```


Replace all the with the numbers from your sudoku puzzle.

```./sudoku_solver <file>```

The output will be a file named as the same as the input file with the extension .result. 

## Notes 

This solver is part from the project [OCR_SUDOKU](https://github.com/Helyosis/OCR_EPITA) feel free to look at it.