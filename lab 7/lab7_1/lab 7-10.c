#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *nextptr;
};
bool fx = false;
typedef struct node node;
typedef struct node *nodeP;

int isEmpty(nodeP lst);
int create_node(nodeP *node, int value);
int deleteDuplicate(nodeP node);
int main(){
    nodeP dataNode = NULL;
    int i = 0, temp_d;
    while(true){
        scanf("%d", &temp_d);
        if(create_node(&dataNode, temp_d)) printf("%d saved\n", temp_d);
        else printf("ERROR!!\n");
        fflush(stdin);
        ///counter condition part
        i++;
        if(i==10) break;
    }
    printList(dataNode);
    printf("delete node duplicate : %d\n", deleteDuplicate(dataNode));
    printList(dataNode);
    return 0;
}

int create_node(nodeP *node, int value){
    nodeP newNode, tempNode;
    if(isEmpty(*node)){
        newNode = malloc(sizeof(node));
        if(newNode == NULL) return 0;
        newNode->data = value;
        newNode->nextptr = NULL;
        *node = newNode;
        return 1;
    }else{
        if(value % 2 == 0){
            tempNode = *node;
            newNode = malloc(sizeof(node));
            newNode->data = value;
            newNode->nextptr = *node;
            *node = newNode;
        }else{
            tempNode = *node;
            while(tempNode->nextptr != NULL){
                tempNode = tempNode->nextptr;
            }
            newNode = malloc(sizeof(node));
            newNode->data = value;
            newNode->nextptr = NULL;
            tempNode->nextptr = newNode;
        }

        return 1;
    }
}

int isEmpty(nodeP lst){
    return (lst == NULL);
}

void printList(nodeP lst){
    if(isEmpty(lst)) printf("EOL\n");

     ///END OF LIST
    else{
        printf("%d->", lst->data);
        printList(lst->nextptr);
    }
}

int deleteDuplicate(nodeP node){
    int num_t, count = 0; // ��˹��������Ѻ�Ѻ����纤��
    nodeP curNode, prevNode, delptr;// �ӹ˴�������Ѻ�纵�ǶѴ� ��ǻѨ�غѹ ��е�����ź
    if(node->nextptr == NULL) return 0;
    num_t = node->data; // �纤�ҵ���Ţ����ͧ���ź
    curNode = node->nextptr;
    prevNode = node;
    while(curNode != NULL){ // ǹ loop-while �����Ҩ��� node �ش����
        if(curNode->data == num_t){ // ��Ң����ŷ������ҡѺ num_t
            if (curNode->nextptr==NULL){ // �ó��� node �ش����
                printf("!");
                delptr = curNode; // ��� delptr �� node �Ѩ�غѹ
                prevNode->nextptr = NULL;
                free(delptr); // �׹��ҵ�� node ����ӡѹ
                count++; // �Ѻ��Ƿ��ⴹź�͡
                break;
            }else{
                delptr = curNode; // ��� delptr �� node �Ѩ�غѹ
                curNode = curNode->nextptr; // ����ǻѨ�غѹ���价�� ��ǶѴ�
                prevNode->nextptr = curNode;
                free(delptr); // �׹��ҵ�� node ����ӡѹ
                count++; // �Ѻ��Ƿ��ⴹź�͡
            }
        }else{
            prevNode = curNode;
            curNode = curNode->nextptr;
        }
    }

    return count +  deleteDuplicate(node->nextptr); // �ӡ�ä׹��Ҩӹǵ�Ƿ��ⴹź���Ը� recurse
}
