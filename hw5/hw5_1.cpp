#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

#include<cctype>
#include<cstdlib>
#include<ctime>

using namespace std;
class MaxHeap{
    public:
        MaxHeap(){
            heap.push_back(0);

            int i;
            string str;
        
            fstream inFile("in.txt");
            if(!inFile){    
                cout << "Input File not found" << endl;      
                exit(1);
            }
                    
            getline(inFile, str);  
            for(i=0; i<str.size(); ++i)    
                if(ispunct(str.at(i)))        
                    str.replace(i,1," ");        
                
            istringstream iss(str);
            while(iss >> i) insertElement(i);
        }

        void sort(const int &index){
            if(index<=1 || index>=heap.size()) return;
            if(heap[index]>heap[index/2]){
                heap[index] ^= heap[index/2];
                heap[index/2] ^= heap[index];
                heap[index] ^= heap[index/2];
            }
            return sort(index/2);
        }

        void insertElement(const int &num){
            heap.push_back(num);
            sort(heap.size()-1);
        }

        void changePriority(const int &origNum, const int &newNum){
            int i; 
            for(i=1; i<heap.size(); ++i)
                if(heap[i]==origNum)
                    break;
            while(i*2<heap.size()){
                if(i*2+1==heap.size() || heap[i*2]>heap[i*2+1]){
                    heap[i]=heap[i*2];
                    i=i*2;
                }else{
                    heap[i]=heap[i*2+1];
                    i=i*2+1;
                }
            }    
            heap[i]=newNum;
            sort(i);
        }

        void printHeap(){
            cout << "Max Heap : " << endl;
            int i=1, cnt=2;
            while(i<heap.size()){
                cout << heap[i++] << " ";
                if(i==cnt){
                    cout << endl;
                    cnt*=2;
                }
            }
            cout << endl;
        }

    private:
        vector<int> heap;
};

unsigned long long int begin, end;
inline unsigned long long int rdtsc()
{
    unsigned long long int a;
    asm volatile("rdtsc":"=A"(a));
    return a;
}

int main(int argc, char* argv[]){
    MaxHeap mh;
    int origNum, newNum;
    char ch;

    cout << "Create Max Heap : " << endl;
    mh.printHeap();
    while(1){
        cout << "Change priority?(Y/N) : ";
        cin >> ch;
        if(ch!='Y') break;
        cout << "Choice priority : ";
        cin >> origNum;
        cout << "Change priority to : ";
        cin >> newNum;
        begin = rdtsc();
        mh.changePriority(origNum, newNum);
        end = rdtsc();
        mh.printHeap();
        cout << "Spend time : " << (double)(end-begin)/1000000 << " sec" << endl;
    }
    return 0;
}
