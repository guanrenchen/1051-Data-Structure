#include<iostream>
#include<fstream>
#include<vector>
#include<cstdio>
using namespace std;

vector<int> matrixToArray(int n, int a, int b, int* matrix){
    int i=a-1, j=0, end_i=n-b, end_j=n-1;
    vector<int> e;
    while(1){
        e.push_back(matrix[i*n+j]);
        if(i==end_i && j==end_j) break;
        ++i; 
        ++j;
        if(j>=n){
            j=n-i+1;
            i=0;
        }else if(i>=n){
            i=n-j-1;
            j=0;
        }
    }
    return e;
}

void printArray(int n, int a, int b, vector<int> e){
    int i, j, index;
    for(index=0, i=a-1, j=0; index<e.size(); ++index){    
        printf("e[%d] = %d\td(%d,%d)\n", index, e.at(index), i++, j++);
        if(j>=n){
            j=n-i+1;
            i=0;
        }else if(i>=n){
            i=n-j-1;
            j=0;
        }
    }
}

int main(int argc, char* argv[]){
    string fileName;
    fstream inFile;
    cout << "Please input the file name: ";
    cin >> fileName;
    inFile.open(fileName.data(), ios::in);
    if(!inFile){
        cout << "File open failed" << endl;
        return 0;
    }

    int n;
    inFile >> n;

    int i, matrix[n][n];
    for(i=0; i<n*n; ++i)
        inFile >> matrix[i/n][i%n];

    int a, b;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    
    vector<int> e = matrixToArray(n, a, b, *matrix);
    printArray(n, a, b, e);

    return 0;
}
