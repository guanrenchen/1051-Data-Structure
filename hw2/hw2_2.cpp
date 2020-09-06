#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[]){
    int n, m, x, y;
    cout << "N: ";
    cin >> n;
    cout << "M: ";
    cin >> m;
    cout << "Initial bug position X: ";
    cin >> x;
    cout << "Initial bug position Y: ";
    cin >> y;

    if(n<2  || m<2  || x<0  || y<0  || n>40 || m>20 || x>=n || y>=m){
        cout << "INVALID INPUT" << endl;
        return 0;
    }

    srand(time(NULL));
    const int MOVE_LIMIT=50000;
    const int dx[8]={-1, 0, 1,-1, 1,-1, 0, 1};
    const int dy[8]={ 1, 1, 1, 0, 0,-1,-1,-1};
    int map[n][m], space=n*m;
    int i=0, j=0, k=0;
    int randNum, temp_x, temp_y;

    for(i=0; i<n; ++i)
        for(j=0; j<m; ++j)
            map[i][j]=0;

    for(i=1; i<MOVE_LIMIT; ++i){
        if(map[x][y]++==0 && --space==0) break;
        do{
            randNum=rand()%8;
            temp_x = x+dx[randNum];
            temp_y = y+dy[randNum];
        }while(temp_x<0 || temp_x>=n || temp_y<0 || temp_y>=m);
        x=temp_x;
        y=temp_y;
    }

    FILE *outFile = fopen("Sample_Output.txt","w");
    fprintf(outFile,"總共 %d 步\n\n", i);
    for(i=m-1; i>=0; --i){
        for(j=0; j<n; ++j)
            fprintf(outFile, "%5d", map[i][j]);
        fprintf(outFile, "\n");
    }
    fclose(outFile);
    return 0;
}
