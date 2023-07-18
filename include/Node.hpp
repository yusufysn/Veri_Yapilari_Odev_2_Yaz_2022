#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
using namespace std;
class Node{
public:
    int data, size, height;
    int* array;
    Node* left;
    Node* right;
    Node(const int& = 0, int* = 0, const int& = 0, Node* = 0, Node* = 0);
    ~Node();
    void printScreen();
};
#endif