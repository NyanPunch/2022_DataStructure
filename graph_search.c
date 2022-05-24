/* 11주차 과제
*  2019038054 김경민
*  2022 05 23 ~
*  Graph Search
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 10

typedef struct node{
	int vertex;
	struct node* link;
}graphNode;

void initializeGraph();
void insertVertex();
void insertEdge();
void DFS();
void BFS();
void printGraph();
void freeGraph();

int main()
{
	char command;
	int key;
	Node* head = NULL;

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
			initializeGraph();
			break;
		case 'q': case 'Q':
			freeGraph(head);
			printf("----------------------------------------------------------------\n");
			printf("                    2019038054       김경민                     \n");
			printf("----------------------------------------------------------------\n");
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;
		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;
		case 'l': case 'L':
			levelOrder(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}
