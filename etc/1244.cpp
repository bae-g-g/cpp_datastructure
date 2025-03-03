#include <iostream>
#include <set>




class Myclass{

private:

int input_num;
int swap_num;
int max_num;
int size;
public:

int arr_to_num(int* arr){
    int ans = 0;
    int temp = 1;
    for(int i =0 ; i<size; i++){
        ans += arr[size -1 -i]*temp;
        temp *= 10;
    }
    return ans;
}
int* num_to_arr(int num,int* arr){
    
    for(int i =0; i<size; i++){
        arr[size -1 -i] = num%10;
        num /=10;
    }

}

void szie_cheek(){
    int temp = 10;
    size = 1;
    while(1){
        if(input_num/temp == 0) return;
        temp*=10;
        size++;
    }    
}

void max_cheek(){
    int temp_arr[6] = {0};
    num_to_arr(input_num,temp_arr);
    int max_arr[6] = {0};
    for(int i = 0 ; i<size; i++){
        int max = 0;
        int max_index =0 ;
        for(int j= 0; j<size; j++){
            if(temp_arr[j]> max){
                max_index = j;
                max = temp_arr[j];
            }
        }
        max_arr[i] = max;
        temp_arr[max_index] = -1;

    }
    max_num = arr_to_num(max_arr);
}

void input(){

    std::cin>>input_num;
    std::cin>>swap_num;
    szie_cheek();
    max_cheek();


}

void swap(int* arr,int id1,int id2){
    int temp = arr[id1];
    arr[id1] = arr[id2];
    arr[id2] = temp;
}

void dfs(int dfs_swap_num,int dfs_num, std::set<std::pair<int,int>> myset, int& max,int& max_swap_num){
   
    if(dfs_num > max ){
       max = dfs_num;
       max_swap_num = dfs_swap_num;          
    }
    if(dfs_num == max){
        if(max_swap_num < dfs_swap_num){
            max_swap_num = dfs_swap_num;
        }
    }

    if(dfs_swap_num == 0) return ;

    // if(max == max_num){
    //     return;
    // }

    dfs_swap_num--;
    int temp_arr[6] = { 0 };
    num_to_arr(dfs_num,temp_arr);
    for(int i =0; i< size - 1; i++){
        for(int j = i; j<size; j++){
            if(myset.find({i,j}) == myset.end() ){
                myset.insert({i,j});
                swap(temp_arr,i,j);
                int temp_num = arr_to_num(temp_arr);
                
                    if(temp_num >= dfs_num){
    
                        dfs(dfs_swap_num,temp_num,myset,max,max_swap_num);
                
                    }
                        
                
                
                swap(temp_arr,i,j);
            }
            
        }
    }

}

void fn(){
    std::set<std::pair<int,int>> myset;
    int max = 0;
    int cur_swap_num = 0;

    dfs(swap_num,input_num,myset,max,cur_swap_num);
    std::cout<<max<<std::endl;
    std::cout<<cur_swap_num<<std::endl;
    
    if(cur_swap_num == 0){
        std::cout<<max<<std::endl;
    }
    else{
        int count_arr[10]= {0};
        int temp_arr[6] ={0};
        int flag = 0;
        num_to_arr(max,temp_arr);
        for(int i =0; i<size; i++){
            count_arr[temp_arr[i]]++;
            if(count_arr[temp_arr[i]]>1){
                std::cout<<max<<std::endl;
                return ;
            }
        }
        if(cur_swap_num%2 == 0){
            std::cout<<max<<std::endl;
        }
        else{
            swap(temp_arr,size-1,size-2);
            std::cout<<arr_to_num(temp_arr)<<std::endl;
        }
        



    }

}


};


int main(){

    int test_case;
    std::cin>>test_case;
    for(int i = 1 ; i<=test_case; i++){
        std::cout << "#"<<i<< " ";
        Myclass a;
        a.input();
        a.fn();
    }



}