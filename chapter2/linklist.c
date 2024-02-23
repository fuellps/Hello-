#include "../lib/lib.h"
// 定义LinkNode类
typedef struct LinkNode{
    int val;
    struct LinkNode *next;
}LinkNode;

// 构造函数
LinkNode* newLinkNode(int val){
    LinkNode * node = malloc(sizeof(LinkNode));
    if(node == NULL){
        printf("新节点分配失败\n");
        return NULL;
    }
    node ->val = val;
    node -> next = NULL;
    return node;
}

/*
双向链表
typedef struct LinkNode{
    int val;
    struct LinkNode *prev;
    struct LinkNode *next;
} LinkNode;
构造函数
LinkNode* newLinkNode(int val){
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    node->val = val;
    node->prev = NULL;
    node->next = NULL;
}
*/


// 链表常用基本操作
void insert(LinkNode * node, LinkNode * tag);
void erase(LinkNode * node);
void traverse(LinkNode *Head);
LinkNode* find(LinkNode *Head, int target);

int main(void)
{
    // 1.初始化节点
    LinkNode *n1 = newLinkNode(1);
    LinkNode *n2 = newLinkNode(2);
    LinkNode *n3 = newLinkNode(3);
    LinkNode *n4 = newLinkNode(4);
    LinkNode *n5 = newLinkNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    printf("当前链表的值为: ");
    traverse(n1);
    printf("\n");
    printf("插入值为666后的值为  :");
    LinkNode *n6 = newLinkNode(666);
    insert(n5,n6);
    traverse(n1);
    printf("\n");
    printf("删除值为666后的值为  :");
    erase(n5);
    traverse(n1);
    printf("\n");
    
}

// 2.插入操作: 在node后面插入一个节点
void insert(LinkNode * node, LinkNode * target){
    target->next = node->next;
    node->next = target;
}
// 3.删除操作: 删除node后面的节点
void erase(LinkNode * node){
    if(node -> next == NULL)
        return;
    LinkNode *tmp = node->next;
    node->next = tmp->next;
    free(tmp);
}
// 4.遍历操作
void traverse(LinkNode *Head){
    while(Head){
        printf("%d ", Head->val);
        Head = Head->next;
    }
}
// 5.查找操作 寻找值为target的节点
LinkNode* find(LinkNode *Head, int target){
    while(Head){
        if(Head -> next == NULL)
            return NULL;
        if(Head -> val == target)
            return Head;
    }
    return NULL;
}
