/** 
* @file        : Node.cpp
* @description : Dugum veri yapisini olusturuyor.
* @course Dersi: Yaz Donemi 1. Ogretim B Grubu 
* @assignment  : 2. Odev
* @date        : 17.08.2022
* @author      : Yusuf Yesin
*/
#include "Node.hpp"

Node::Node(const int& data, int* array, const int& size, Node* left, Node* right){
    this->data = data;
    this->size = size;
    this->array = array;
    this->left = left;
    this->right = right;
    this->height = 0;
}

Node::~Node(){
    if(this->array != NULL){
        delete [] this->array;
    }
}