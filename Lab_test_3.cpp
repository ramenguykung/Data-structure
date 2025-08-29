#include <iostream>

class Queue{
public:
    int queue[5] = {};
    int head = 2;
    int tail = 1;
    int size = 0;
    
    void enqueue(int value){
        if(size == 5){
            std::cout << "Queue Full" << std::endl;
        }else{
            queue[tail] = value;
            tail = (tail + 1) % 5;
            size++;
            std::cout << "h : " << head << " " << "t : " << tail << std::endl;
        }
    }
    void dequeue(){
        if(size == 0){
            std::cout << "Queue Empty" << std::endl;
        }else{
            std::cout << queue[head] << std::endl;
            head = (head + 1) % 5;
            size--;
            std::cout << "h : " << head << " " << "t : " << tail << std::endl;
        }
    }
    void checkcommand(char command){
        switch(command){
            case 'e': int temp ;std::cin >> temp; enqueue(temp);break;
            case 'd': dequeue();break;
        }
    }
};
int main(){
    Queue q;
    char command;
    while(command != 'x'){
        std::cin >> command;
        q.checkcommand(command);
    }
    return 0;
}