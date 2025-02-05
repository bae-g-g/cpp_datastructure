#include <iostream>
#include <vector>

struct buliding
{
    long long hight;
    long long sum;
};

int fn(std::vector<buliding>& _stack, long long _input, long long& _ans){
   
    if( _stack.empty() == true || _stack.back().hight > _input ){
        return 0;
    }

    long long temp = _stack.back().sum;
    _ans += temp;
    _stack.pop_back();
       
    if( _stack.empty() == false ){
        temp++;
        _stack.back().sum += temp;
    }

    return 1;
}


int main(){
    std::vector<buliding> STACK;
    
    int num;
    std::cin >> num;
    long long ans = 0;

    for(int i = 0; i<num; i++){
        int input;
        std::cin >> input;

        buliding data;
        data.hight = input;
        data.sum = 0;
        
        while(1){

            if(fn(STACK,input,ans)== 0){
                STACK.push_back(data);
                break;
            }
        } 
    }


    while(1){
        if(fn(STACK,9999999999,ans) == 0){
            std::cout <<ans;
            break;
        }
    }

}
