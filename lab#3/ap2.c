/*******************************
���α׷���: �迭�� ������ 2
�� �� ��: 2019038054 ����
�� �� ��: 2022 03 22
���α׷� ����: �迭�� �̸��� ���� Ư¡
********************************/ 
#include <stdio.h>

void main()
{
    int list[5];

    list[0] = 10;  

    printf("2019038054 \t\t  ����\n");

    printf("list[0] \t\t= %d\n", list[0]);          //list[0]�� ����� �� = 10
    printf("address of list \t= %p\n", list);       //list �ּ�
    printf("address of list[0] \t= %p\n", &list[0]);//list[0]�ּ�
    printf("address of list + 0 \t= %p\n", list+0); //list+0��° �ּ�
    printf("address of list + 1 \t= %p\n", list+1); //lsit+1��° �ּ�
    printf("address of list + 2 \t= %p\n", list+2); //list+2��° �ּ�
    printf("address of list + 3 \t= %p\n", list+3); //list+3��° �ּ�
    printf("address of list + 4 \t= %p\n", list+4); //list+4��° �ּ�
    printf("address of list[4] \t= %p\n", &list[4]);//list[4]�� �ּ�

}