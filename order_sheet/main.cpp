#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
#include "stdio.h"
/**
 * ˳����ʵ���Լ�����
 */
#define InitSize 10 // Ĭ�ϵ���󳤶�
// ����һ���ṹ�壬�������ݲ���
typedef struct {
    char name[10];
    int sex;
} Student;
typedef struct {
    Student *data; // ָʾ��̬�����ָ��
    int MaxSize; // ˳�����������
    int length; // ˳����ǰ����
}SeqList;
// ��ʼ��˳�����̬�� malloc����
void InitList(SeqList &list){
    // ʹ��malloc�������������Ĵ洢�ռ�
    list.data = (Student *)malloc(InitSize * sizeof(Student));
    // ����ֵΪ0
    list.length = 0;
    // ��ʼ��˳�����������
    list.MaxSize = InitSize;
}
/**
 * ��̬��������ĳ���
 * @param list
 * @param length
 */
void IncreaseSize(SeqList &list,int length){
    Student *p = list.data;
    // �¼Ӳ��ֵĳ��ȼ���ԭ���ĳ��� ������������> ���������
    list.data = (Student *) malloc((list.MaxSize + length) * sizeof(Student));
    // ��ԭ�������ݸ��Ƶ��µ�����
    for (int i = 0;i < list.length;i++){
        list.data[i] = p[i];
    }
    list.MaxSize = list.MaxSize + length;
    // �ͷ�ָ��
    free(p);
}
/**
 * ˳���Ĳ����������λ�ò���
 * @param list ���в�����˳���
 * @param index ����λ��
 * @param student ���������
 * @return
 */
bool ListInsert(SeqList &list,int index,Student student){
    // �жϲ����λ���Ƿ�Ϸ�
    if (index < 1 || index > list.length + 1){
        return false;
    }
    // ��ǰ���ȴ�����󳤶ȣ��洢�ռ��������޷�����
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
    // ����һ��˳������ҳ�ʼ��
    SeqList list;
    InitList(list);
    // ��ӡ��������ͳ���
    printf("�������Ϊ%d,��ǰ����Ϊ��%d\n",list.MaxSize,list.length);
    // �������
    IncreaseSize(list,2);
    printf("���֮���������Ϊ%d,��ǰ����Ϊ��%d\n",list.MaxSize,list.length);
    // ���һ�����ݽ�ȥ
    Student student;
    strcpy(student.name, "�޴�");
    student.sex = 18;
    bool b = ListInsert(list,1,student);
    if (b) printf("��ӳɹ�");
    printf("���֮���������Ϊ%d,��ǰ����Ϊ��%d\n",list.MaxSize,list.length);
    return 0;
}


