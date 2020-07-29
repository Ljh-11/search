//
// Created by ���� on 2020/7/25.
//
#include <iostream>

#define InitSize 10

//���ұ�����ݽṹ
typedef struct {
    int * elem;
    int TableLen;
}SSTable;

//����˳���ṹ�����ͣ���̬��
typedef  struct {
    int * elem;
    int maxSize, TableLen;
}SeqList;

//��̬���䴴��˳���
void InitList(SeqList & L) {
    L.elem = (int *) malloc (sizeof(int) * InitSize);
    L.TableLen = 0;
    L.maxSize = InitSize;
}

//����һ����������Ա�
void CreatSeqList(SeqList & L) {
    for (int i = 0; i < InitSize; ++i) {
        L.elem[i] = i + 1;
        L.TableLen++;
    }
}

//һ�����Ա��˳�����
int Search_Seq(SSTable T, int key) {
    T.elem[0] = key; //���롰�ڱ���

    int i;
    for (i = T.TableLen; T.elem[i] != key ; --i); //�Ӻ���ǰ��
    return i;
}

//�۰���ң�����洢�����Ա�
int Binary_Search(SeqList L, int key) {
    int low = 0, high = L.TableLen - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (L.elem[mid] == key) {
            return mid;
        } else if (L.elem[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    SSTable T;
    SeqList L;
    InitList(L);
    CreatSeqList(L);

    return 0;
}
