/*******************************
���α׷���: �迭 ���α׷� 2
�� �� ��: 2019038054 ����
�� �� ��: 2022 03 22
���α׷� ����: �����͸� �̿��� �迭 ȣ��
********************************/ 
#include <stdio.h>

void print1 (int *ptr, int rows);       

int main()
{
    int one[] = {0,1,2,3,4};

    printf("one     = %p\n", one);      //one �迭�� �ּ�
    printf("&one    = %p\n", &one);     //one �迭�� �ּ�
    printf("&one[0] = %p\n", &one[0]);  //one[0]�� �ּ�
    printf("\n");

    print1(&one[0], 5);                 
    
    printf("2019038054 ����\n");
    return 0;
}

void print1(int *ptr, int rows)         //one[]�� *ptr�� ȣ��
{
    int i;
    printf("Address \t Content\n");
    for(i=0;i<rows;i++)                 //ptr + i == one + i
        printf("%p \t %5d\n", ptr + i, *(ptr + i));
    printf("\n");
}