#include <iostream>

class CircularQueue{

private:
    int size;
    int front;
    int rear;
    int* arr;

public:
    CircularQueue(int _size){
        this -> size = _size + 1;
        this -> front = 0 ;
        this -> rear = 0;
        this -> arr = new int[this -> size];
    }
    
    ~CircularQueue(){
        delete[] this -> arr;
    }

    bool is_empty(){
        if(this -> rear == this -> front ){
            return true;
        }
        else{
            return false;
        }

    }

    bool is_full(){
        if( (this -> rear +1 )% this -> size == this -> front ){
            return true;
        }
        else{
            return false;
        }
    }

    void enque(int _data){
        if(this -> is_full() == true){
            
        }
        else{
            this -> arr[this -> rear] = _data;
            this -> rear = (this -> rear +1 )% this -> size;
        }

    }

    int deque(){
        if(this -> is_empty() == true ){

        }
        else{
            int result = this -> arr[this -> front];
            this -> front = ( this -> front + 1 )% this -> size;
            return result; 
        }

    }
    int peek(){
        if(this->is_empty() == true){

        }
        else{
            return this->arr[this -> front];
        }
    }

};


int main(){
    int N;
    std :: cin >> N;

    CircularQueue _queue(N);

    for(int i = 1; i<=N; i++){
        _queue.enque(i);
    }

    int K;
    int count = 0;
    std :: cin >> K;
    
    std::cout << '<';

    while(_queue.is_empty() == false){
      
        count++;
      
        for(int i = 0; i<K-1; i++){
            int temp = _queue.deque();
            _queue.enque(temp);
        }
        
        if(count ==  N){
            std::cout << _queue.deque();
        }
        else{
            std::cout << _queue.deque() <<", ";
        }
        

    }
    
    std::cout << '>';

}