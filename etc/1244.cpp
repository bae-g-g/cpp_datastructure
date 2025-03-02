#include <iostream>


/*
입력 받은 정수를 문자열로 쪼갠다

이후에 중복이 있는값 slection sort 진행 <- 아님 시발

1288

1 - 8281 - big
2 - 8821 - big
------
1 - 8218 - small
2 - 8812 - samll

================
2188

1 - 8182 - big
2 - 8812 small
-------
1 - 8128  -small
2 - 8821 big

15599


95591

99551
----




backtraking

index  <- comp;
for(int i = 0 ; i< size-1; i++){
    for(int j = i+1; j<size; j++){
        swap(i,j);
        eche value comp  
        
        compli -> max  push (  )
        swap(j,i);   
    }
}

사이즈/2 만큼 교환을 하면 최대값을 찾을 수 있음
-> 1234
-> 4231
-> 4321  


----------------------------------------
same value arr[10] ={ 0 };
same_value_arr[ arr[i] ]++;
if(samevaluearr[i]) > 1 
samevalue exist = true;



swap_value = swap_value - same_value_num;


if( swap_valu > size ) n-1
=  if (same value exist) 최대값 
=  if ( same value non ) 최대값  <-> 그 다음 최대값



else( swap_value < size)
-> if(same value exist) greed;
-> if(same value non ) -> backtraking (samevalue)



------------



*/


class MyClass{

private:
    int arr_num[6] = {0};
    int size = 0;
    int int_num;
    int swap_num;

public:

    int arr_to_num(int* arr){
        int ans = 0;
        int temp = 1;
        for(int i =0; i<size; i++){
            ans += arr_num[size-1-i]*temp;
            temp *= 10;
        }
        return ans;
    }
    
    void num_to_arr(int* arr, int num){

        for(int i =0 ; i<size; i++){
            arr[size -1 -i] = num%10;
            num = num/10;
        }

    }
    void size_cheek(int num){
        if(num == 0){
            return ;
        }
        else{
            size++;
        }
        int temp = 1;

        for(int i =0 ; i<6; i++){
            if( temp <= num || temp*10 > num ){
                return;
            }
            else{
                size++;
                temp *=10;
            }
        }
    }

    void input(){
        std::cin >> int_num;
        std::cin >> swap_num;
        size_cheek(int_num);
        num_to_arr(arr_num,int_num);
    }

    int fn(){


        if( ){

        }
        else{

        }

    }



};


int main(){

}