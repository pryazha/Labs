#include "bst.h"
#include <QApplication>
using namespace std;

int main(int argc, char **argv){
    QApplication app(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    view.setRenderHints(QPainter::SmoothPixmapTransform);

    BST* Tree = new BST();
    Tree->init(&scene, &view);

    Tree->addNode(7);
    Tree->addNode(6);
    Tree->addNode(10);
    Tree->addNode(3);
    Tree->addNode(4);
    Tree->addNode(5);
    Tree->addNode(8);
    Tree->addNode(12);
    Tree->addNode(9);
    Tree->addNode(1);
    Tree->addNode(2);
    Tree->addNode(11);

    cout << "Tree height: " << Tree->countLevels() << endl;
    cout << "Number of nodes: " << Tree->countNodes() << endl;
    cout << "Find element: " << Tree->findElem(12) << " : " << Tree->findElem(12)->key << endl;

    Tree->preOrderWalk();
    Tree->inOrderWalk();
    Tree->postOrderWalk();

    Tree->show();

    return app.exec();
}
