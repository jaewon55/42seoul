#ifndef BST_H
# define BST_H

typedef struct  s_BSTNode
{
    char               data;
    struct s_BSTNode   *pLChild;
    struct s_BSTNode   *pRChild;
}               t_BSTNode;

typedef struct  s_BST
{
    t_BSTNode   *root;
    int         currenteElementCount;
}               t_BST;

t_BST       *createBST();
void        deleteBST(t_BST **BST);
int         insertNodeBST(t_BST *BST, t_BSTNode node);
t_BSTNode   *deleteNodeBST(t_BST *BST, char key);
t_BSTNode   *searchNodeBST(t_BST *BST, char key);
int         isBSTEmpty(t_BST *BST);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif
