//
// Created by 李金豪 on 2020/7/25.
//
#include <iostream>

#define InitSize 10

//查找表的数据结构
typedef struct {
    int * elem;
    int TableLen;
}SSTable;

//定义顺序表结构体类型（动态）
typedef  struct {
    int * elem;
    int maxSize, TableLen;
}SeqList;

//动态分配创建顺序表
void InitList(SeqList & L) {
    L.elem = (int *) malloc (sizeof(int) * InitSize);
    L.TableLen = 0;
    L.maxSize = InitSize;
}

//创建一个有序的线性表
void CreatSeqList(SeqList & L) {
    for (int i = 0; i < InitSize; ++i) {
        L.elem[i] = i + 1;
        L.TableLen++;
    }
}

//一般线性表的顺序查找
int Search_Seq(SSTable T, int key) {
    T.elem[0] = key; //引入“哨兵”

    int i;
    for (i = T.TableLen; T.elem[i] != key ; --i); //从后往前找
    return i;
}

//折半查找（有序存储的线性表）
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
