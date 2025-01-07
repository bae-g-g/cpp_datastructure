#include <iostream>

template <typename T>

class CircularQueue{

private:
    int size;
    int front;
    int rear;
    T* arr;

public:

    CircularQueue(int _size){
        this -> size = _size+1;
        this -> front = 0;
        this -> rear = 0;
        this -> arr = new T[this -> size];

    }
    
    CircularQueue():size(50),front(0),rear(0){
        arr = new int[this->size];
    }
    
    ~CircularQueue(){
        delete[] arr;
    }

    bool is_empty(){
        if(this -> front == this -> rear){
            return true;
        }
        else{
            return false;
        }
        
    }

    bool is_full(){
        if( ( this -> rear + 1 )% this -> size == this -> front){
            return true;

        }
        else{
            return false;
        }
    }

    void enqueue(T _data){
        if( this -> is_full() == true){
             throw std::out_of_range("queeu is full");
        }
        else{
            this -> arr[this -> rear] = _data;
            this -> rear = (this -> rear +1)% this -> size;
        }
    }

    T dequeue(){
        if( this -> is_empty() == true){
            throw std::out_of_range("queue is empty");
        }
        else{
            T result = this -> arr[this -> front];
            this -> front = (this -> front + 1) % this -> size;
            return result;
        }
    }

};


int main(){


}