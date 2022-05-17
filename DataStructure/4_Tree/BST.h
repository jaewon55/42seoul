#ifndef BST_H
# define BST_H

typedef struct  s_BSTNode
{
    char        data;
    t_BSTNode   *pLChild;
    t_BSTNode   *pRChild;
}               t_BSTNode;

typedef struct  s_BST
{
    t_BSTNode   *root;
    int         currenteElementCount;
}               t_BST;

t_BST       *createBST();
void        deleteBST(t_BST *BST);
int         insertNodeBST(t_BST *BST, t_BSTNode node);
t_BSTNode   *deleteNodeBST(t_BST *BST, char key);
t_BSTNode   *searchNodeBST(t_BST *BST, char key);
int         isBSTEmpty(t_BST *BST);

#endif