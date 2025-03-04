#include <iostream>
#include <set>


void fn1(std::set<int> _set){
    _set.erase(15);
}
void fn2(std::set<int>& _set){
    _set.erase(15);
}

int main(){

    
    std::set<int> myset; // set 선언
    std::set<int>::iterator it; // set의 요소접근을 위한 포인터 
    myset.insert(13);//node삽입
    myset.insert(12);
    myset.insert(15);
    myset.insert(10);

    
    if( myset.find(13) != myset.end() ){
        std::cout<< "exist1"<<std::endl;
    }
    else{
        std::cout<< "not exist"<<std::endl;
    }
    /*
    find를 통해 그 값을 찾는다면 node의 위치를 가르키는 iterator* 형태로 반환
    아닌경우 null반환 <- 자료형이 iterator임으로 null,nullptr로 직접적 사용 x 
    end()의 경우 iterator자료형의 null을 반환해줌으로 end를 사용
    */
    
    std::cout<<myset.size()<<std::endl; //size ,요소 갯수 출력

    auto st = myset.find(10); // iterator자료형 선언이 번거롭기 때문에 auto이용
    auto end = myset.find(13);
    myset.erase(st,end);//단일 원소 삭제 myset.erase(10); 또는 반복자를 이용해 범위로 삭제 가능

    std::cout << " myset "<<std::endl;
    for(auto i = myset.begin(); i!= myset.end(); i++ ){
        std::cout<<*i<<std::endl;
    }

    fn1(myset); // call by value
    std::cout << "after fn1 myset "<<std::endl;
    for(auto i = myset.begin(); i!= myset.end(); i++ ){
        std::cout<<*i<<std::endl;
    }
    fn2(myset); // call by reference
    std::cout << "after fn1 myset "<<std::endl;
    for(auto i = myset.begin(); i!= myset.end(); i++ ){
        std::cout<<*i<<std::endl;
    }

    std::set<int> myset1 ={ 1 , 2 , 3 ,4 ,5};
    std::set<int> myset2 ={ 10 , 20 , 30 ,40 ,50,60,70};
    myset2.swap(myset1);  // set을 둘이 바꿔 버림.
    std::cout << " myset2 "<<std::endl;
    for(auto i = myset2.begin(); i!=myset2.end(); i++){
        std::cout<<*i<<std::endl;
    }

    std::cout << " myset3 "<<std::endl;
    std::set<int> myset3 = myset2; // set을 그대로 복사합니다. 얕은복사가 이루어짐으로 주의해야합니다.  
    for(auto i = myset3.begin(); i!=myset3.end(); i++){
        std::cout<<*i<<std::endl;
    }
    


}