#include <iostream>

class Stack{
    private:
        int top;
        int size;
        int *arr;

    public:
        Stack(int _size){
            this -> size = _size;
            this -> arr = new int[_size];
            this -> top = -1;
        }
        ~Stack(){
            delete[] this->arr; 
        }

        void push(int _data){

            this -> top++;
            this -> arr[top] = _data;

        }

        int pop(){
            int temp = this ->arr[this -> top];
            this -> top--;
            return temp;
        }
        int peek(){
            return this -> arr [ this -> top ];

        }


};


class Node{
    public:
        int data;
        int count;

    Node(int _data){
        this -> data = _data;
        this -> count = 1;
    }
    ~Node(){

    }

    void add_node(int _data){
        if(this -> count == 0){
         Node(_data);
        }
        else{
            this -> count++;
        }
    }


};




int main(){
    int size;
    std::cin >> size;
    Stack _stack(size);




}

/*


7

1   1   2   3   4   2   1

3   3   2   1   1   2   3

-1 -1   1   2   2   1  -1


-------

3=3 =3  = x
2 = 2  = 1
1 = 1 =2





------


1  1  2  3  4  2  1 1

1  2  2  1  1  2  3 3




*/