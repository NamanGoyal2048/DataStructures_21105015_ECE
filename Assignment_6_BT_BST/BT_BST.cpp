/ *NAMAN GOYAL
    21105015
    ECE
    */

#include<iostream>
using namespace std;

template <typename t>
class Binarytreenode{
    public:
        t data;
        Binarytreenode<t>* left;
        Binarytreenode<t>* right;

        Binarytreenode(t data){
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~Binarytreenode(){
            delete(left);
            delete(right);
        }
};

class BST{
    Binarytreenode<int>* root;

    Binarytreenode<int>* insertnodenodehelper(int data, Binarytreenode<int>* node){
        if (node == NULL){
            Binarytreenode<int>* tmp = new Binarytreenode<int>(data);
            return tmp;
        }

        if (node->data > data){
            node->left = insertnodenodehelper(data, node->left);
        }
        else{
            node->right = insertnodenodehelper(data, node->right);
        }
        return node;
    }

    int minimum(Binarytreenode<int>* nood){
        if (nood == NULL){
            return -1;
        }

        while(nood->left != NULL){
            nood = nood->left;
        }

        return nood->data;
    }

    Binarytreenode<int>* deletenodehelper(int data, Binarytreenode<int>* node){
        if (node == NULL){
            return NULL;
        }

        if (node->data == data){
            if ((node->left == NULL)&&(node->right == NULL)){
                delete node;
                return NULL;
            }
            else if ((node->left == NULL)&& (node->right != NULL)){
                Binarytreenode<int>* tmp = node->right;
                node->right = NULL;
                delete node;
                return tmp;
            }
            else if ((node->left != NULL)&& (node->right == NULL)){
                Binarytreenode<int>* tmp = node->left;
                node->left = NULL;
                delete node;
                return tmp;
            }
            else{
                int min = minimum(node->right);
                node->data = min;
                node->right = deletenodehelper(min,node->right);
                return node;
            }
        }
        else if (node->data > data){
            node->left = deletenodehelper(data, node->left);
        }
        else{
            node->right = deletenodehelper(data, node->right);
        }
        return node;
    }

    public:
        BST(){
            root = NULL;
        }

        ~BST(){
            delete root;
        }

        void insertnode(int* data, int size){
            for(int i = 0; i < size; i++){
                this->root = insertnodenodehelper(data[i], root);
            }
        }

        void deletenode(int data){
            this->root = deletenodehelper(data, root);
        }

    private:
        void printhelper(Binarytreenode<int>* nood){
            if(nood == NULL){
                return;
            }

            cout << nood->data << ":";
            if (nood->left){
                cout << " L" << nood->left->data;
            }
            if (nood->right){
                cout << " R" << nood->right->data;
            }
            cout << endl;

            printhelper(nood->left);
            printhelper(nood->right);
        }
    
    public:
        void print(){
            printhelper(root);
        }
};

void print_Arr(int* arr, int size){
    for(int i = 0; i< size; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void deletedataarr(int data, int* arr, int size){
    int i = 0;
    for(; i<size; i++){
        if (arr[i] == data){
            break;
        }
    }
    for(; i<size; i++){
        arr[i] = arr[i+1];
    }
    return;
}

int main(){
    int input_arr[] = {4,5,8,1,11,9,3,4,5,8,7,56};
    cout << "Initial array taken to create BST"<< endl;
    print_Arr(input_arr,12);
    
    BST asg;
    asg.insertnode(input_arr,12);
    
    cout << "BST created from the array taken." << endl;
    cout << "Output format:" << endl;
    cout << "node_Data: L(data_at_left_node) R(data_at_right_node)" << endl;
    asg.print();
    cout << endl;

    deletedataarr(11,input_arr,12);
    cout << "Arr after deleting 76 from it." << endl;
    print_Arr(input_arr,11);

    asg.deletenode(11);
    cout << "BST after deleting 76 from it." << endl;
    asg.print();
    cout << endl;

    cout << "Space complexity analysis:" << endl << endl;
    cout << "To save data in arr we use (4 bytes * size_of_arr) that is to save 9 int we used 9*4 = 36 bytes of data." << endl << endl;
    cout << "To save single int in BST we use (4 bytes + 2*8 bytes = 20bytes) of space. To save n int we use (20 bytes * size_of_arr) ie to save 9 int we used 9*20 = 180 bytes of data." << endl << endl;
    cout << "Therefore we are using a lot more space in BST than the arr. Hence in terms of space complexity array is much better." << endl << endl;
    return 0;
}
