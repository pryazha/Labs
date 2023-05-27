#ifndef BST_H
#define BST_H

#include <iostream>
#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>

using namespace std;

struct Node {
    Node *p;
    int key;
    Node *left;
    Node *right;
};

class BST {
public:
    void init(QGraphicsScene* scene, QGraphicsView* view);

    void preOrderWalk();
    void postOrderWalk();
    void inOrderWalk();

    void addNode(int a);
    void deleteNode(int val);
    void deleteNode(Node* p);
    void show();

    int countNodes();
    int countLevels();
    Node* findElem(int val);

private:
    int countNodes(Node* p);
    int countLevels(Node* p);

    void preOrderWalk(Node* p);
    void postOrderWalk(Node* p);
    void inOrderWalk(Node* p);

    Node* findSuccessor(int val);

    QByteArray _prepareGraph();
    void _graphWalk(Node* p,  QTextStream* stream);
    Node* findElem(int val, Node* p);

    Node* root;
    QGraphicsScene* scene;
    QGraphicsView* view;
};

#endif // BST_H
