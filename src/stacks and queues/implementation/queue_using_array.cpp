class ArrayQueue {
    int currSize;
    int capacity;
    int* queueArray;
    int start, end;

   public:
    ArrayQueue(int size = 1000) {
        currSize = 0;
        capacity = size;
        queueArray = new int[capacity];
        start = end = -1;
    }

    ~ArrayQueue() { delete[] queueArray; }

    void push(int x) {
        // push at the end
        if (currSize == capacity) {
            // can't push
            cout << "no space to push" << endl;
            return;
        }
        if (start == -1 && end == -1) start = 0;
        end = (end + 1) % capacity;
        queueArray[end] = x;
        currSize++;
    }

    int pop() {
        if (currSize == 0) {
            cout << "nothing to pop" << endl;
            return -1;
        }
        if (currSize == 1) {
            int el = queueArray[start];
            start = -1;
            end = -1;
            currSize--;
            return el;
        }
        int el = queueArray[start];
        start = (start + 1) % capacity;
        currSize--;
        return el;
    }

    int peek() {
        // starting element
        if (currSize == 0) return -1;
        return queueArray[start];
    }

    bool isEmpty() { return currSize == 0; }
};