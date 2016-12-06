typedef struct node{
	char* word;
	struct node *next;
} Node;

typedef struct stack{
	Node* top;
	int size;
} Stack;

Stack* initializeStack();
void push(char* word, Stack* stack);
char* copyWord(char* word, Stack* stack);
void pop(Stack* stack);
void print(Stack* stack);
void freeStack(Stack* stack);
void freeNode(Node* node);
