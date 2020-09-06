#include<iostream>
using namespace std;

class Matrix{
    public:
        class Node{
            public:
                Node(){
                    this->row = -1;
                    this->col = -1;
                    this->value = -1;
                    this->nextRow = NULL;
                    this->nextCol = NULL;
                }

                Node(const int &row, const int &col, const int &value){
                    this->row = row;
                    this->col = col;
                    this->value = value;
                    this->nextRow = NULL;
                    this->nextCol = NULL;
                }

                Node *nextRow, *nextCol;
                int row, col, value;
        };

        Matrix(){
            cin >> row >> col;
            
            int i, j, temp;
            Node *cur;
            
            head = new Node[row>col? row: col];
            
            for(i=0; i<row; ++i)
            for(j=0; j<col; ++j){
                cin >> temp;
                if(temp!=0){
                    cur = new Node(i, j, temp);
                    pushToRow(i, cur);
                    pushToCol(j, cur);
                }
            }
        }
        
        void pushToRow(const int &row, Node *newNode){
            Node *cur = &head[row];
            while(cur->nextCol!=NULL) cur = cur->nextCol;
            cur->nextCol = newNode;
        }

        void pushToCol(const int &col, Node *newNode){
            Node *cur = &head[col];
            while(cur->nextRow!=NULL) cur = cur->nextRow;
            cur->nextRow = newNode;
        }
        
        void transpose(){
            int i, j;
            Node *cur;
            for(i=0; i<col; ++i){
                cur = head[i].nextRow;
                for(j=0; j<row; ++j){
                    if(cur!=NULL && j==cur->row){
                        cout << cur->value;
                        cur=cur->nextRow;
                    }else{
                        cout << 0;
                    }
                    cout << " ";
                }
                cout << endl;
            }
        }

        static int multiply(Node arrA, Node arrB){
            int temp=0;
            Node *curA=arrA.nextCol, *curB=arrB.nextRow;
            while(curA!=NULL && curB!=NULL){
                if(curA->col==curB->row){
                    temp += curA->value*curB->value;
                    curA = curA->nextCol;
                    curB = curB->nextRow;
                }
                else if(curA->col<curB->row) curA = curA->nextCol;
                else if(curA->col>curB->row) curB = curB->nextRow;
            }
            return temp;
        }

        static void multiply(Matrix b, Matrix a){
            if(a.row!=b.col) cout << "ERROR : Matrix do not match" << endl;
            int i, j;
            for(i=0; i<a.row; ++i){
                for(j=0; j<b.col; ++j){
                    cout << multiply(a.head[i], b.head[j]);
                    cout << " ";
                }
                cout << endl;
            }
        }

        Node *head;
        int row, col;
};

int main(int argc, char* argv[]){
    Matrix::multiply(*(new Matrix()), *(new Matrix()));
    return 0;
}
