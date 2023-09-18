/*******************************
���α׷���: ����ü
�� �� ��: 2019038054 ����
�� �� ��: 2022 03 23
���α׷� ����: struct�� typedef�� �̿��� ����ü Ư�� �ľ�
********************************/ 
#include <stdio.h>

struct student1 {
    char lastName;
    int studentId;
    char grade;
};

typedef struct {
    char lastName;
    int studentId;
    char grade;
} student2;

int main() {
    //struct�� ���� ���� �� struct�� �� �Բ� ���
    struct student1 st1 = {'A', 100, 'A'};      //������ struct���� ������ ������� {lastname, studentId, grade}�̴�.

    printf("st1.lastName = %c\n", st1.lastName);        
    printf("st1.studentId = %d\n", st1.studentId);
    printf("st1.grade = %c\n", st1.grade);

    student2 st2 = {'B', 200, 'B'};             //typedef struct�� struct�� �� �ٿ��� ����

    printf("\nst2.lastName = %c\n", st2.lastName);
    printf("st2.studentId = %d\n", st2.studentId);
    printf("st2.grade = %c\n", st2.grade);

    printf("\n2019038054 ����\n");

    student2 st3;   //typedef
    st3 = st2;      //st2�� ������ st3�� ���� {'B', 200, 'B'}
                    //���簡 �Ǵ��� Ȯ��
    printf("\nst3.lastName = %c\n", st3.lastName);
    printf("st3.studentId = %d\n", st3.studentId);
    printf("st3.grade = %c\n", st3.grade);

    
       /* equality test */
    //if(st3 == st2) /* not working */
    //    printf("equal\n");
    //else
    //    printf("not equal\n");
        
    return 0;
}