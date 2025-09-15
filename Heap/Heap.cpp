#include <iostream>
class MaxHeap {
private:
	int heap[100];
	int size;
	void heapifyUp(int index) {
		if (index > 0) {
			int parentIndex = (index - 1) / 2;
			if (heap[parentIndex] < heap[index]) {
				std::swap(heap[parentIndex], heap[index]);
				heapifyUp(parentIndex);
			}
		}
	}

	void heapifyDown(int index) {
		int leftChildIndex = 2 * index + 1;
		int rightChildIndex = 2 * index + 2;
		int largestIndex = index;

		if (leftChildIndex < size && heap[leftChildIndex] > heap[largestIndex]) {
			largestIndex = leftChildIndex;
		}

		if (rightChildIndex < size && heap[rightChildIndex] > heap[largestIndex]) {
			largestIndex = rightChildIndex;
		}

		if (largestIndex != index) {
			std::swap(heap[largestIndex], heap[index]);
			heapifyDown(largestIndex);
		}
	}

public:
	MaxHeap() : size(0) {}

	void add(int data) {
		if (size < sizeof(heap) / sizeof(heap[0])) {
			heap[size] = data;
			heapifyUp(size);
			size++;
		} else {
			std::cerr << "Heap is full" << std::endl;
		}
	}

	int remove() {
		if (size == 0) {
			std::cerr << "Heap is empty" << std::endl;
			exit(1);
		}

		int maxData = heap[0];
		heap[0] = heap[size - 1];
		size--;
		heapifyDown(0);
		return maxData;
	}

	void show() {
		for (int i = 0; i < size; i++) {
			std::cout << heap[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main() {
	MaxHeap maxHeap;

	char command;
	int data;

	while (std::cin >> command) {
		if (command == 'a') {
			std::cin >> data;
			maxHeap.add(data);
		} else if (command == 'p') {
			maxHeap.show();
		} else if (command == 'd') {
			std::cout << maxHeap.remove() << std::endl;
		} else if (command == 'e') {
			break;
		}
	}

	return 0;
}