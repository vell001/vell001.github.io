#include <stdio.h>
#include <iostream.h>
#include <windows.h>
using namespace std;

typedef struct Node{
    int value;
    struct Node *parentNode;
    struct Node *brotherNode;
    struct Node *childNode;
}Node, *Tree;

Tree createTree(){
    Tree tree;
    Node *node, *cup, *bro;
    tree = (Node *)malloc(sizeof(Node));
    node = tree;
    cup = tree; // 1
    
    node->parentNode = NULL;
    node->brotherNode = NULL;
    node->childNode = (Node *)malloc(sizeof(Node));
    node->value = 1;
    
    node = node->childNode;
    
    node->parentNode = tree;
    node->brotherNode = (Node *)malloc(sizeof(Node));
    node->childNode = (Node *)malloc(sizeof(Node));
    node->value = 2;
    
    cup = node; // 2
    node = node->brotherNode;
    
    node->parentNode = tree;
    node->brotherNode = NULL;
    node->childNode = NULL;
    node->value = 3;
    
    node = cup->childNode;
    
    node->parentNode = cup;
    node->brotherNode = (Node *)malloc(sizeof(Node));
    node->childNode = (Node *)malloc(sizeof(Node));
    node->value = 4;
    
    node = node->brotherNode;
    
    node->parentNode = cup;
    node->brotherNode = (Node *)malloc(sizeof(Node));
    node->childNode = NULL;
    node->value = 5;
    
    node = node->brotherNode; 
    
    node->parentNode = cup;
    node->brotherNode = NULL;
    node->childNode = NULL;
    node->value = 6;
    
    cup = cup->childNode; // 4
    node = cup->childNode;
    
    node->parentNode = cup;
    node->brotherNode = NULL;
    node->childNode = (Node *)malloc(sizeof(Node));
    node->value = 7;
    
    cup = cup->childNode; // 7
    node = cup->childNode;
    
    node->parentNode = cup;
    node->brotherNode = (Node *)malloc(sizeof(Node));
    node->childNode = NULL;
    node->value = 8;
    
    node = node->brotherNode;
    
    node->parentNode = cup;
    node->brotherNode = NULL;
    node->childNode = (Node *)malloc(sizeof(Node));
    node->value = 9;
    
    cup = node; // 9
    node = cup->childNode;
    
    node->parentNode = cup;
    node->brotherNode = NULL;
    node->childNode = (Node *)malloc(sizeof(Node));
    node->value = 10;
    
    cup = cup->childNode; // 10
    node = cup->childNode;
    
    node->parentNode = cup;
    node->brotherNode = NULL;
    node->childNode = NULL;
    node->value = 11;
    
    return tree;
}

Node *next(Node *node, int flag=0){ //flag用判断当前结点的`childNode`是否被遍历过了
    if(flag != 0){
        if(node->brotherNode != NULL)
            return node->brotherNode;
        else if(node->parentNode != NULL)
            return next(node->parentNode, 1);
        else 
            return NULL;
    }
    if(node->childNode != NULL)
        return node->childNode;
    else if(node->brotherNode != NULL)
        return node->brotherNode;
    else if(node->parentNode != NULL)
        return next(node->parentNode, 1);
}
/*
Node *next(Node *node){
	if(node == NULL) return NULL;
    if(node->childNode != NULL)
        return node->childNode;
    else if(node->brotherNode != NULL)
        return node->brotherNode;
    else if(node->parentNode != NULL)
        return next(node->parentNode->brotherNode); // 这个退出问题很严重啊
}
*/
void recursion(Node *node){
    if(node == NULL) return;
    
    cout << node->value << " ";
    
    recursion(node->childNode);
    recursion(node->brotherNode);
}

int main(){

    Tree tree = createTree();

    recursion(tree);
    cout << endl;

    Node *node = tree;
    while(node != NULL){
        cout << node->value << " ";
        node = next(node);
    }
    
    cout << endl;

    system("pause");
    return 0;
}
