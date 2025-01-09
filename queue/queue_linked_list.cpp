#include <iostream>

// 노드 구조체 정의
typedef struct node{
    int data;
    struct node* next;
}node;


//큐 클래스  정의
class linked_list_queue{

private:
//front,rear기능을 하는 노드의 포인터 선언
//size확인 하는 변수 추가
node* front;
node* rear;
int size;

public:


//생성자,소멸자메서드
// 공백확인 메서드 (linked list에서 포화일 경우는 없음)
//enque deque peek메서드 구현
bool is_empty(){
    return size == 0;
}

void enque(int _data){

    node* new_node = new node;
    new_node -> data = _data;
    new_node -> next = 0;

    if( this -> is_empty() == true ){
        this -> front = new_node;
        this -> rear = new_node;
    }
    else{
        this -> rear -> next = new_node;
        this -> rear = new_node;
    }
    this -> size++;

}

int deque(){

    if( this -> is_empty() == true){
        throw std::runtime_error("Queue is empty.");
    }
    else{
        this -> size--;
        int result = this -> front -> data;
        node* temp_node = this->front;
        this -> front = this -> front -> next;
        delete temp_node;

        return result;
    }

}

int peek(){

    return this -> front -> data;
}

int get_size(){
    return this -> size;
}


linked_list_queue(){
    this -> front = 0;
    this -> rear = 0;
    this -> size = 0;
}

~linked_list_queue(){
    while( this -> is_empty() == false ){
        this -> size--;
        node* temp_node = this -> front;
        this -> front = this -> front -> next;
        delete temp_node; 
    }
}



};


int main(){


}