#include <iostream>
#include <map>


/*
정렬된 상태가 필요.

각 요소는 중복이 허용됨.

각 시행마다 최소 - 최대값을 뽑아야함.
또는 정렬이 필요함.

-중복 갯수를 저장가능한.
데이터구조.

map.


*/


class myclass{
private:
std::map< int, int > my_map;
int dump_num;

public:

    void add_hight(int input){
        if( my_map.find(input) == my_map.end() ){

            my_map.insert({input,1});

        }
        else{
            my_map[input]++;
        }
        

    }
    
    void input(){
        std::cin>>dump_num;
        for(int i = 0 ; i<100; i++){
            int _input;
            std::cin>>_input;
            add_hight(_input);
        }
    }


    int dump(){
        auto min = my_map.begin();
        auto max = my_map.end();
        max--;

        
        std::cout << min->first <<" "<<max->first<<std::endl;
        add_hight(min -> first + 1 );
        add_hight(max -> first - 1 );
        
        min->second--;
        max->second--;
        

        if(min->second == 0){
            my_map.erase(min);
        }
        
        if(max->second == 0){
            my_map.erase(max);
        }
        min = my_map.begin();
        max = my_map.end();
        max--; 
        return max->first - min -> first;


    }
    
    int fn(){
        int ans = -1;
        for(int i =0 ; i<dump_num; i++){
            ans = dump();
            if(ans == 0 || ans == 1){
               break;;
            }
        }
        return ans;
    }


};


int main(){
    for(int i = 1; i<=10; i++){

    myclass a;
    a.input();
    std::cout <<"#"<<i<<" "<<a.fn()<<std::endl;
}
}