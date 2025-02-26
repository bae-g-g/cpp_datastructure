
/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=CCPP&select-1=2&pageSize=10&pageIndex=1
*/
/*
입렵값 정렬 필요x 
max값은
스택에 순서 대로 넣는데 만약 넣는 값이 스택에 쌓인 값보다 크다면 넣는 값보다 작은 값들은 다 pop으로 날린다.

입력값 자체와 max값을 모두 스택에 저장하면서 뒤에서 부터 쭉 빼면 될 듯
스택사용에서 복잡한 기능이 필요없으니까 벡터이용.

최대 입력 날짜 1,000,000
최대 입력 가격 10,000
최대 이익 10,000,000,000
long long 사용

*/
#include <iostream>
#include <vector>

class MyClass{

private:
    std::vector<int> daily_preice;
    std::vector<int> max_price;
    long long profit = 0;

    void to_next_max(int price){
        while(1){
            if( max_price.empty() || max_price.back() > price){
                max_price.push_back(price);
                return;
            }
            else{
                max_price.pop_back();
            }
        }
        
    }

public:


    void input(int num){
        
        int price;

        for(int i = 0; i<num; i++){
            std::cin>> price;
            daily_preice.push_back(price);
            to_next_max(price);
        }
    }
 
    long long max_profit(){
        
        int _size = max_price.size();
        for(int i = 0; i<_size; i++){
            
            int cur_max = max_price.back();
            max_price.pop_back();
            
            while(1){
                if(daily_preice.empty() || daily_preice.back() > cur_max) break;
                
                profit += cur_max - daily_preice.back();
                daily_preice.pop_back();
                 
            }
        }
        return profit;
    }

};

int main(){

    int test_num;
    std::cin>>test_num;

    for(int i =0; i<test_num; i++){
        
        MyClass test_case;
        int test_case_input;
        std::cin>>test_case_input;

        test_case.input( test_case_input );

        std::cout<<"#"<<i<<" "<< test_case.max_profit()<<std::endl;
        
    }

}