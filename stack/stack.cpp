#include  <iostream>

class stack{

private:
    int top;
    int size;
    int *arr;

public:
    //매개변수 생성자
    stack(int size){
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
    }
    //디폴트 생성자
    stack():size(20),top(-1){
        this -> arr = new int[ this->size ]; 
    }
    ~stack(){
        delete[] this->arr;
    }

    bool isempty(){
        
        if(this->top == -1){
            return true;
        }
        else{
            return false;
        }

    }

    bool isfull(){
        if(this->top == this->size -1){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int data){

        if( this->isfull() ){
            std :: cout << "full\n";
        }
        else{
            this->top++;
            this->arr[this->top] = data;

        }
    }


    int pop(){
        if( this -> isempty() ){
            std:: cout << "empty\n";
            return -1;
        }
        else{
            int result = this -> arr[ this -> top]; 
            this -> top --;
            return result;

        }
    }

    
    int peek(){

        if( this->isempty() ){
            
            return -1;
        }
        else{

            return this -> arr[ this -> top ];
        }
    }
};


int main(){

    stack s(5);

    return 0;

}