#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class AOE{
public:
    class Activity{
    public:
        Activity(int start, int end, int duration): start(start), end(end), duration(duration), early(0), late(0){}
        int start, end, duration, early, late;
    };

    AOE(){
        fstream inFile("Sample_input.txt", ios::in);
        inFile >> eventNum;
        int i, j, temp;
        for(i=0; i<eventNum; ++i)
        for(j=0; j<eventNum; ++j){
            inFile >> temp;
            if(temp>0) a.push_back(Activity(i, j, temp));
        }
        inFile.close();
    }

    void getEarly(){
        int i, j;
        for(i=0; i<a.size(); ++i)
        for(j=0; j<a.size(); ++j)
            if((a[i].end==a[j].start) && (a[i].early+a[i].duration>a[j].early))
                a[j].early = a[i].early+a[i].duration;
    }

    void getLate(){
        int i, j;
        for(i=0; i<a.size(); ++i)
            if(a[i].end==eventNum-1)
                a[i].late=a[i].early;

        for(i=a.size()-1; i>=0; --i)
        for(j=a.size()-1; j>=0; --j)
            if(a[i].start==a[j].end)
                a[j].late = a[i].late-a[j].duration;   
    }

    void printActivity(){
        int i;
        cout << "\tearly time\tlate time\tslack" << endl;
        cout << "activity     e\t\t    l\t\t l-e" << endl;
        for(i=0; i<a.size(); ++i){
            cout << "a(" << a[i].start << "," << a[i].end << ")";
            cout << "\t" << setw(6) << a[i].early;
            cout << "\t\t" << setw(5) << a[i].late;
            cout << "\t\t" << setw(3) << a[i].late-a[i].early;
            cout << endl;
        }
        cout << endl;
    }


private:
    int eventNum;
    vector<Activity> a;
};

int main(int argc, char* argv[]){
    AOE aoe;
    aoe.getEarly();
    aoe.getLate();
    aoe.printActivity();
    return 0;
}
