#include <iostream>


template <typename T>

class Node{
    private:
        T data;
        Node<T>* next;


    public:
    Node(T input){
        this -> data = input;
        this -> next = 0;
    }

    ~Node(){
    }

    void set_next(Node<T>* _next){
        this -> next = _next;
    }

    T get_data(){
        return this -> data;
    }

    Node<T>* get_next(){
        return this ->next;
    }

};

template <typename T>
class stack{

    private:
        Node<T>* head;
        int size;
        
    public:

        stack(){
            this -> head = 0;
            this -> size = 0; 
        }

        ~stack(){
        }

        bool isempty(){
            if(this -> head == 0){
                return true;
            }
            else{
                return false;
            }

        }
        int get_size(){
            return this -> size;
        }

        void push(T input){
            Node<T>* cur_node = new Node<T>(input);
            cur_node->set_next( this -> head );
            this -> head = cur_node;
            this -> size++;
        }

        T pop(){

            if(this -> isempty()){
                throw std::out_of_range("Stack is empty");
            }

            T result = this -> head -> get_data();
            Node<T>* temp = this -> head;
            this -> head = this ->head->get_next();
            delete temp;
            this -> size--;
            return result;

        }

        T peek(){
            if(this -> isempty()){
                throw std::out_of_range("Stack is empty");
            }
            return this -> head -> get_data();
        }


};


int main(){
    
    stack<std::string> a;
    
    a.push("123");
    a.push("456");
    a.push("789");

    std:: cout << a.pop();
    


}