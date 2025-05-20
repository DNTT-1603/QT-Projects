#include <iostream>
#include <typeinfo>
#include <QString>
#include <QDebug>
#include <QObject>


#include "test.h"


using namespace std;

Test * makeTree() {
    Test *root = new Test(nullptr,"Root");
    Test *Parent = new Test(root,"Parent");
    Test *child1 = new Test(Parent,"Child1");
    Test *child2 = new Test(child1,"Child2");

    return root;
}
void printTree(Test *root, int level = 0 ) {
    if (root == nullptr) return;
    QString aaa;
    qInfo() << "|_" + aaa.fill('_',level*2) + root->objectName();

    for (QObject *child : root->children()) {
        level++;
        printTree(static_cast<Test*>(child),level);
    }
}


int main(int argc, char *argv[])
{
    unique_ptr<Test>  uni_root(makeTree());
    Test parent;
    parent.setObjectName("Parentxxxx");
    Test child;

    child.setObjectName("Childxxxx");
    child.setParent(&parent);

    Test* t = (Test*) parent.children().at(0);

    qInfo() << "Parent: " << parent.objectName() << "Child: " << parent.children();
    qInfo() << "Parent: " << parent.objectName() << "Child: " << t->objectName();

}
