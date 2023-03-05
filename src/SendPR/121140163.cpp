//121140178_Muhammad Daffa Fahreza_RC
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct TNode *addressNode;
typedef addressNode BinTree;
typedef struct TNode
{
    infotype info;
    addressNode left;
    addressNode right;
    addressNode parent;
} Node;

addressNode root;


#define Root(T)     (T)->info 
#define Left(T)     (T)->left 
#define Right(T)    (T)->right 

#define Nil NULL

addressNode Allocation(infotype x)
{
    addressNode NewNode;

    NewNode = new Node;
    NewNode->info = x;
    NewNode->left = Nil;
    NewNode->right = Nil;
    NewNode->parent = Nil;

    return NewNode;
}

void CreateRoot(infotype x)
{
    if(root != Nil)
    {
        cout << "\nTree is already created!" << endl;
    }
    else
    {
        root = Allocation(x);
        cout << "\nData " << x << " successfully become root" << endl;
    }
}

addressNode InsertLeft(addressNode NodeParent, infotype x)
{
    if(NodeParent->left!=NULL)
    {
        cout << "\nParent Node with value " << NodeParent->info << " already has child" << endl;

        return Nil;
    }
    else
    {
        addressNode NewNode;

        NewNode = Allocation(x);
        NodeParent->left = NewNode;
        NewNode->parent = NodeParent;
        cout<<"InsertLeft " << x << " is succssesful on parent : " << NodeParent->info << endl;

        return NewNode;
    }
}

addressNode InsertRight(addressNode NodeParent, infotype x)
{
    if(NodeParent->right!=NULL)
    {
        cout << "\nParent Node with value " << NodeParent->info << " already has child" << endl;

        return Nil;
    }
    else
    {
        addressNode NewNode;

        NewNode = Allocation(x);
        NodeParent->right = NewNode;
        NewNode->parent = NodeParent;
        cout<<"InsertRight " << x << " is succssesful on parent : " << NodeParent->info << endl;

        return NewNode;
    }    
}

addressNode InsertElmt(addressNode NodeParent, infotype x)
{
    if(x >= NodeParent->info)
    {
        return InsertRight(NodeParent,x);
    }
    else
    {
        return InsertLeft(NodeParent, x);
    }
}

void preOrder(addressNode T)
{
    if (T == Nil){
        return;
    }
    else
    {
        cout << T->info <<" ";
        preOrder(Left(T));
        preOrder(Right(T));
    }
    
}

int main()
{
    BinTree node2,node3,node4,node5,node6;

    CreateRoot(8);
    node2 = InsertElmt(root,4);
    node3 = InsertElmt(root,0);
    node4 = InsertElmt(node2,1);
    node5 = InsertElmt(node2,7);
    node6 = InsertElmt(node3,8);
    cout << endl;
    cout << "Pre Order: " ; preOrder(root);
}