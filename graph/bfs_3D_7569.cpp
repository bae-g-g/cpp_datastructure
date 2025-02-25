#include <iostream>
#include <vector>



struct index_3D{
    int H; // 층  i
    int N; // 세로  j
    int M; // 가로  k

    index_3D(int _h, int _n, int _m)
    :H(_h),N(_n),M(_m){}

    index_3D()
    :H(0),N(0),M(0){}

};


class Graph_3D{    //3차원 그래프 생성
protected:

    int H;
    int N;
    int M;
    int ***graph;

public:

    Graph_3D(int _h, int _n, int _m)
    :H(_h),N(_n),M(_m){
        graph = new int**[H];

        for(int i = 0; i < H; i++){
            graph[i] = new int*[N];

            for(int j = 0; j<N; j++){
                graph[i][j] = new int[M];
            }

        }
    }

    ~Graph_3D(){
        for(int i = 0; i < H; i++){
            for(int j = 0; j < N; j++){
                delete[] graph[i][j];
            }
            delete[] graph[i];
        }
        delete[] graph;
    }


    void update_edge(index_3D idx, int value){
        graph[idx.H][idx.N][idx.M] = value;
    }


    int get_edge(index_3D idx){
        return graph[idx.H][idx.N][idx.M];
    }

    void input_edge(){
        for(int i = 0; i < H; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < M; k++){
                    std::cin >> graph[i][j][k];
                }
            }
        }
    }
};

class bfs_3D : public Graph_3D{ // 토마토 bfs 실행 알고리즘 클래스
private:  
    int total_tomato_num;
    int cur_rippen_tomato_num;
    int day;

    index_3D* queue;
    int queue_size;
    int front;
    int rear;
    int queue_tomato_num;

public:

    bfs_3D(int _h,int _n,int _m):Graph_3D(_h,_n,_m){
        total_tomato_num = 0;
        cur_rippen_tomato_num = 0;
        day = 0;

        queue_size = _n*_m*_h + 1;
        queue = new index_3D[ queue_size ];
        front = 0;
        rear = 0;
        queue_tomato_num = 0;
    }

    void enque(index_3D idx){
        queue[rear] = idx;
        rear = (rear + 1) % queue_size;
        update_edge(idx,1);
        queue_tomato_num++;
    }

    index_3D deque(){
        if( front == rear){
            return index_3D(-1,-1,-1);
        }
        index_3D index_temp = queue[front];
        front = (front + 1) % queue_size;
        queue_tomato_num--;
        return index_temp;
    }


    void input_tomato(){
        for(int i = 0; i < H; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < M; k++){

                    int input;
                    std::cin >> input;
                    if(input == 1){
                        cur_rippen_tomato_num++;
                        total_tomato_num++;
                        enque(index_3D(i,j,k));
                    }
                    else if(input == 0){
                        total_tomato_num++;
                    }
                    
                    update_edge( index_3D(i,j,k),  input);

                }
            }
        }
    }


    void check_arround(index_3D idx){


        //각 실행에서 
        // 익은 토마토 ++ 
        //  enque
        // 큐 토마토 넘++  <- 이건  enque가 알아서 하네
        if(idx.H > 0){
            if( graph[idx.H-1][idx.N][idx.M] == 0   ){
                cur_rippen_tomato_num++;
                enque( index_3D( idx.H-1,idx.N,idx.M) );
            }    
        }
        if(idx.H < H-1){
            if( graph[idx.H+1][idx.N][idx.M] == 0   ){
                cur_rippen_tomato_num++;
                enque( index_3D( idx.H+1,idx.N,idx.M) );
            }
        }



        if(idx.N > 0){
            if( graph[idx.H][idx.N-1][idx.M] == 0   ){
                cur_rippen_tomato_num++;
                enque( index_3D( idx.H,idx.N-1,idx.M) );
            }    
        }
        if(idx.N < N-1){
            if( graph[idx.H][idx.N+1][idx.M] == 0   ){
                cur_rippen_tomato_num++;
                enque( index_3D( idx.H,idx.N+1,idx.M) );
            }
        }



        if(idx.M > 0){
            if( graph[idx.H][idx.N][idx.M-1] == 0   ){
                cur_rippen_tomato_num++;
                enque( index_3D( idx.H,idx.N,idx.M-1) );
            }    
        }
        if(idx.M < M-1){
            if( graph[idx.H][idx.N][idx.M+1] == 0   ){
                cur_rippen_tomato_num++;
                enque( index_3D( idx.H,idx.N,idx.M+1) );
            }
        }
        


    }

    bool oneday(){
     int today_rippen_num = queue_tomato_num;
     
     for(int i = 0; i< today_rippen_num; i++){
        index_3D temp = deque();
        check_arround(temp);   
     }

    if(queue_tomato_num == 0 ){
       
        return false;
     }


     
     day++;
     return true;
     
    }

    int resulet(){
        if(total_tomato_num == cur_rippen_tomato_num){
            return day;
        }
        else{
            return -1;
        }
    }
    
};


int main(){
    int _n;
    int _m;
    int _h;
    std::cin >> _m;
    std::cin >> _n;
    std::cin >> _h;
    bfs_3D my_tomato_box(_h,_n,_m);
    my_tomato_box.input_tomato();
    while(my_tomato_box.oneday() == true){
        
    };
    std::cout<<my_tomato_box.resulet()<<std::endl;

}