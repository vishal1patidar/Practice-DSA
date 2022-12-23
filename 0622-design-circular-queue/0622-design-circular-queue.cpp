class MyCircularQueue {
private:
    deque<int> buffer_;
    int k_;

public:
    MyCircularQueue(int k) : k_(k) {
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        buffer_.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        buffer_.pop_front();
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return buffer_.front();
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return buffer_.back();
    }
    
    bool isEmpty() {
        return empty(buffer_);
    }
    
    bool isFull() {
        return size(buffer_) == k_;
    }
};