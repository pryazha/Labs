#include "bst.h"

void BST::init(QGraphicsScene* scene, QGraphicsView* view) {
    this->root = NULL;
    this->scene = scene;
    this->view = view;
}

void BST::addNode(int a) {
    Node* tmp = new Node;
    tmp->key = a;
    tmp->left = NULL;
    tmp->right = NULL;

    if (this->root == NULL) {
        tmp->p = NULL;
        this->root = tmp;
    } else {
        Node* cElem = this->root;
        Node* parent = NULL;

        while (cElem != NULL) {
            parent = cElem;
            cElem = (a < cElem->key) ? cElem->left : cElem->right;
        }

        tmp->p = parent;
        if (a < parent->key)
            parent->left = tmp;
        else
            parent->right = tmp;
    }
}

void BST::preOrderWalk(Node* p) {
    if (p != NULL) {
       cout << p->key << " ";
       this->preOrderWalk(p->left);
       this->preOrderWalk(p->right);
    }
}
void BST::preOrderWalk() {
    cout << "Preorder walk: ";
    this->preOrderWalk(this->root);
    cout << endl;
}

void BST::postOrderWalk(Node* p) {
        if (p != NULL) {
           this->postOrderWalk(p->left);
           this->postOrderWalk(p->right);
           cout << p->key << " ";
        }
}
void BST::postOrderWalk() {
    cout << "Postorder walk: ";
    this->postOrderWalk(this->root);
    cout << endl;
}

void BST::inOrderWalk(Node* p) {
        if (p != NULL) {
           this->inOrderWalk(p->left);
           cout << p->key << " ";
           this->inOrderWalk(p->right);
        }
}
void BST::inOrderWalk() {
    cout << "Inorder walk: ";
    this->inOrderWalk(this->root);
    cout << endl;
}

Node* BST::findElem(int value, Node* p) {
    if (p != NULL) {
        if (value == p->key)
            return p;

        if (value < p->key)
            return findElem(value, p->left);
        else
            return findElem(value, p->right);
    } else
        return NULL;
}

Node* BST::findElem(int value) {
    return this->findElem(value, this->root);
}

Node* BST::findSuccessor(int value) {
    Node* startNode = this->findElem(value);
    Node* parent = startNode;
    startNode = startNode->right;
    while (startNode != NULL && startNode->left != NULL){
        parent = startNode;
        startNode = startNode->left;
    }
    return startNode;
}

void BST::deleteNode(Node* p) {
    Node *q = NULL;
    Node *r = NULL;

    if (p->left == NULL || p->right == NULL)
        q = p;
    else
        q = this->findSuccessor(p->key);

    if (q->left != NULL)
        r = q->left;
    else
        r = q->right;

    if (r != NULL)
        r->p = q->p;

    if (q->p == NULL)
        this->root = r;
    else if (q == q->p->left)
        q->p->left = r;
    else
        q->p->right = r;

    if (q != p)
        p->key = q->key;
}

void BST::deleteNode(int val) {
    this->deleteNode(this->findElem(val));
}

int BST::countLevels(Node* p) {
    int h1 = 0, h2 = 0;
    if (p == NULL)
        return 0;

    if (p->left)
        h1 = countLevels(p->left);
    if (p->right)
        h2 = countLevels(p->right);

    return(max(h1,h2)+1);
}

int BST::countLevels() {
    return this->countLevels(this->root);
}

int BST::countNodes(Node* p) {
    if(p == NULL)
        return 0;
    else
        return (countNodes(p->left) + countNodes(p->right)+1);
}

int BST::countNodes() {
    return this->countNodes(this->root);
}

void BST::_graphWalk(Node* p, QTextStream *stream) {
    if (p != NULL) {
        *stream << "\t\t" << "n" << p->key << "[label=\"" << p->key << "\"];" << endl;
        if (p->left != NULL) {
            *stream << "\t\tn" << p->key << "--" << "n" << p->left->key << ";" << endl;
            this->_graphWalk(p->left, stream);
        }
        if (p->right != NULL) {
            *stream << "\t\tn" << p->key << "--" << "n" << p->right->key << ";" << endl;
            this->_graphWalk(p->right, stream);
        }
    }
}

QByteArray BST::_prepareGraph() {
    QByteArray arr = QByteArray();

    QTextStream stream(&arr, QIODevice::ReadWrite);
    stream << "graph ""{" << endl;
    stream << "\tnode[fontsize=10,margin=0,width=\".4\", height=\".3\"];" << endl;
    stream << "\tsubgraph cluster17{" << endl;

    this->_graphWalk(this->root, &stream);
    stream << "\t}\n" << "}" << endl;
    stream.flush();

    return arr;
}

void BST::show() {
    QProcess* p = new QProcess();
    QByteArray a = this->_prepareGraph();

    p->setProcessChannelMode(QProcess::MergedChannels);
    p->start("dot", QStringList() << "-Tpng");
    p->write(a);

    QByteArray data;
    QPixmap pixmap = QPixmap();

    while(p->waitForReadyRead(100)) {
        data.append(p->readAll());
    }

    pixmap.loadFromData(data);

    this->scene->addPixmap(pixmap);
    this->view->show();
}
