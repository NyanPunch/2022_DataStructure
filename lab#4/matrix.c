/*******************************
���α׷���: ��� ���� ���α׷�
�� �� ��: 2019038054 ����
�� �� ��: 2022 03 30 ~ 2022 04 02
���α׷� ����: �����޸��Ҵ��� �̿��� ����� ����� �䱸������ �����Ѵ�
********************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);  //�������� ��� ���� �Լ�
void print_matrix(int** matrix, int row, int col);  //��� ��� �Լ�
int free_matrix(int** matrix, int row, int col);    //���� ��� ���� �Լ�
int fill_data(int** matrix, int row, int col);  //��� ������ ������ �Է�
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);  //��� ���� �Լ�
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);   //��� ���� �Լ�
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);   //��ġ��� ���� �Լ�
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);  //��� ���� �Լ�

int main()
{

    char command;   //�޴� �̿�� ��ɾ �Է¹��� ����
    printf("[----- [����]  [2019038054] -----]\n");

    int row, col;
    srand(time(NULL));

    printf("Input row and col : ");
    scanf("%d %d", &row, &col); 
    int** matrix_a = create_matrix(row, col);   //��� a ����
    int** matrix_b = create_matrix(row, col);   //��� b ����
    int** matrix_a_t = create_matrix(col, row); //��ġ��� ��� t ���� ##�Է¹��� ��� ���� �ݴ�

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) {return -1;}

    do{
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch(command) {
        case 'z': case 'Z': //��� ����
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);
            fill_data(matrix_b, row, col);
            break;
        case 'p': case 'P': //��� ���
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A': //��� ����
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S': //��� ����
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T': //matrix_a�� ��ġ��� matrix_a_t ����
            printf("Transpose matrix_a \n");
            printf("matrix_a_t\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row);
            break;
        case 'm': case 'M': //matrix_a �� matrix_a_t ����
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q': //���� �޸� ������ ���α׷� ����
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            break;
        default:    //�־��� ��ɾ� �̿� �Է½� 
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    }while(command != 'q' && command != 'Q');   //'q' �Ǵ� 'Q'�� �ƴ� �� ���� �ݺ�

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{
    if (row <= 0 || col <= 0){                          //��ó���˻� ������ �Ϻ��� �Դ��� Ȯ��
        printf("Check the sizes of row and col!\n");
        return NULL;
    }
       
    int **matrix = (int**)malloc(sizeof(int *)*row);    //�����޸� �Ҵ� row����
    for(int i=0;i<row;i++)
        matrix[i] = (int*)malloc(sizeof(int)*col);      //�����޸� �Ҵ� col����
    
    /* check post conditions */
    if(matrix == NULL) {    //��ó���˻� �޸��Ҵ��� ����� �Ǿ����� Ȯ��
        printf("Memory Allocation Failed.\n");
        return NULL;
    }
    return matrix;
}
/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
	if (row <= 0 || col <= 0) { //��ó�� �˻�
		printf("Check the size of row and col!\n");
		return;
	}
    for(int i=0; i<row; i++){   //row x col ��� ���
        for(int j=0; j<col; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");   //�� �ٲ�
    }
    if (matrix == NULL) {   //��ó�� �˻�
		printf("Memory Allocation Failed.\n");
		return;
	}
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col) //�����޸� ���� ���� �Լ�
{
    if (row <= 0 || col <= 0){  //��ó���˻� ������ �Ϻ��� �Դ��� Ȯ��
        printf("Check the sizes of row and col!\n");
        return -1;
    }
    for(int i=0;i<row;i++)
        free(matrix[i]);    //�����޸� ���� row����
    free(matrix);          //�����޸� ���� col����   

    return 1;
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)   
{   
    if (row <= 0 || col <= 0) { //��ó���˻�
		printf("Check the size of row and col!\n");
		return -1;
	}
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            matrix[i][j]=( rand() % 20 );   //0~19���� ���� ��
    }
    if (matrix == NULL) {   //��ó���˻�
		printf("Memory Allocation Failed.\n");
		return -1;
	}
	return 1;
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{   
    int** matrix_sum = create_matrix(row, col); //���������� �����ϰ� ����� �Լ�
    if (row <= 0 || col <= 0) { //��ó���˻�
		printf("Check the size of row and col!\n");
		return -1;
	}

    for(int i=0; i<row ; i++){
        for(int j=0; j<col ; j++)  //a[] + b[]
            matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];
    }       //����� ������ ��� ���� ��ġ�� ����� ���� ���Ѵ�.

    if (matrix_a == NULL || matrix_b == NULL || matrix_sum == NULL) { //��ó���˻�
		printf("Memory Allocation Failed.\n");
		return -1;
	}
    print_matrix(matrix_sum,row,col); //���� ����Լ�
    free_matrix(matrix_sum,row,col);  //�Ҵ� ����
    return 1;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int** matrix_sub = create_matrix(row,col); //�������� ���� �޸� ����
    if (row <= 0 || col <= 0) { //��ó���˻�
		printf("Check the size of row and col!\n");
		return -1;
	}

    for(int i=0; i<row ; i++){
        for(int j=0; j<col ; j++)  //a[] - b[] �Լ�
            matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j];
    }          //����� ������ ��� ���� ��ġ�� ����� ���� ����.

    if (matrix_a == NULL || matrix_b == NULL || matrix_sub == NULL) { //��ó���˻�
		printf("Memory Allocation Failed.\n");
		return -1;
	}
    print_matrix(matrix_sub,row,col);
    free_matrix(matrix_sub,row,col);
    return 1;
}

/* transpose the matrix to matrix_t */                                  //int** matrix_a_t = create_matrix(col, row);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)    //if 3x2 matrix, t => 2x3 matrix   row, col
{
    if (row <= 0 || col <= 0) { //��ó���˻�
		printf("Check the size of row and col!\n");
		return -1;
	}
    
    for(int i=0; i<row ; i++){
        for(int j=0; j<col ; j++)           //��ġ��� ���� �� ��� ���� �ݴ�� ���� �ص�
            matrix_t[i][j] = matrix[j][i];  //��� ���� �� �ݴ��̹Ƿ� matrix[j][i]�� ����
    }

    if (matrix == NULL || matrix_t ==NULL) {    //��ó���˻�
		printf("Memory Allocation Failed.\n");
		return -1;
	}

    return 1;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)   
{   
    int** matrix_mul = create_matrix(row,col);  //��İ��� �޸� �Ҵ�
	if (row <= 0 || col <= 0) { //��ó���˻�
		printf("Check the size of row and col!\n");
		return -1;
	}

    int sum;
    for(int i=0; i<row ; i++){    //a�� ��
        for(int j=0; j<row; j++) {//t�� ��
            sum = 0;
            for(int k=0; k<col; k++)    //a�� �� t�� ��
                sum += matrix_a[i][k] * matrix_t[k][j];
            matrix_mul[i][j] = sum;
        }
    }

    if (matrix_t == NULL || matrix_mul == NULL) { //��ó���˻�
		printf("Memory Allocation Failed.\n");
		return -1;
	}
    print_matrix(matrix_mul,row,row);   //ù ��° row = matrix_a�� row �� ��° row = matrix_t�� col�� row
    free_matrix(matrix_mul,row,row);
    return 1;
}