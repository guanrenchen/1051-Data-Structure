#include<iostream>
using namespace std;

long long int recursiveStair(int n)
{
    if(n==0) return 1;
    return n*recursiveStair(n-1);
}

long long int iterativeStair(int n)
{
    long long int result=1;
    while(n>0) result*=n--;
    return result;
}

int main(int argc, char* argv[])
{
    int num;
    while((cout << "\nPlease enter a number bigger than 0. enter\'-1\' to end program.\n") &&
          (cin >> num) &&
          num>=0)
    {
        if(num!=0 && recursiveStair(num)/num!=recursiveStair(num-1))
        {
            cout << "Recursive: overflow" << endl;
            cout << "Iterative: overflow" << endl;
            continue;
        }
        cout << "Recursive: " << recursiveStair(num) << endl;
        cout << "Iterative: " << iterativeStair(num) << endl;
    }

    return 0;
}
