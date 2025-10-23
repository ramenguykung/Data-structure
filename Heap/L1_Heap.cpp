#include <iostream>
#define HEAP_SIZE 100

class MaxHeap {
    public:
    int heap[HEAP_SIZE];
    int size = 0;

    void heapUp(int index) {
        if (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[parentIndex] < heap[index]) {
                std::swap(heap[parentIndex], heap[index]);
                heapUp(parentIndex);
            }
        }
    }
    void heapDown(int index) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int largestIndex = index;

        if (leftChildIndex < size &&
            heap[leftChildIndex] > heap[largestIndex]) {
                largestIndex = leftChildIndex;
            }
        
        if (rightChildIndex < size &&
            heap[rightChildIndex] > heap[largestIndex]) {
                largestIndex = rightChildIndex;
            }

        if (largestIndex != index) {
            std::swap(heap[largestIndex], heap[index]);
            heapDown(largestIndex);
        }
    }

    void add(int data) {
        if (size < sizeof(heap) / sizeof(heap[0])) {
            heap[size] = data;
            heapUp(size);
            size++;
        } else {
            std::cout << "Heap is full" << std::endl;
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }

    int pop() {
        if (size == 0) {
            return -1;
        } else {
            int MaxValue = heap[0];
            heap[0] = heap[size - 1];
            size--;
            heapDown(0);
            return MaxValue;
        }
    }
};
int main() {
    MaxHeap h;
    char option;
    int value;

    while(std::cin >> option) {
        switch(option) {
        case 'a':
            std::cin >> value;
            h.add(value);
            break;
        case 'p':
            h.print();
            break;
        case 'd': {
            int t = h.pop();
            if (t == -1){
                std::cout << "Heap is empty" << std::endl;
            } else {
                std::cout << t << std::endl;
            }
            }
            break;
        case 'e':
            exit(0);
        default:
            std::cout << "Invalid option" << std::endl;
            break;
        }
    }
    return 0;
}
