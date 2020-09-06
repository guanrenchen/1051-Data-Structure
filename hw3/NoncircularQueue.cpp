#include<iostream>
#include<vector>
#include<string>
using namespace std;

class NoncircularQueue{
    public:
        NoncircularQueue(const int &n){
            size = n;
            front = -1;
            rear = -1;
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
                    if(rear==size-1){
                        if(front>-1){
                            for(i=0; i<size-(front+1); ++i) queue[i]=queue[i+front+1];
                            while(i<size) queue[i++].clear();
                            rear-=(front+1);
                            front=-1;
                            queue[++rear]=data;
                        }else{
                            cout << "Queue is full" << endl;
                        }
                    }else{
                        queue[++rear]=data;
                    }
                    printQueue(action);
                    break;
                case 2:
                    if(front==rear) cout << "Queue is empty" << endl;
                    else              queue[++front].clear();
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
    NoncircularQueue ncQueue = NoncircularQueue(4);
    while(ncQueue.prompt());
    return 0;
}
