/*******************************
���α׷���: �迭 ���α׷� 1
�� �� ��: 2019038054 ����
�� �� ��: 2022 03 22
���α׷� ����: �迭�� ȣ������ �� ���� ����
********************************/ 
#include <stdio.h>
#define MAX_SIZE 100

float sum(float [], int);
float input[MAX_SIZE], answer;
int i;

void main(void)
{
    for(i=0; i < MAX_SIZE; i++)
        input[i] = i;                               //�� n��° �迭�� n�� ����

    /* for checking call by reference */
    printf("address of input = %p\n", input);       //input�� �ּ� ���

    answer = sum(input, MAX_SIZE);                  //input[] �迭���� �� �� �Լ�
    printf("The sum is: %f\n", answer);             //return ���� tempsum�� �� ���
    printf("2019038054 ����\n");
}

float sum(float list[], int n)                      //input�迭�� list�� �ּҸ� �ѱ�
{
    printf("value of list = %p\n", list);           //list�� �� = input�� �ּ�
    printf("address of list = %p\n\n", &list);      //list�� �ּ�

    int i;
    float tempsum = 0;
    for(i = 0; i < n; i++)
        tempsum += list[i];                         //tempsum = tempsum + list[i]
    return tempsum;
}