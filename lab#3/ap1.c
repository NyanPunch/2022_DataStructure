/*******************************
���α׷���: �迭�� ������ 1
�� �� ��: 2019038054 ����
�� �� ��: 2022 03 22
���α׷� ����: �迭�� �����͹迭�� Ư¡
********************************/ 
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5];
    int *plist[5] = {NULL,};

    plist[0]=(int*)malloc(sizeof(int));

    list[0]= 1;
    list[1]= 100;
    *plist[0]=200;

    printf("value of list[0] = %d\n", list[0]);     //list[0]�� �� = 1 ���
    printf("address of list[0] = %p\n", &list[0]);  //list[0]�� �ּ�
    printf("value of list = %p\n", list);           //list�� �ּ�
    printf("address of list (&list) = %p\n", &list);//list�� �ּ�

    printf("\n----------------------------------------\n");
    printf("\t2019038054 ����"); 
    printf("\n----------------------------------------\n\n");

    printf("value of list[1] = %d\n", list[1]);     //list[1]�� �� = 100
    printf("address of list[1] = %p\n", &list[1]);  //list[1]�� �ּ� = list[0] + 4byte(int)
    printf("value of *(list+1) = %d\n", *(list + 1));//*(list+1) = list[1] = 100
    printf("address of list+1 = %p\n", list+1);     //list+1 = &list[1] = list[1]�ּ�

    printf("\n----------------------------------------\n\n");
    printf("value of *plist[0] = %d\n", *plist[0]); //plist[0]�� �� = 200
    printf("&plist[0] = %p\n", &plist[0]);          //plist[0]�ּ�
    printf("&plist = %p\n", &plist);                //plist���ּ�
    printf("plist = %p\n", plist);                  //plist
    printf("plist[0] = %p\n", plist[0]);            //plist[0]�� ����Ű�� �ּ� = 200�� ����� ��
    printf("plist[1] = %p\n", plist[1]);            //plist[1]�� ����Ű�� �ּ� = NULL
    printf("plist[2] = %p\n", plist[2]);            //plist[2]�� ����Ű�� �ּ� = NULL
    printf("plist[3] = %p\n", plist[3]);            //plist[3]�� ����Ű�� �ּ� = NULL
    printf("plist[4] = %p\n", plist[4]);            //plist[4]�� ����Ű�� �ּ� = NULL

    free(plist[0]);
}     