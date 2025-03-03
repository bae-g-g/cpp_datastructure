#include <iostream>

template<typename T1,typename T2>
struct mypair_struct{
    T1 key;
    T2 value;

    mypair_struct(T1 input1, T2 input2)
    : key(input1), value(input2){}


};

template<typename T1,typename T2>
class MyPair{
    public:
    mypair_struct<T1,T2> my_pair; 
    
    MyPair(T1 input1,T2 input2)
    :my_pair(input1,input2){}

    T1 get_key() const{
        return my_pair.key;
    }
    T2 get_value() const{
        return my_pair.value;
    }
    
    void swap(MyPair& other){
        T1 key_temp = this ->my_pair.key;
        this ->my_pair.key = other.my_pair.key;
        other.my_pair.key = key_temp;
        
        T2 value_temp = this ->my_pair.value;
        this ->my_pair.value = other.my_pair.value;
        other.my_pair.value = value_temp;

        
    }

    bool operator> (const MyPair& other) const{
        return this->get_key() > other.get_key();
       
    } 


};

template<typename T>

void swap(T& a,T& b){
    T temp = a;
    a = b;
    b= temp;
}

int main(){
MyPair<int,float> a(1,2.2);
MyPair<int,float> b(3,4.4);

std::cout<<a.get_key()<<std::endl;
a.swap(b);
std::cout<<a.get_key()<<std::endl;
swap(a,b);
std::cout<<a.get_key()<<std::endl;

if(a>b){
    std::cout<<"a > b "<<std::endl;
}
else{
    std::cout<<"b > a"<<std::endl;
}


}