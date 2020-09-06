#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

static int minSteps;

void solveMaze(ofstream &outFile, vector< vector<char> > maze, const int &x, const int &y, const int &steps){
    int dx, dy;
    for(dx=-1; dx<=1; ++dx)
    for(dy=-1; dy<=1; ++dy){
        int tempX=x+dx, tempY=y+dy;
        if(tempX<0 || tempY<0 || tempX>=maze.size() || tempY>=maze[tempX].size() || (dx==0 && dy==0))               continue;
        switch(maze[tempX][tempY]){
            case '0':
                maze[tempX][tempY]='*';
                solveMaze(outFile, maze, tempX, tempY, steps+1);
                maze[tempX][tempY]='0';
                break;
            case 'd':
                int i, j;
                for(i=0; i<maze.size(); ++i){
                    for(j=0; j<maze[i].size(); ++j)
                        outFile << maze[i][j];
                    outFile << endl;
                }
                outFile << endl;
                if(steps<minSteps) minSteps=steps;
                break;
            default:
                break;
        }
	}
}

void solveMaze(ofstream &outFile, vector< vector<char> > maze){
    int i, j, startX, startY;
    for(i=0; i<maze.size(); ++i)
    for(j=0; j<maze[i].size(); ++j)
        if(maze[i][j]=='s'){
            solveMaze(outFile, maze, i, j, 1);
            return;
        }
}

int main(int argc, char* argv[]){
    ifstream inFile("in.txt");
    if(!inFile){
        cout << "Input File not found" << endl;
        return 0;
    }
    
    string str;
    vector< vector<char> > maze;
    vector<char> emptyCharVector;
    maze.push_back(emptyCharVector);
    while(getline(inFile, str)){
        int i;
        for(i=0; i<str.size(); ++i, ++minSteps)
            maze[maze.size()-1].push_back(str[i]);
        maze.push_back(emptyCharVector);
    }
    maze.pop_back();
    inFile.close();

    ofstream outFile("out.txt", ofstream::trunc);
    if(!outFile){
        cout << "Output file open failed" << endl;
        return 0;
    }
    solveMaze(outFile, maze);
    outFile << "The shortest path: " << minSteps << " steps";    
    outFile.close();

    return 0;
}
