#include<iostream>
#include<vector>
#include<string>
using namespace std;

class CircularQueue{
    public:
        CircularQueue(const int &n){
            size = n;
            front = 0;
            rear = 0;
            for(i=0; i<size; ++i) queue.push_back(string());
        }

        void printQueue(int mode){
            cout << "Front=" << front << ",Rear=" << rear << endl;
            if(mode==2 && front!=rear) cout << "delete:" << front << endl;
            cout << "Queue:";
            for(i=0; i<size; ++i) cout << '[' << queue[i] << ']';
            cout << endl << endl;
        }

        bool prompt(){
            int action;
            string data;                    
            cout << "Insert(1)delete(2):";
            cin >> action;
            switch(action){
                case 1:
                    cout << "Insert number:";
                    cin >> data;
                    if((rear+1)%size==front){
                        cout << "Queue is full" << endl;
                    }else{
                        (++rear)%=size;
                        queue[rear]=data;
                    }
                    printQueue(action);
                    break;
                case 2:
                    if(front==rear){
                        cout << "Queue is empty" << endl;
                    }else{
                        (++front)%=size;
                        queue[front].clear();
                    }
                    printQueue(action);
                    break;
                default:
                    return false;
                    break;
            }
            return true;
        }

    private:
        vector<string> queue;
        int front, rear, size, i;
};

int main(int argc, char* argv[]){
    CircularQueue cQueue = CircularQueue(4);
    while(cQueue.prompt());
    return 0;
}
