#include  <iostream>


//자료형 일반화화
template <typename T> 
class stack{

private:
    int top;
    int size;
    T *arr;

public:
    //매개변수 생성자
    stack(int size){
        this->size = size;
        this->top = -1;
        this->arr = new T[size];
    }
    //디폴트 생성자
    stack():size(50),top(-1){
        this -> arr = new T[ this->size ]; 
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

    void push(T data){

        if( this->isfull() ){
            throw std::out_of_range("Stack is full");
        }
        else{
            this->top++;
            this->arr[this->top] = data;

        }
    }


    T pop(){
        if( this -> isempty() ){
            throw std::out_of_range("Stack is empty");
            
        }
        else{
            T result = this -> arr[ this -> top]; 
            this -> top --;
            return result;

        }
    }


    T peek(){

        if( this->isempty() ){
            throw std::out_of_range("Stack is empty");
        }
        else{

            return this -> arr[ this -> top ];
        }
    }
};


int main(){

 
    int repeat_num;
    std::cin>>repeat_num;
    

    for(int i = 0; i<repeat_num; i++){
        
        stack<char> my_stack;

        std::string input;
        std::cin >> input;
        
        bool vaild = true;

        for(char j : input){
            if ( j == '(' ){
                
                my_stack.push('(');
            }
            else{

                if(my_stack.isempty()){
                    vaild = false;
                    break;

                }
                else{
                    my_stack.pop();
                }
            }

        }
        
        if(vaild == false || my_stack.isempty() == false){
            std :: cout << "NO\n";
        }
        else{
            std :: cout << "YES\n";
        }

    }

}