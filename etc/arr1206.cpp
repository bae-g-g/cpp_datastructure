
/*
swea1206
https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV134DPqAA8CFAYh&categoryId=AV134DPqAA8CFAYh&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1

별다른 자료구조가 필요할것같지 않음
현재 - 양옆으로 min값이 양수라면 min만큼 조망권이 확보된다.
그 외의 경우 조망권이 확보되지 않는다.

*/
#include <iostream>

int calculate(int* arr, int cur_index){

    int min = arr[cur_index] - arr[cur_index-2]; 
    for(int i = cur_index -1; i<=cur_index+2; i++){
        if(cur_index == i) continue;
        
        if( arr[cur_index] - arr[i] < min ){
            min = arr[cur_index] - arr[i];
        }
    }
    if(min > 0){
        return min;
    }
    else{
        return 0;
    }

}

int input(const int num){
    
    int* arr = new int[num];
    int ans = 0;
    for(int i = 0 ; i< num; i++){
        std::cin >> arr[i];
        if(i > 1){
            ans += calculate(arr,i-2);
        }
    }
    delete[] arr;
    return ans;
}

int main(){
    for(int i = 1; i<11; i++){
        int _input;
        std::cin>> _input;
        std::cout<< "#"<<i << " " << input(_input) << std::endl;
    }
    


}