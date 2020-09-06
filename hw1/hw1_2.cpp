#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

static int numOfSets=0;

vector<string> acquireElements()
{
    string str;
    getline(cin, str);

    int i;
    for(i=0; i<str.size(); ++i)
        if(ispunct(str.at(i)))
            str.replace(i,1," ");

    istringstream iss(str);
    vector<string> elements;
    do{
        string sub;
        iss >> sub;
        if(sub.size()!=0)
            elements.push_back(sub);
    }while(iss);
    return elements;
}

void printSubspace(const vector<string> &elements, 
                   const int &targetSize,
                   const int &pos,
                   vector<string> subspace)
{
    if(targetSize>elements.size())
        return;
    int i;
    if(subspace.size()==targetSize)
    {
        cout << '{';
        for(i=0; i<targetSize; ++i)
            cout << subspace.at(i) << ',';        
        cout << (targetSize==0?'\0':'\b') << '}' << endl;
        ++numOfSets;
        return;
    }
    for(i=pos; i<elements.size(); ++i)
    {
        subspace.push_back(elements.at(i));
        printSubspace(elements, targetSize, i+1, subspace);
        subspace.pop_back();
    }
}

int printAllSubspace(const vector<string> &elements)
{
    int i=0;
    vector<string> zeroSpace;
    numOfSets=0;
    while(i<=elements.size())
        printSubspace(elements, i++, 0, zeroSpace);
    return numOfSets;
}

int main(int argc, char* argv[])
{
    cout << "A total of " << printAllSubspace(acquireElements()) << " sets in the powerset" <<endl;
    return 0;
}
