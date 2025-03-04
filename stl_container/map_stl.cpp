#include <iostream>
#include <map>

/*

key - value 를 한 쌍으로 저장하는 자료형
내부적으로 key에 대한 balnce tree로 이루어져
삽입,삭제,탐색이 logN


*/

int main(){


    std::map<int,int> mymap; // key - value를 모두 int로 선언

    mymap.insert({1,0});
    mymap.insert({2,0});
    mymap.insert({3,0});
    mymap.insert({4,0});
    mymap.insert({5,0});

    std::map<int,int>::iterator it = mymap.find(3);
    
    std::cout<< it->first <<std::endl; // key - value로 이루어져 있기 때문에 반복자는 그 쌍 자체를 가르킨다. 값을 사용하고 싶을때 더 정확히 그 쌍의 key혹은 value를 지정해야한다. 
    std::cout<< it->second <<std::endl;


    std::cout<<mymap[2]<<std::endl; // map은 key값을 인덱스로 사용한다. key를 통한 인덱스 접근으로 value의 값을 조절한다.
    mymap[2] = 10; 
    std::cout<<mymap[2]<<std::endl;

    it = mymap.end();//내부적으로 오름차정렬이 되어있다. 
    it--;
    std::cout<< it->first <<std::endl;
    it = mymap.begin();
    std::cout<< it->first <<std::endl;

    mymap.erase(it);
    it = mymap.begin();
    std::cout<< it->first <<std::endl;
    
}