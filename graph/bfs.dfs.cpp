#include <iostream>
#include <vector>


class visited_vector{
    public:
    std::vector<int> visisted;


    bool is_visited(int data){
        for(int i : this -> visisted){
            if( i == data) return true;
        }
        return false;
    }

    void add_visit(int data){
        this -> visisted.push_back(data);
    }
};

struct node{
    int num;
    node* next = nullptr;
};
class QUEUE{
    private:

    node* front = nullptr;
    node* back= nullptr;
    int size = 0;
public:    
    void Enque(int n){

        
        node* cur = this -> back;
        
        node* temp = new node;
        temp -> num = n;
        
        if(this -> front == nullptr){
            this -> size = 1;
            this -> front = temp;
            this -> back = temp;
            return ;

        }

        cur -> next = temp;
        this -> back = temp;   
        this -> size ++;


    }
    int get_size(){
        return this->size;
    }
    int peek(){


        return this -> front ->num;
    }

    int Deque(){
        
        if(this -> size == 0){
            this -> front = nullptr;
            this -> back = nullptr;
        
            return -1;
        }


        int ans = this -> front ->num;
        node* temp = this -> front;
        
        
        
        this -> front = temp -> next;
        delete temp;
        this -> size --;
        return ans;

    }

};


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
                cur_edge = cur_edge -> next_edge;
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

            GRAPH_EDGE_LIST* cur_edge = cur_vertex ->head_edge;
            if(cur_edge->edge_num >_edge){
                cur_vertex ->head_edge = temp;
                temp->next_edge = cur_edge;
                return;
            }

            while(1){

                if(cur_edge -> next_edge == 0){
                    cur_edge -> next_edge = temp;
                    cur_vertex->tail_edge = temp;
                    break;
                }

                if(cur_edge ->next_edge->edge_num >_edge){
                    
                    temp->next_edge = cur_edge->next_edge;
                    cur_edge ->next_edge = temp;
                    break;
                }
               
                cur_edge = cur_edge->next_edge;
                
            }

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


    void dfs(int _vertex){
        visited_vector _visited;

        GRAPH_VERTEX_LIST* cur_vertex;
        GRAPH_EDGE_LIST* cur_edge;

        std::vector<int> dfs_stack;
        
        
        dfs_stack.push_back(_vertex);
        

        
        while(1){
            if(dfs_stack.empty() == true ) break;

            if(_visited.is_visited(dfs_stack.back()) == false){

                std::cout << dfs_stack.back() << " ";
                _visited.add_visit( dfs_stack.back() );   

                cur_vertex = this -> Serch_Vertex( dfs_stack.back() );
                dfs_stack.pop_back();
                if(cur_vertex == nullptr){
                    break;
                }
                cur_edge = cur_vertex -> head_edge;

                std::vector<int> upper_sort_stack;

                while(1){
                    if(cur_edge == nullptr) break;

                        upper_sort_stack.push_back( cur_edge -> edge_num );

                    
                    cur_edge = cur_edge -> next_edge;

                }

                for(int i : upper_sort_stack ){

                    int pop_val = upper_sort_stack.back();
                    upper_sort_stack.pop_back();
                    
                    dfs_stack.push_back(pop_val);
                    

                }
            }
            else{
                dfs_stack.pop_back();

            }
            
        
        }


    }


    void bfs(int _vertex){
        visited_vector _visited;
        QUEUE bfs_queue;

        bfs_queue.Enque(_vertex);




        while(1){
            if(bfs_queue.get_size() == 0)    break;
            
            if(_visited.is_visited(bfs_queue.peek()) == false   ){
                std::cout << bfs_queue.peek()<< " ";
                GRAPH_VERTEX_LIST *cur_vertex = this ->Serch_Vertex(bfs_queue.peek() );
                _visited.add_visit( bfs_queue.peek() );
                bfs_queue.Deque();
                if(cur_vertex == nullptr){
                    break;
                }
                GRAPH_EDGE_LIST* cur_edge =  cur_vertex -> head_edge;
                

                while(1){
                    if(cur_edge == nullptr) break;

                          bfs_queue.Enque(cur_edge->edge_num);
                    
                    cur_edge = cur_edge ->next_edge;

                }

                
            }
            else{
                bfs_queue.Deque();
            }
        }

        

    }

};

int main(){



GRAPH_LIST graph;

int vertex_num;
int edge_num;
int start_vertex;
std::cin>>vertex_num;
std::cin>>edge_num;
std::cin>> start_vertex;

for(int i= 0; i<edge_num; i++){
    int input_vertex;
    int input_edge;
    std::cin >> input_vertex;
    std::cin >> input_edge;
    graph.Add_Edge_Two_Way(input_vertex,input_edge);

}
 
graph.dfs(start_vertex);
std::cout << "\n";
graph.bfs( start_vertex);

}   