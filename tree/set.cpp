#include <iostream>


/*

set을 구현합니다

중복을 허용하지 않고,정렬된 상태를 유지하는 자료구조입니다.



read-black tree로 삽입,삭제가 logN을 보장하도록 하는 것이 효율적이지만
간단한 구현을 위해 bst로 구현하엿습니다.

*/

struct setstruct{
    int a;
    int b;

    setstruct(int _a, int _b)
    : a(_a),b(_b){}
};

template < typename T>

struct TreeNode{
    
    T data;
    TreeNode* left;
    TreeNode* right;


    TreeNode(T _data)
    :data(_data),left(nullptr),right(nullptr){}

};


template <typename T>

class set{

private:
    TreeNode<T> *root = nullptr;
    int tree_size = 0;

public:

    bool AddNode(T _input){
        TreeNode<T>* _newnode = new TreeNode<T>(_input);

        if(root == nullptr){
            root = _newnode;
            tree_size++;
            return true;
        }

        TreeNode<T>* cur_node = root;

        while(1){

            
            if(cur_node->data < _input){
                if(cur_node->right == 0){
                    cur_node -> right = _newnode;
                    tree_size++;
                    return true;
                }
                else{
                    cur_node = cur_node ->right;
                }
            }
            else if( cur_node->data > _input){
                if(cur_node -> left == 0){
                    cur_node -> left = _newnode;
                    tree_size++;
                    return true;
                }
                else{
                    cur_node = cur_node ->left;
                }
            }
            else if( cur_node -> data == _input){
                delete _newnode;
                return false;
            }
        }    

    }

    TreeNode<T>* find(T _data){
        TreeNode<T>* cur_node = root;
        if(root == nullptr){
            return nullptr;
        }

        while(1){
            if(cur_node == nullptr){
                return nullptr;
            }

            if(cur_node -> data == _data){
                return cur_node;
            }
            else if(cur_node -> data < _data){
                cur_node = cur_node -> right;
            }
            else if(cur_node -> data > _data){
                cur_node = cur_node -> left;
            }
        }

    }
    /////////del_nod

    int count_child(TreeNode<T>* input){
        int res = 0 ;
        if(input -> right != nullptr) res++;
        if(input -> left != nullptr) res++;
        return res;
    }

    void del_zero_child(TreeNode<T>* cur_node,TreeNode<T>* p_node ){
        if(p_node == nullptr){
            root = nullptr;
        }
        else if( p_node ->left == cur_node){
            p_node ->left = nullptr;
        }
        else{
            p_node-> right =nullptr;
        }
        delete cur_node;    
        tree_size--;
    }
    void del_one_child(TreeNode<T>* cur_node,TreeNode<T>* p_node){
        
        TreeNode<T>* sub_node = nullptr;
        if(cur_node ->left != nullptr) sub_node = cur_node->left;
        if(cur_node ->right != nullptr) sub_node = cur_node->right;
        
        if(p_node == nullptr){
            root = sub_node;
        }
        else if( p_node ->left == cur_node){
            p_node ->left = sub_node;
        }
        else{
            p_node->right = sub_node;
        }
        delete cur_node;    
        tree_size--;

    }

    void del_two_child(TreeNode<T>* cur_node,TreeNode<T>* p_node){

        TreeNode<T>* sub_node = cur_node -> right;
        TreeNode<T>* p_sub_node = cur_node;
       
        while(1){
            if(sub_node -> left == nullptr) break;
            p_sub_node = sub_node;
            sub_node = sub_node ->left;
        } 


        if(sub_node->right != nullptr){
            if(p_sub_node ->left == sub_node ){
                p_sub_node ->left = sub_node->right;
            }
            else{
                p_sub_node -> right =sub_node->right;
            }

        }
        if(p_node == nullptr){
            root = sub_node;
        }
        else if(p_node->left == cur_node){
            p_node ->left = sub_node;
        }
        else{
            p_node -> right = sub_node;
        }
        sub_node ->right =cur_node ->right;
        sub_node ->left =cur_node ->left;

        delete cur_node;
        tree_size--;

    };


    bool DelNode(T _data){
        
        TreeNode<T>* par_node =nullptr;
        TreeNode<T>* cur_node =nullptr;
        cur_node = root;

        while(1){
            if(cur_node == nullptr){
                return false;
            }

            if(cur_node -> data == _data){
                break;
            }
            else if(cur_node -> data < _data){
                par_node = cur_node;
                cur_node = cur_node -> right;
            }
            else if(cur_node -> data > _data){
                par_node = cur_node;
                cur_node = cur_node -> left;
            }
        }

        int child_node_num = count_child(cur_node);
        if(child_node_num == 0) del_zero_child(cur_node,par_node);
        if(child_node_num == 1) del_one_child(cur_node,par_node);
        if(child_node_num == 2) del_two_child(cur_node,par_node);

        return true;
        
        

    }

    void inoder_traval(TreeNode<T>* node){
       
        if(node ->left !=nullptr ) inoder_traval(node->left);
        std::cout<<node->data<<" ";
        if(node -> right != nullptr) inoder_traval(node ->right);
        
    }
    

    TreeNode<T>* get_root(){
        return root;
    }

};


int main(){


   set<int> a;
   a.AddNode(4);
   a.AddNode(1);
   a.AddNode(2);
   a.AddNode(3);
   a.AddNode(5);
   a.AddNode(6);
   a.AddNode(6);
   a.AddNode(6);
   a.AddNode(6);
   a.DelNode(6);

   a.inoder_traval(a.get_root());


}