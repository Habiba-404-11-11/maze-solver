#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include "MazeAlgorithms.h"
#include "MAZE.h"



using namespace std;

void showMazeResult(const AlgorithmResult& result, MazeData& mazeData) {

    for (int i = 0; i < mazeData.FULL_R; i++) {
        for (int j = 0; j < mazeData.FULL_C; j++) {
            int cell = result.solutionGrid[i][j];


            if (cell == WALL) cout << "###";
            else if (cell == START) cout << " S ";
            else if (cell == GOAL) cout << " G ";
            else if (cell == SHORTEST_PATH) cout << " . ";
            else cout << " " << mazeData.weights[i][j] << " ";  // Empty for PATH
        }
        cout << endl;
    }


}
void showMaze(const MazeData& mazeData) {

    for (int i = 0; i < mazeData.FULL_R; i++) {
        for (int j = 0; j < mazeData.FULL_C; j++) {
            int cell = mazeData.grid[i][j];


            if (cell == WALL) cout << "###";
            else if (cell == START) cout << " S ";
            else if (cell == GOAL) cout << " G ";
            else if (cell == PATH) cout << " " << mazeData.weights[i][j] << " ";  // Empty for PATH
        }
        cout << endl;
    }


}



#endif 

