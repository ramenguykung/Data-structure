#include<iostream>
#define size 100
using namespace std;

class Cqueue{
public:
    int front;
    int rear;
    int arr[size];
    int count;
    
    Cqueue(){
        front = 2;
        rear = 1;
        count = 0;
    }
    
    bool isempty(){
        return count == 0; 
    }
    bool isfull(){
        return count == size;
    }
    void enqueue (int data){
        if(isfull()){
            cout << "Queue Full" << endl;
        }else{
            rear = (rear + 1) % size;
            arr[rear] = data;
            count++;
            cout << "f" << front << "r" << rear << endl;
        }
    }
    void dequeue(){
        if(isempty()){
            cout << "Queue Empty" << endl;
            cout << "f" << front << "r" << rear << endl; 
        }else{
            cout << arr[front] << endl;
            front = (front + 1) % size;
            count--;
            cout << "f" << front << "r" << rear << endl;
        }
    }
};

int main(){
    char x;
    int data;
    Cqueue c;
    
    while(true){
        cin >> x;
        switch(x){
            case 'e':
                cin >> data;
                c.enqueue(data);
                break;
            case 'd':
                c.dequeue();
                break;
            case 'x':
                return 0;
        }
    }
}