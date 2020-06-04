#ifndef _BINARYTREE_H
#define _BINARYTREE_H
struct node
{
	int value;
	struct node* left;
	struct node* right;
};
typedef struct node node;
struct queue
{
	struct queue* next;
	struct node* tree;
};
typedef struct queue queue;
add_new(struct node** root, int value);
dfs(struct node* node);
enqueue(struct queue** head, struct queue** tail, struct node* value);
struct node* dequeue(struct queue** head, struct queue** tail);
bfs(struct node* root);
search(struct node* root, const int num);
statistics(struct node* root);
#endif 