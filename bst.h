#ifndef BST_H
#define BST_H
#include<iostream>
#include <string>
using namespace std;

class BST
{
    struct node
    {
        string data;
        node * left = nullptr;
        node * right = nullptr;
        node * parent = nullptr;
    };
    node* root = nullptr;
    node* last = nullptr;
    int depth = 0;
 int c = 0;
 int addC = 0;


public:
    BST()=default;
    void add ( string x, node * t );
    void insert (string x);
    void print(node * t);
    void show();
    int getD() {return depth;}
    node* search(string x){if(root) return find(x, root);} //if wykona sie jesli root nie jest pusty; jesli cos jest to true
    node* find(string x,node* t);

 int getC() {return c;}
    void removeLast();
    void updateDepth(node* t,int glebokosc);

    int getaddC() {return addC;}




};



#endif // BST_H

