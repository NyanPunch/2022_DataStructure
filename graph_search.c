/* 11주차 과제
*  2019038054 김경민
*  2022 05 23 ~
*  Graph Search
*/

#include <stdio.h>
#include <stdlib.h>


/* 그래프 노드 */
typedef struct node{
	int vertex;			//정점을 나타냄
	struct node* link; 	//다음 인접 정점과 연결
}GraphNode;
#define MAX_VERTEX 10

/* for stack */
#define MAX_STACK_SIZE 10	
GraphNode* stack[MAX_STACK_SIZE];
int top = -1;

GraphNode* pop();
void push(GraphNode* aNode);

/* for queue */
#define MAX_QUEUE_SIZE 10 
GraphNode* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

GraphNode* deQueue();
void enQueue(GraphNode* aNode);

/* 함수 선언 */
int initializeGraph(GraphNode** h); /* 그래프 생성 */
int insertVertex(GraphNode* h, int vertex);	/* vertex 삽입 */
int insertEdge(GraphNode*h, int ,int );	/* edge 삽입 */
void DFS();	/* 깊이 우선 탐색 */
void BFS();	/* 너비 우선 탐색 */
void printGraph();
int freeGraph(GraphNode* h);
int freeVertex(GraphNode* ptr);

int main()
{
	char command;
	int u, v;
	GraphNode* head = NULL;

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                          Graph Search                          \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph     = z                                       \n");
		printf(" Insert Vertex        = v      Insert Edge                  = e \n");
		printf(" Depth First Search   = d      Breath First Search          = b \n");
		printf(" Print Graph          = p      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeGraph(head);
			break;
		case 'q': case 'Q':
			freeGraph(head);
			printf("----------------------------------------------------------------\n");
			printf("                    2019038054       김경민                     \n");
			printf("----------------------------------------------------------------\n");
			break;
        case 'v': case 'V':
            printf("Your Key = ");
            scanf("%d", &u);
			InsertVertex(head, u);
			break;
        case 'e': case 'E':
            printf("Your Key(u) = ");
            scanf("%d", &u);
            printf("Your Key(v) = ");
            scanf("%d", &v);
			InsertEdge(head, u, v);
			break;
        case 'd': case 'D':
			printf("Your Key = ");
            scanf("%d", &u);
			DFS(head, u);
			break;
			break;
        case 'b': case 'B':
			printf("Your Key = ");
            scanf("%d", &u);
			BFS(head, u);
			break;
        case 'p': case 'P':
			PrintGraph(head);
			break;			
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeGraph(GraphNode **h){
	if(*h != NULL ) freeGraph(*h);
	/* MAX VERTEX SIZE = 10 */
	*h = (GraphNode*)malloc(sizeof(GraphNode)*MAX_VERTEX);
	for(int i=0;i<MAX_VERTEX;i++){
		(*h+i)->link = NULL;		/* 초기화 */ 
		(*h+i)->vertex = -9999;		
	}
	top = -1;
	front = rear = -1;
	return 0;
}

int freeGraph(GraphNode* h){
	/* 포인터 배열 내부 할당 해제 */
	for(int i=0; i<MAX_VERTEX; i++){
		if((h+i)->link) freeVertex((h+i)->link);
	}
	/* 헤드 해제 */
	free(h);
	return 0;
}
/* recursive */
int freeVertex(GraphNode* ptr){
	if(ptr){
		freeVertex(ptr->link);
		free(ptr);
	}
	return 0;
}
/* 정점 생성 */
int insertVertex(GraphNode* h, int v){
	/* 정점이 존재하는 경우 */
	if((h+v)->vertex == v){
		printf("\n Vertex is already exists!\n");
		return 0;
	}
	/* 정점은 0~9값이 부여되므로 해당 배열값에 생성 */
	(h+v)->vertex = v;
	return 1;
}
/* 간선 생성 */
int insertEdge(GraphNode* h, int u,int v){
	/* 두 정점이 존재하지 않은경우 */
	if((h+u)->vertex != u ||(h+v)->vertex != v);{
		printf("\n Vertex is not exists!\n");
		return 0;
	}

	GraphNode* Edge1 = (GraphNode*)malloc(sizeof(GraphNode));
	GraphNode* Edge2 = (GraphNode*)malloc(sizeof(GraphNode));

}

void DFS(){

}

void BFS(){

}

void printGraph(){

}


/* 스택의 탑 감소 */
GraphNode* pop() {
	if(top < 0) return NULL;
	return stack[top--];
}
/* 스택의 탑을 증가시키고 삽입 */
void push(GraphNode* aNode) {
	stack[++top] = aNode; 
}
/* front를 증가시켜 삭제 */
GraphNode* deQueue()
{
	if(front == rear){
		printf("\n Queue is empty!");
		return NULL;
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}
/* rear를 증가시켜 삽입 */
void enQueue(GraphNode* aNode)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	if(front == rear){
		printf("\n Queue is FULL!\n");
		return;
	}
	queue[rear] = aNode;
}
