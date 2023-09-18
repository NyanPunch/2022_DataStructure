/* postfix.c
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */
/*******************************
���α׷���: ����ǥ���
�� �� ��: 2019038054 ����
�� �� ��: 2022 04 07 ~ 2022 04 09
���α׷� ����: ������ Ȱ���� ����ǥ��� �Լ�
********************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

/* stack ������ �켱����, lparen = 0 ���� ���� */
typedef enum{
	lparen = 0,  /* ( ���� ��ȣ */
	rparen = 9,  /* ) ������ ��ȣ*/
	times = 7,   /* * ���� */
	divide = 6,  /* / ������ */
	plus = 5,    /* + ���� */
	minus = 4,   /* - ���� */
	operand = 1 /* �ǿ����� */
} precedence;

char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression�� �����ϴ� �迭 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix�� ����� ���ڿ��� �����ϴ� �迭 */
char postfixStack[MAX_STACK_SIZE];	/* postfix�� ��ȯ�� ���� �ʿ��� ���� */
int evalStack[MAX_STACK_SIZE];		/* ����� ���� �ʿ��� ���� */

int postfixStackTop = -1;  /* postfixStack�� top */
int evalStackTop = -1;	   /* evalStack�� top */

int evalResult = 0;	   /* ��� ����� ���� */

void postfixpush(char x);
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();
precedence getToken(char symbol);
precedence getPriority(char x);
void charCat(char* c);
void toPostfix();
void debug();
void reset();
void evaluation();

int main()
{
	char command;
	printf("\n------------------[����]--------[2019038054]------------------\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			getInfix();
			break;
		case 'p': case 'P':
			toPostfix();
			break;
		case 'e': case 'E':
			evaluation();
			break;
		case 'd': case 'D':
			debug();
			break;
		case 'r': case 'R':
			reset();
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

/* postfix ���ÿ� x�� Ǫ�� */
void postfixPush(char x) {
	//postfix ž�� ������Ų �� x�� ����
    postfixStack[++postfixStackTop] = x;
}

/* postfix ���ÿ��� x�� �� */
char postfixPop() {
    char x;
	//������ ������ ��� NULL�� ����
    if(postfixStackTop == -1)
        return '\0';
	//postfix ž���� x�� �� �� ����
    else {
    	x = postfixStack[postfixStackTop--];
    }
    return x;
}

/* evalstack�� ž�� Ǫ�� */
void evalPush(int x) {
	//eval ������ ž�� ������Ų �� x�� ����
    evalStack[++evalStackTop] = x;
}

/* evalstack�� ž�� ��  */
int evalPop() {
    if(evalStackTop == -1)
        return -1;
    else
        return evalStack[evalStackTop--];
}

/*
 * infix expression�� �Է¹޴´�.
 * infixExp���� �Էµ� ���� �����Ѵ�.
 */
void getInfix() {
    printf("Type the expression >>> ");
    scanf("%s",infixExp);
}

/* symbol�� ���������� �ǿ��������� ����*/
precedence getToken(char symbol) {
	switch(symbol) {
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand;
	}
}

precedence getPriority(char x) {
	return getToken(x);
}

/* �����ϳ��� ���޹޾�, postfixExp�� �߰� */
void charCat(char* c) {
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/*
 * infixExp�� ���ڸ� �ϳ��� �о�鼭 stack�� �̿��Ͽ� postfix�� �����Ѵ�.
 * ����� postfix�� postFixExp�� ����ȴ�.
 */
void toPostfix() {
	/* infixExp�� ���� �ϳ����� �б����� ������ */
	char *exp = infixExp;
	char x; /* �����ϳ��� �ӽ÷� �����ϱ� ���� ���� */

	/* exp�� �������Ѱ��鼭, ���ڸ� �а� postfix�� ���� */
	while(*exp != '\0')
	{
		//�ǿ������Ͻ� postfix
		if(getPriority(*exp)==operand){
			x = *exp;
			charCat(&x);
		}
		// *exp == '(' ���ÿ� Ǫ��
		else if(getPriority(*exp)==lparen){
			postfixPush(*exp);
		}
		// *exp == ')' ���ÿ� Ǫ���� �����ڵ��� �� '('�� ����������
		else if(getPriority(*exp)==rparen){
			while((x = postfixPop()) != '('){
				charCat(&x);
			}
		}
		else {	//������ ž�� �ִ� �����ڰ� *exp ���ڿ� ���ų� Ŭ������ ������ ��
			while(getPriority(postfixStack[postfixStackTop]) >= getPriority(*exp)){
				x = postfixPop(); 
				charCat(&x);
			}
			//������ ž�� �����ں��� ���� �� �Է¹��� ���� Ǫ��
			postfixPush(*exp);
		}
		exp++;
	}
	//������ ������ �ɶ����� ��
	while(postfixStackTop != -1){
		x = postfixPop();
		charCat(&x);
	}
}

void debug() {
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}
/* ��� �������� �ʱ�ȭ */
void reset() {
	infixExp[0] = '\0';	
	postfixExp[0] = '\0';

	for(int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';
         
	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation() {
	//�ǿ�����1, �ǿ�����2
	int opr1, opr2;
	
	int length = strlen(postfixExp); //postfixExp�� ����� ���ڿ� ��ŭ ���� �Ҵ�
	char symbol;	//������ �ǿ����� ���� ����
	evalStackTop = -1;

	for(int i = 0; i < length; i++)
	{
		symbol = postfixExp[i];
		if(getToken(symbol) == operand) { //symbol�� operand ���
			evalPush(symbol - '0');	//�Է¹��� ���� '1'~'9'�� '0'���� ���� 1~9�� �ȴ�.
		}
		else {	//symbol�� '+', '-', '*', '/' ���
			opr2 = evalPop(); //evalstack ž�� ��ġ�� ���߿� push�� �ǿ�����2 push
			opr1 = evalPop(); //evalstack ���� ���� pop�� �ǿ�����1 push

			switch(getToken(symbol)) { /* symbol���� ���� ���� ���� */
			case plus: evalPush(opr1 + opr2); break;
			case minus: evalPush(opr1 - opr2); break;
			case times: evalPush(opr1 * opr2); break;
			case divide: evalPush(opr1 / opr2); break;
			default: break;
			}
		}
	}
	evalResult = evalPop(); //����� ����
}

