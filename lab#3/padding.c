/*******************************
���α׷���: ����ü�� ����Ȱ��(�е�)
�� �� ��: 2019038054 ����
�� �� ��: 2022 03 23
���α׷� ����: �� ������ ���� �� ��ǻ�Ϳ��� ��� �����ϴ��� Ȯ���Ѵ�
********************************/ 
#include <stdio.h>

struct student {
    char lastName[13];  //13bytes
    int studentId;      //4bytes
    short grade;        //2bytes
};
int main()
{
    struct student pst;
    
    printf("size of student = %ld\n", sizeof(struct student));  //���� student struct�� ���� �޸� ũ��
    printf("size of int = %ld\n", sizeof(int));                 //integer �޸� ũ��
    printf("size of short = %ld\n", sizeof(short));             //short �޸� ũ��

    printf("\n2019038054 ����\n");
    return 0;
}
