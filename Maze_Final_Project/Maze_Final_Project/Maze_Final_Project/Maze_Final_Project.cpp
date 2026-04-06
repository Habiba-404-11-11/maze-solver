
#include <iostream>

#include "MyVector.h"
#include "MazeAlgorithms.h"
#include "MyPriorityQueue.h" 
#include "Maze.h"
#include "control.h"
#include "Console.h"

using namespace std;




int main()
{
	//defualt cordinates
    Cordinates c;
    c.start.r = 0; 
    c.start.c = 0;
    c.goal.r = 14;
    c.goal.c = 14;

    cout << "////////////////////////////MAZE COMPARISON////////////////////////////////\n";
    cout << endl;
    int choice;

    cout << "Eneter 1 if you want default controls\n";
    cout << "Enter 2 if you want to customize your maze\n";
    cout << endl;
    cout << "/////////////////////////////Default Controls////////////////////////////////\n";
    cout << endl;
    cout << "Rows: 15" << " Columns: 15\n";
    cout << "Start X: 0" << " Start Y: 0\n";
    cout << "Goal X: 14" << " Goal Y: 14\n";
    cout << endl;
    cout << "Your Choice: ";
    cin >> choice;

    bool validChoice1;
    bool validChoice2;
    bool validChoice3;

    while (true) {
     if(choice == 1 || choice == 2){
         break;
     }
     else{
         cout << "Invalid Choice. Please enter 1 or 2: ";
         cin >> choice;
	 }

    }
    cout << endl;
    if (choice == 2) {

        cout << "Please Enter\n";

        do {
            validChoice1 = true;
            cout << "Rows: ";
            cin >> c.R;
            cout << "Columns: ";
            cin >> c.C;
            cout << endl;
            if (c.R < 0 || c.C < 0)
            {
                validChoice1 = false;
                cout << "Invalid Choices\n";
            }

        } while (!validChoice1);

        cout << "Please Enter\n";

        do {
             validChoice2 = true;
            cout << "Start X: ";
            cin >> c.start.r;
            cout << "Start Y: ";
            cin >> c.start.c;
            cout << endl;
            if (c.start.r < 0 || c.start.c < 0 || c.start.r>= c.R || c.start.c>=c.C)
            {
                validChoice2 = false;
                cout << "Invalid Choices\n";
            }

        } while (!validChoice2);

        cout << "Please Enter\n";

        do {
             validChoice3 = true;
            cout << "Goal X: ";
            cin >> c.goal.r;
            cout << "Goal Y: ";
            cin >> c.goal.c;
            cout << endl;
            if (c.goal.r< 0 || c.goal.c < 0 || c.goal.r>= c.R || c.goal.c>=c.C)
            {
                validChoice3 = false;
                cout << "Invalid Choices\n";
            }
            if(c.goal.r == c.start.r && c.goal.c == c.start.c){
                validChoice3 = false;
                cout << "Goal point cannot be the same as Start point. Please enter different coordinates.\n";
			}

        } while (!validChoice3);

    }

    

    MazeData maze = generateMaze(c);
    AlgorithmResult solution1 = solveDijkstra(maze);
    AlgorithmResult solution2 = solveAStar(maze);
    AlgorithmResult solution3 = solveBucket(maze);



	cout << "\n///////////////////////////////Maze Generated/////////////////////////////////////\n";
	showMaze(maze);
    cout << endl;

	cout << "///////////////////////////////Dijkstra Result/////////////////////////////////////\n";
	cout << endl;
	showMazeResult(solution1, maze);
    cout << endl;
	cout << "Total Cost: " << solution1.totalCost << endl;
    cout << "Nodes Expanded: " << solution1.nodesExpanded << endl;
    cout << "Time Taken (ms): " << solution1.timeTakenMs << endl;
    cout << "Path Length: ";
    for (int i = 0; i < solution1.path.size(); i++) {
        cout << "(" << solution1.path[i].r << ", " << solution1.path[i].c << ")";
        if (i != solution1.path.size() - 1) {
            cout << " -> ";
        }
    }
	cout << endl;

	cout << "///////////////////////////////A* Result/////////////////////////////////////\n";
	cout << endl;
    showMazeResult(solution2, maze);
    cout << endl;
    cout << "Total Cost: " << solution2.totalCost << endl;
    cout << "Nodes Expanded: " << solution2.nodesExpanded << endl;
	cout << "Time Taken (ms): " << solution2.timeTakenMs << endl;
    cout << "Path Length: ";
    for (int i = 0; i < solution2.path.size(); i++) {
        cout << "(" << solution2.path[i].r << ", " << solution2.path[i].c << ")";
        if (i != solution2.path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;

	cout << "///////////////////////////////Bucket Result/////////////////////////////////////\n";
    cout << endl;
    showMazeResult(solution3, maze);
    cout << endl;
	cout << "Total Cost: " << solution3.totalCost << endl;
    cout<< "Nodes Expanded: " << solution3.nodesExpanded << endl;
    cout << "Time Taken (ms): " << solution3.timeTakenMs << endl;
    cout << "Path Length: ";
    for (int i = 0; i < solution3.path.size(); i++) {
        cout << "(" << solution3.path[i].r << ", " << solution3.path[i].c << ")";
        if (i != solution3.path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
	
    return 0;



   }
