#!/bin/bash
build(){
    rm -rf build
    mkdir build
    cd build
    cmake ..
    make
    mv sudoku_solver ../
    cd ..
    cp ../Ressources/resultGrid.jpg /tmp/resultGrid.jpg
    cp -r ../Ressources/Numbers /tmp/Numbers
}
build

execTest(){
    for ((i=1 ; i < 3 ; i++)); do
        echo "Test $i"
        ./sudoku_solver ../Tests/grid$i.txt
        diff -s ../Tests/grid$i.txt.result ../Tests/TestRes/grid$i.txt.expect
        diff -s ../Tests/grid$i.txt.result.bmp ../Tests/TestRes/grid$i.txt.expect.bmp
    done

}
execTest
