#include <iostream>
#include <vector>
/*
그래프(dfs, bfs)
- 행렬
- 리스트 
- 리스트(Vector)

*/



class GRAPH_ARR{

private:

    int row;
    int col;
    int **graph_arr;

public:

    GRAPH_ARR(int r,int c)
    : row(r),col(c){

        this -> graph_arr = new int*[r];
        for(int i = 0 ; i<r; i++ ){
            this -> graph_arr[i] =new int[c];
        }
    }

    ~GRAPH_ARR(){
        for(int i = 0; i< this ->row; i++ ){
            delete[]  graph_arr[i];
        }

        delete[] graph_arr;
    }




    void Add_Edge_One_Way(int _vertex, int _edge){
        this -> graph_arr[_vertex][_edge] = 1;
    }

    void Add_Edge_Two_Way(int _vertex, int _edge){
        Add_Edge_One_Way(_vertex, _edge);
        Add_Edge_One_Way(_edge, _vertex);
    }


    void Print_Graph(){
        for(int i = 0 ; i<this ->row; i++){

            std::cout << i << "  :  ";
            for(int j =0; j< this ->col; j++){
                std::cout << this -> graph_arr[i][j] << " ";
            }
            std::cout << "\n";
        }
    } 

};

//////////////////////////////////////////////// 

struct GRAPH_EDGE_LIST
{
    int edge_num;
    int weight;
    GRAPH_EDGE_LIST* next_edge = nullptr;

};

struct GRAPH_VERTEX_LIST
{
    int vertex_num;
    GRAPH_VERTEX_LIST* next_vertex = nullptr;
    GRAPH_EDGE_LIST* head_edge = nullptr;
    GRAPH_EDGE_LIST* tail_edge = nullptr;

};



class GRAPH_LIST{
private:

GRAPH_VERTEX_LIST* head_vertex = nullptr;
GRAPH_VERTEX_LIST* tail_vertex = nullptr;


GRAPH_VERTEX_LIST* Serch_Vertex(int target){

    GRAPH_VERTEX_LIST* cur_vertex = this -> head_vertex;

    while(1){
        if(cur_vertex == nullptr){
            break;
        }
        else if(cur_vertex ->vertex_num == target){
            break;
        }
        else{
            cur_vertex = cur_vertex -> next_vertex;
        }

    }
    return cur_vertex;
}

GRAPH_EDGE_LIST* Serch_Edge(int target_vertex,int target_edge){

    GRAPH_VERTEX_LIST* cur_vertex = Serch_Vertex(target_vertex);
    
    if(cur_vertex == nullptr){
        return nullptr;
    }
    else{
        GRAPH_EDGE_LIST* cur_edge = cur_vertex -> head_edge;

        while(1){
            if(cur_edge == nullptr){
                break; 
            }
            else if(cur_edge -> edge_num == target_edge){
               break;
            }
            else{
                cur_edge =cur_edge->next_edge;
            }
        }
        return cur_edge;
    }
    
}


void add_vertex(int _vertex){
    if(Serch_Vertex(_vertex) != nullptr){
        return ;
    }
    GRAPH_VERTEX_LIST* temp = new GRAPH_VERTEX_LIST;
    temp ->vertex_num = _vertex;


    if( this -> head_vertex == nullptr){
        this -> head_vertex = temp;
        this -> tail_vertex = temp;
    }
    else{
        this -> tail_vertex -> next_vertex = temp;
        this -> tail_vertex = temp;
    }

}

public:

    ~GRAPH_LIST(){
        GRAPH_VERTEX_LIST* cur_vertex = this -> head_vertex;
        GRAPH_EDGE_LIST* cur_edge;

        while(1){
            if(cur_vertex == nullptr) break;

            cur_edge = cur_vertex ->head_edge;
            GRAPH_VERTEX_LIST* delete_vertex = cur_vertex;

            while(1){

                if(cur_edge == nullptr){

                    cur_vertex = cur_vertex ->next_vertex;
                    delete delete_vertex;        
                    break;
                }

                GRAPH_EDGE_LIST* delete_edge = cur_edge;
                cur_edge = cur_edge->next_edge;
                delete delete_edge;
    
            }

        }


    }

    void Add_Edge_One_Way(int _vertex, int _edge){

        if(Serch_Edge(_vertex,_edge) != nullptr){
            return ;
        }

        GRAPH_EDGE_LIST* temp = new GRAPH_EDGE_LIST;
        temp -> edge_num =_edge;

        GRAPH_VERTEX_LIST* cur_vertex = Serch_Vertex(_vertex);

        if( cur_vertex == nullptr ){
            add_vertex(_vertex);
            cur_vertex = this -> tail_vertex;
            cur_vertex ->head_edge = temp;
            cur_vertex ->tail_edge = temp;
            return ;

        }
        else{

            GRAPH_EDGE_LIST* cur_edge = cur_vertex ->tail_edge;
            cur_edge -> next_edge = temp;
            cur_vertex -> tail_edge = temp; 
            return ;

        }

    }
    void Add_Edge_Two_Way(int _vertex, int _edge){
        Add_Edge_One_Way(_vertex,_edge);
        Add_Edge_One_Way(_edge,_vertex);
    }

    void Print_Graph(){
        GRAPH_VERTEX_LIST* cur_vertex = this ->head_vertex;
        while(1){
            if(cur_vertex == nullptr) break;

            std::cout << cur_vertex ->vertex_num << "  :  ";
            GRAPH_EDGE_LIST* cur_edge = cur_vertex ->head_edge;  

            while(1){
                if(cur_edge == nullptr){
                    cur_vertex = cur_vertex ->next_vertex;
                    break;
                }
                
                
                std::cout << cur_edge -> edge_num << " ";
                cur_edge = cur_edge ->next_edge;
            }
            std::cout<<"\n";
        }

    }



};

///////////////////////////////////////////////////////////////////////////

struct VERTEX{
    std::vector<int> edge_list;
    int vertex_num;

};

class GRAPH_VECTOR{
private:
std::vector< VERTEX > vertex_list;

int Vertex_Index(int _vertex){

    for(int i = 0; i< this -> vertex_list.size(); i++){
        if(this -> vertex_list[i].vertex_num == _vertex){
            return i;
        }

    }
    return -1;

}

void Add_Vertex(int _vertex){
    if(this -> Vertex_Index(_vertex) != -1) return ;

    VERTEX temp;
    temp.vertex_num = _vertex;
    vertex_list.push_back(temp);

}

int Edge_Index(std::vector<int>& _list,int _edge){
   for(int i=0; i< _list.size(); i++){
        
        if(_list[i]== _edge){
            return i;
        }
   } 
   return -1;
}

public:

void Add_Edge_One_Way(int _vertext, int _edge){
    
    int vertext_index = Vertex_Index(_vertext);
    if(vertext_index == -1){
        VERTEX temp;
        temp.vertex_num = _vertext;
        temp.edge_list.push_back(_edge);
        this -> vertex_list.push_back(temp);
        return;
    }

    if(Edge_Index( this -> vertex_list[vertext_index].edge_list, _edge) != -1 ) return;
    vertex_list[vertext_index].edge_list.push_back(_edge);

}

void Add_Edge_Two_Way(int _vertex, int _edge){
    Add_Edge_One_Way(_vertex,_edge);
    Add_Edge_One_Way(_edge,_vertex);
}

void Print_Graph(){
    for( int i=0; i < this->vertex_list.size(); i++){
        std::cout<< this -> vertex_list[i].vertex_num<< "  :  ";
        for(int j = 0; j< this -> vertex_list[i].edge_list.size(); j++){
            std::cout<< this -> vertex_list[i].edge_list[j] << " ";
        }
        std::cout<< "\n";
    }


}

};

int main(){





}   