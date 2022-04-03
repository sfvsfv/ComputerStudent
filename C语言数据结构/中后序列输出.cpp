#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct BiTNode {//二叉树结点
    char data;                      //数据
    struct BiTNode* lchild, * rchild; //左右孩子指针
} BiTNode, * BiTree;
int nn = 0;
int CreateBiTree(BiTree* T) {//按先序序列创建二叉树
    char data;
    scanf_s("%c", &data);//按先序次序输入二叉树中结点的值（一个字符），‘#’表示空树
    if (data == '#') {
        *T = NULL;
    }
    else {
        *T = (BiTree)malloc(sizeof(BiTNode)); nn++;
        (*T)->data = data;         //生成根结点
        CreateBiTree(&(*T)->lchild);//构造左子树
        CreateBiTree(&(*T)->rchild);//构造右子树
    }
    return 0;
}
void Visit(BiTree T) {//输出
    if (T->data != '#') {
        printf("%c ", T->data);
    }
}
void PreOrder(BiTree T) {//先序遍历
    if (T != NULL) {
        Visit(T);               //访问根节点
        PreOrder(T->lchild);    //访问左子结点
        PreOrder(T->rchild);    //访问右子结点
    }
}
void InOrder(BiTree T) {//中序遍历
    if (T != NULL) {
        InOrder(T->lchild);     //访问左子结点
        Visit(T);               //访问根节点
        InOrder(T->rchild);     //访问右子结点
    }
}
void PostOrder(BiTree T) {//后序遍历
    if (T != NULL) {
        PostOrder(T->lchild);   //访问左子结点
        PostOrder(T->rchild);   //访问右子结点
        Visit(T);               //访问根节点
    }
}
void PreOrder2(BiTree T) {//先序遍历(非递归)
//访问T->data后，将T入栈，遍历左子树；遍历完左子树返回时，栈顶元素应为T，出栈，再先序遍历T的右子树。
    BiTree* stack = (BiTree*)malloc(nn * sizeof(BiTree));
    int sp = 0;
    BiTree p = T;//p是遍历指针
    while (p || sp) {   //栈不空或者p不空时循环
        if (p != NULL) {
            stack[sp] = p; sp++;       //存入栈中
            printf("%c ", p->data);  //访问根节点
            p = p->lchild;          //遍历左子树
        }
        else {
            sp--; p = stack[sp];       //退栈
            p = p->rchild;          //访问右子树
        }
    }
    free(stack);
}
void InOrder2(BiTree T) {//中序遍历(非递归)
//T是要遍历树的根指针，中序遍历要求在遍历完左子树后，访问根，再遍历右子树。
//先将T入栈，遍历左子树；遍历完左子树返回时，栈顶元素应为T，出栈，访问T->data，再中序遍历T的右子树。
    BiTree* stack = (BiTree*)malloc(nn * sizeof(BiTree));
    int sp = 0;
    BiTree p = T;//p是遍历指针
    while (p || sp) {   //栈不空或者p不空时循环
        if (p != NULL) {
            stack[sp] = p; sp++;       //存入栈中
            p = p->lchild;          //遍历左子树
        }
        else {
            sp--; p = stack[sp];       //退栈
            printf("%c ", p->data);
            p = p->rchild;          //访问右子树
        }
    }
    free(stack);
}

typedef struct BiTNodePost {
    BiTree biTree;
    char tag;
} BiTNodePost, * BiTreePost;
void PostOrder2(BiTree T) {//后序遍历(非递归)
    BiTreePost* stack = (BiTreePost*)malloc(nn * sizeof(BiTreePost));
    int sp = 0;
    BiTree p = T;//p是遍历指针
    BiTreePost BT;
    while (p != NULL || sp) {//栈不空或者p不空时循环
        while (p != NULL) {//遍历左子树
            BT = (BiTreePost)malloc(sizeof(BiTNodePost));
            BT->biTree = p;
            BT->tag = 'L';//访问过左子树
            stack[sp] = BT; sp++;       //存入栈中
            p = p->lchild;
        }
        while (sp && (stack[sp - 1])->tag == 'R') {//左右子树访问完毕访问根节点
            sp--; BT = stack[sp];        //退栈
            printf("%c ", BT->biTree->data);
            free(BT);
        }
        if (sp) {//遍历右子树
            BT = stack[sp - 1];
            BT->tag = 'R';//访问过右子树
            p = BT->biTree;
            p = p->rchild;
        }
    }
    free(stack);
}
void LevelOrder(BiTree T) {//层次遍历
    BiTree p;
    BiTree* queue;
    int h = 0, t = 0, n = 0;

    if (T == NULL) return;
    p = T;
    queue = (BiTree*)malloc(nn * sizeof(BiTree));
    queue[t] = p; t = (t + 1) % 10; n++;//根节点入队
    while (n) {    //队列不空循环
        p = queue[h];             //对头元素出队
        printf("%c ", p->data);  //访问p指向的结点
        h = (h + 1) % 10; n--;         //退出队列
        if (p->lchild != NULL) {//左子树不空，将左子树入队
            queue[t] = p->lchild; t = (t + 1) % 10; n++;
        }
        if (p->rchild != NULL) {//右子树不空，将右子树入队
            queue[t] = p->rchild; t = (t + 1) % 10; n++;
        }
    }
    free(queue);
}
int main() {
    BiTree T;
    printf("请输入字符串序列：\n");
    setlocale(LC_ALL, "chs");
    CreateBiTree(&T);

    printf("先序遍历        ："); PreOrder(T); printf("\n");
    printf("先序遍历(非递归)："); PreOrder2(T); printf("\n");
    printf("\n");
    printf("中序遍历        ："); InOrder(T); printf("\n");
    printf("中序遍历(非递归)："); InOrder2(T); printf("\n");
    printf("\n");
    printf("后序遍历        ："); PostOrder(T); printf("\n");
    printf("后序遍历(非递归)："); PostOrder2(T); printf("\n");
    printf("\n");
    printf("层次遍历        ："); LevelOrder(T); printf("\n");

    return 0;
}
//ABC##DE#G##F###
//先序遍历        ：A B C D E G F
//先序遍历(非递归)：A B C D E G F
//
//中序遍历        ：C B E G D F A
//中序遍历(非递归)：C B E G D F A
//
//后序遍历        ：C G E F D B A
//后序遍历(非递归)：C G E F D B A
//
//层次遍历        ：A B C D E F G
//

///       A
///      /
///     B
///    / \
///   C   D
///      / \
///     E   F
///      \
///       G
