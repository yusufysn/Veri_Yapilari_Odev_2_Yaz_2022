/** 
* @file        : AVL.cpp
* @description : AVL agacini olusturuyor.
* @course Dersi: Yaz Donemi 1. Ogretim B Grubu 
* @assignment  : 2. Odev
* @date        : 17.08.2022
* @author      : Yusuf Yesin
*/
#include "AVL.hpp"

Node* AVL::SearchAndAdd(Node *subNode,const int& item, int *array, const int& size){
    if(subNode == NULL) subNode = new Node(item,array,size);
    else if(item < subNode->data){
        subNode->left = SearchAndAdd(subNode->left,item,array,size);
        
        if(Height(subNode->left) == Height(subNode->right)+2){
            if(item < subNode->left->data){
                DeleteLastElement(subNode); //ilk dugum
                if(subNode->right!=NULL) postorderlaMaxDegeriSil(subNode->right); //var ise ilk dugumun sagi
                DeleteFirstElement(subNode->left); //ilk dugumun solu
                postorderlaMinDegeriSil(subNode->left->left);
                subNode = SwapWithLeftChild(subNode);
            }
            else{
                DeleteLastElement(subNode->left);//aşağı indi
                DeleteFirstElement(subNode->left->right);//yukarı çıktı
                subNode->left = SwapWithRightChild(subNode->left);
                
                DeleteLastElement(subNode); //ilk dugum
                if(subNode->right!=NULL) postorderlaMaxDegeriSil(subNode->right); //var ise ilk dugumun sagi
                DeleteFirstElement(subNode->left); //ilk dugumun solu
                postorderlaMinDegeriSil(subNode->left->left);
                
                subNode = SwapWithLeftChild(subNode);
            }
        }
    }
    else if(item > subNode->data){
        subNode->right = SearchAndAdd(subNode->right,item,array,size);
        
        if(Height(subNode->right) == Height(subNode->left)+2){
            if(item > subNode->right->data){
                DeleteLastElement(subNode); //ilk dugum
                if(subNode->left!=NULL) postorderlaMaxDegeriSil(subNode->left); //var ise ilk dugumun solu
                DeleteFirstElement(subNode->right); // ilk dugumun sagi
                postorderlaMinDegeriSil(subNode->right->right);
                subNode = SwapWithRightChild(subNode);
            }
            else{
                DeleteLastElement(subNode->right);//aşağı indi
                DeleteFirstElement(subNode->right->left);//yukarı çıktı
                subNode->right = SwapWithLeftChild(subNode->right);

                DeleteLastElement(subNode); //ilk dugum
                if(subNode->left!=NULL) postorderlaMaxDegeriSil(subNode->left); //var ise ilk dugumun sagi
                DeleteFirstElement(subNode->right); //ilk dugumun sagi
                postorderlaMinDegeriSil(subNode->right->right);

                subNode = SwapWithRightChild(subNode);
            }
        }
    }
    else;
    
    subNode->height = Height(subNode);
    return subNode;
}

Node* AVL::SwapWithLeftChild(Node *subNode){
    Node *tmp = subNode->left;
    subNode->left = tmp->right;
    tmp->right = subNode;
    
    subNode->height = Height(subNode);
    tmp->height = 1+max(Height(tmp->left),subNode->height);
    
    return tmp;
}

Node* AVL::SwapWithRightChild(Node *subNode){
    Node *tmp = subNode->right;
    subNode->right = tmp->left;
    tmp->left = subNode;
    
    subNode->height = Height(subNode);
    tmp->height = 1+max(Height(tmp->right),subNode->height);
    
    return tmp;
}

int AVL::Height(Node *subNode){
    if(subNode == NULL) return -1;
    return 1+max(Height(subNode->left),Height(subNode->right));
}

void AVL::preorder(Node *subNode){
    if(subNode != NULL){
        cout<<endl;
        cout<<subNode->data<<": ";
        
        for (size_t i = 0; i < subNode->size; i++)
        {
            cout<<subNode->array[i]<<" ";                
        }
        cout<<endl;
        preorder(subNode->left);
        preorder(subNode->right);
        
    }
}

void AVL::postorderlaMinDegeriSil(Node *subNode){
    if(subNode != NULL){
        postorderlaMinDegeriSil(subNode->left);
        postorderlaMinDegeriSil(subNode->right);
        if (subNode->size > 0) {
            DeleteFirstElement(subNode);
        }
    }
}

void AVL::postorderlaMaxDegeriSil(Node *subNode){
    if(subNode != NULL){
        postorderlaMaxDegeriSil(subNode->left);
        postorderlaMaxDegeriSil(subNode->right);
        if (subNode->size > 0) {
            DeleteLastElement(subNode);
        }
    }
}

bool AVL::DeleteNode(Node *&subNode){
    Node *delNode = subNode;
    
    if(subNode->right == NULL) subNode = subNode->left;
    else if(subNode->left == NULL) subNode = subNode->right;
    else{
        delNode = subNode->left;
        Node *parentNode = subNode;
        while(delNode->right != NULL){
            parentNode = delNode;
            delNode = delNode->right;
        }
        subNode->data = delNode->data;
        if(parentNode == subNode) subNode->left = delNode->left;
        else parentNode->right = delNode->left;
    }
    delete delNode;
    return true;
}

bool AVL::Search(Node *subNode,const int& item){
    if(subNode == NULL) return false;
    if(subNode->data == item) return true;
    if(item < subNode->data) return Search(subNode->left,item);
    else return Search(subNode->right,item);
}

AVL::AVL(){
    root = NULL;
}

bool AVL::isEmpty()const{
    return root == NULL;
}

void AVL::Add(const int& item,int *array, const int& size){
    root = SearchAndAdd(root,item,array,size);
}

void AVL::preorder(){
    preorder(root);
}

int AVL::Height(){
    return Height(root);
}

void AVL::Clear(){
    while(!isEmpty()) DeleteNode(root);
}

void AVL::DeleteFirstElement(Node* subNode){
    if(subNode->size > 0){
        cout << subNode->data << " nolu dugum yukari ciktigi icin en kucuk " << subNode->array[0] << " sayisi silinmistir." << endl;
        for (size_t i = 1; i < subNode->size; i++)
        {
            subNode->array[i-1] = subNode->array[i];
        }
        subNode->size--;
    }
}

void AVL::DeleteLastElement(Node* subNode){
    if(subNode->size > 0){
        cout << subNode->data << " nolu dugum asagi indigi icin en buyuk " << subNode->array[subNode->size-1] << " sayisi silinmistir." << endl;
        subNode->size--;
    }
}

void AVL::SayilariAgacaEkle(){
    DosyaOku *dosya = new DosyaOku();
    dosya->sayilariSirala();
    for (size_t i = 0; i < dosya->satirSayisi; i++)
    {
        Add(dosya->sayilarToplami[i],dosya->sayilar[i],dosya->satirdakiElemanSayisi->getElement(i));
    }
    delete dosya;
}

AVL::~AVL(){
    Clear();
}
