#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
#include "stdio.h"
/**
 * 顺序表的实现以及操作
 */
#define InitSize 10 // 默认的最大长度
// 定义一个结构体，表述数据部分
typedef struct {
    char name[10];
    int sex;
} Student;
typedef struct {
    Student *data; // 指示动态分配的指针
    int MaxSize; // 顺序表打最大容量
    int length; // 顺序表打当前长度
}SeqList;
// 初始化顺序表（动态） malloc函数
void InitList(SeqList &list){
    // 使用malloc函数申请连续的存储空间
    list.data = (Student *)malloc(InitSize * sizeof(Student));
    // 长度值为0
    list.length = 0;
    // 初始化顺序表的最大容量
    list.MaxSize = InitSize;
}
/**
 * 动态增加数组的长度
 * @param list
 * @param length
 */
void IncreaseSize(SeqList &list,int length){
    Student *p = list.data;
    // 新加部分的长度加上原来的长度 ——————> 变成新区域
    list.data = (Student *) malloc((list.MaxSize + length) * sizeof(Student));
    // 将原来的数据复制到新的区域
    for (int i = 0;i < list.length;i++){
        list.data[i] = p[i];
    }
    list.MaxSize = list.MaxSize + length;
    // 释放指针
    free(p);
}
/**
 * 顺序表的插入操作，按位置插入
 * @param list 进行操作的顺序表
 * @param index 插入位置
 * @param student 插入的数据
 * @return
 */
bool ListInsert(SeqList &list,int index,Student student){
    // 判断插入的位置是否合法
    if (index < 1 || index > list.length + 1){
        return false;
    }
    // 当前长度大于最大长度，存储空间已满，无法出入
    if (list.length >= list.MaxSize){
        return false;
    }
    for (int i = list.length; i >= index ; i--) {
        list.data[i] = list.data[i - 1];
    }
    list.data[index - 1] = student;
    list.length++;
    return true;
}
int main(){
    // 创建一个顺序表，并且初始化
    SeqList list;
    InitList(list);
    // 打印最大容量和长度
    printf("最大容量为%d,当前长度为：%d\n",list.MaxSize,list.length);
    // 添加容量
    IncreaseSize(list,2);
    printf("添加之后最大容量为%d,当前长度为：%d\n",list.MaxSize,list.length);
    // 添加一个数据进去
    Student student;
    strcpy(student.name, "罗川");
    student.sex = 18;
    bool b = ListInsert(list,1,student);
    if (b) printf("添加成功");
    printf("添加之后最大容量为%d,当前长度为：%d\n",list.MaxSize,list.length);
    return 0;
}


