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
    int age;
} Student;
typedef struct {
    Student *data; // ָʾ��̬�����ָ��
    int MaxSize; // ˳�����������
    int length; // ˳����ǰ����
} SeqList;

// ��ʼ��˳�����̬�� malloc����
void InitList(SeqList &list) {
    // ʹ��malloc�������������Ĵ洢�ռ�
    list.data = (Student *) malloc(InitSize * sizeof(Student));
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
void IncreaseSize(SeqList &list, int length) {
    Student *p = list.data;
    // �¼Ӳ��ֵĳ��ȼ���ԭ���ĳ��� ������������> ���������
    list.data = (Student *) malloc((list.MaxSize + length) * sizeof(Student));
    // ��ԭ�������ݸ��Ƶ��µ�����
    for (int i = 0; i < list.length; i++) {
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
bool ListInsert(SeqList &list, int index, Student student) {
    // �жϲ����λ���Ƿ�Ϸ�
    if (index < 1 || index > list.length + 1) {
        return false;
    }
    // ��ǰ���ȴ�����󳤶ȣ��洢�ռ��������޷�����
    if (list.length >= list.MaxSize) {
        return false;
    }
    for (int i = list.length; i >= index; i--) {
        list.data[i] = list.data[i - 1];
    }
    list.data[index - 1] = student;
    list.length++;
    return true;
}

/**
 * ��ʾ˳����е���������
 * @param list �����˳���
 */
void ListShow(SeqList list) {
    // ��ȡlist��ĳ���
    int length = list.length;
    for (int i = 0; i < length; i++) {
        Student student = list.data[i];
        printf("ѧ��������Ϊ��%s,����Ϊ��%d\n", student.name, student.age);
    }
}

/**
 * ͨ��λ�ò���
 * @param list �����˳���
 * @param index λ��
 * @return
 */
Student ListByIndex(SeqList list, int index) {
    return list.data[index];
}

/**
 * ָ��λ��ɾ��
 * @param list
 * @param index
 */
bool ListDeleteByIndex(SeqList &list, int index) {
    if (index < 1 || index > list.length) {
        return false;
    }
    printf("��ɾ��������Ϊ������%s,���䣺%d", list.data[index - 1].name, list.data[index - 1].age);
    for (int i = index; i < list.length; i++) {
        list.data[i - 1] = list.data[i];
    }
    list.length--;
    return true;
}
/**
 * ɾ����С��Ԫ�ز��Һ����һ��Ԫ������λ
 * @param list ����˳���
 * @param s // ����ɾ������Сֵ
 * @return
 */
bool DeleMinValue(SeqList &list,Student &s){
    int temp = 100;
    int index = 0;// ��¼��Сλ�õ�����
    if (list.length <=0 ) return false;
    for (int i = 0; i < list.length; i++) {
        if (list.data[i].age < temp){
            temp = list.data[i].age;
            index = i;
        }
    }
    s = list.data[index];
    list.data[index] = list.data[list.length - 1];
    return true;
}
int main() {
    // ����һ��˳������ҳ�ʼ��
    SeqList list;
    InitList(list);
    // ��ӡ��������ͳ���
    printf("�������Ϊ%d,��ǰ����Ϊ��%d\n", list.MaxSize, list.length);
    // �������
    IncreaseSize(list, 2);
    printf("���֮���������Ϊ%d,��ǰ����Ϊ��%d\n", list.MaxSize, list.length);
    // ���һ�����ݽ�ȥ
    Student student1, student2;
    strcpy(student1.name, "�޴�");
    student1.age = 18;
    bool b1 = ListInsert(list, 1, student1);
    if (b1) printf("��ӳɹ�\n");
    strcpy(student2.name, "�ﲨ");
    student2.age = 17;
    bool b2 = ListInsert(list, 2, student2);
    if (b2) printf("��ӳɹ�\n");
    printf("���֮���������Ϊ%d,��ǰ����Ϊ��%d\n", list.MaxSize, list.length);
    // ��ʾ����
    ListShow(list);
    Student student = ListByIndex(list, 1);
    printf("ѧ��Ϊ%s,����%d", student.name, student.age);
    ListDeleteByIndex(list, 1);
    // ��ʾ����
    ListShow(list);
    return 0;
}


