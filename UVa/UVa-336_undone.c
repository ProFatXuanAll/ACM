#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 100000

static int NC;	/* number of connections between network nodes */

struct Node{	/* node structure */
	int num;	/* node number */
	struct Node* next;	/* link list */
};

struct AdjL{	/* adjacency list structure */
	int num;	/* node number */
	struct Node* next;	/* link list */
	int visit;	/* visit flag */
	int dist;	/* distance */
};

static struct AdjL network[MAX_NODE];	/* graph of network */
static struct AdjL swap;	/* temporary storage for swapping */
static struct Node *travel;	/* traveling list pointer */
static int qp1, qp2;	/* query pair */
static int TotalNode;	/* total node number */
static int BinSrch(const int target);	/* Binary Search to find suitable place */

static void BFS(int num, int step);	/* Breadth First Search within 'step' steps */
static int queue[MAX_NODE];	/* queue for BFS */
static int front=0, rear=0;	/* queue's front and rear */
static void push(int num);	/* push into queue */
static int pop(void);	/* pop from queue */

static int counter=1;	/* case counter */
static void FreeList(void);	/* free all allocated memory */

int main(void){
	int i, j, k;	/* loop counter */

	while(1){	/* main while */
		scanf("%d",&NC);	/* get NC */
		
		if(!NC){	/* zero means end of input */
			break;
		}

		TotalNode=0;

		for(i=0;i<NC;i++){	/* get network */
			scanf("%d%d",&qp1,&qp2);
			
			if(TotalNode==0){	/* first time */
				if(qp1!=qp2){	/* normal pair: different node */
					network[0].num=qp1;
					network[0].next=malloc(sizeof(struct Node));
					network[0].next->num=qp2;
					network[0].next->next=NULL;
					network[1].num=qp2;
					network[1].next=malloc(sizeof(struct Node));
					network[1].next->num=qp1;
					network[1].next->next=NULL;
					TotalNode=2;
				
					if(qp1>qp2){	/* need to sort */
						swap=network[0];
						network[0]=network[1];
						network[1]=swap;
					}
				}
				else{	/* abnormal pair: same node */
					network[0].num=qp1;
					network[0].next=NULL;
					TotalNode=1;
				}
			}
			else{	/* insert with order */
				if(qp1!=qp2){	/* normal pair: different node */
					j=BinSrch(qp1);	/* use binary search to find best fitting location for qp1 */
					if(network[j].num==qp1){	/* already exist */
						travel=network[j].next;
						while(travel!=NULL&&travel->next!=NULL){
							travel=travel->next;
						}
						travel->next=malloc(sizeof(struct Node));
						travel->next->num=qp2;
						travel->next->next=NULL;
					}
					else{	/* get newnode */
						if(network[j].num>qp1){	/* insert in front of network[j] */
							for(k=TotalNode-1;k>=j;k--){	/* shift left */
								network[k+1]=network[k];
							}
							network[j].num=qp1;
							network[j].next=malloc(sizeof(struct Node));
							network[j].next->num=qp2;
							network[j].next->next=NULL;
						}
						else{	/* insert at back of network[j] */
							for(k=TotalNode-1;k>=j+1;k--){	/* shift left */
								network[k+1]=network[k];
							}
							network[j+1].num=qp1;
							network[j+1].next=malloc(sizeof(struct Node));
							network[j+1].next->num=qp2;
							network[j+1].next->next=NULL;
						}
						TotalNode++;
					}
					j=BinSrch(qp2);	/* use binary search to find best fitting location for qp2 */
					if(network[j].num==qp2){	/* already exist */
						travel=network[j].next;
						while(travel!=NULL&&travel->next!=NULL){
							travel=travel->next;
						}
						travel->next=malloc(sizeof(struct Node));
						travel->next->num=qp1;
						travel->next->next=NULL;
					}
					else{	/* get newnode */
						if(network[j].num>qp2){	/* insert in front of network[j] */
							for(k=TotalNode-1;k>=j;k--){	/* shift left */
								network[k+1]=network[k];
							}
							network[j].num=qp2;
							network[j].next=malloc(sizeof(struct Node));
							network[j].next->num=qp1;
							network[j].next->next=NULL;
						}
						else{	/* insert at back of network[j] */
							for(k=TotalNode-1;k>=j+1;k--){	/* shift left */
								network[k+1]=network[k];
							}
							network[j+1].num=qp2;
							network[j+1].next=malloc(sizeof(struct Node));
							network[j+1].next->num=qp1;
							network[j+1].next->next=NULL;
						}
						TotalNode++;
					}
				}
				else{	/* abnormal pair: same node */
					j=BinSrch(qp1);	/* use binary search to find best fitting location for qp1 */
					if(network[j].num!=qp1){	/* get new node */
						if(network[j].num>qp1){	/* insert in front of network[j] */
							for(k=TotalNode-1;k>=j;k--){	/* shift left */
								network[k+1]=network[k];
							}
							network[j].num=qp1;
							network[j].next=NULL;
						}
						else{	/* insert at back of network[j] */
							for(k=TotalNode-1;k>=j+1;k--){	/* shift left */
								network[k+1]=network[k];
							}
							network[j+1].num=qp1;
							network[j+1].next=NULL;
						}
						TotalNode++;
					}
				}
			}

		}	/* end NC for */


		while(1){	/* query while */
			scanf("%d%d",&qp1,&qp2);	/* get query */

			if(!qp1&&!qp2){	/* zero means end of input */
				break;
			}

			if(network[BinSrch(qp1)].num!=qp1){	/* qp1 is not in graph  */
				printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", counter, TotalNode, qp1, qp2);
				counter++;
			}
			else if(qp2>0){	/* step > 0 */
				BFS(qp1,qp2);
			}
			else{	/* step <= 0  */
				printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", counter, TotalNode-1, qp1, 0);
				counter++;
			}

		}	/* end query while */

		FreeList();	/* free all memory */

	}	/* outer while */

	return 0;
}

static int BinSrch(const int target)
{
	int high=TotalNode-1;
	int low=0;
	int mid=(high+low)/2;

	while(high>=low){
		mid=(high+low)/2;
		if(network[mid].num==target){
			return mid;
		}
		else if(network[mid].num<target){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}

	return mid;
}

static void BFS(int num, int step)
{
	int visitCounter=0;	/* visited node counter */
	int curNode;	/* currently visit node */
	int hash1, hash2;	/* hash function */
	int i;	/* loop counter */

	for(i=0;i<TotalNode;i++){	/* initialize visit */
		network[i].visit=0;
		network[i].dist=0;
	}
	
	front=rear=0;	/* queue initailize */
	push(num);	/* push into queue */

	while(front!=rear){	/* queue is not empty */
		curNode=pop();	/* pop from queue */
		hash1=BinSrch(curNode);	/* hash to get array position */
		network[hash1].visit=2;	/* set visit flag to 2, status: visited */

		if(network[hash1].num!=curNode){	/* node not exist */
			break;
		}

		if(network[hash1].dist>step){	/* out of step */
			break;
		}

		visitCounter++;	/* visit node counter increment */
		travel=network[hash1].next;
		while(travel!=NULL){	/* traveling link list */
			hash2=BinSrch(travel->num);
			if(network[hash2].visit==0){	/* not visit yet */
				push(travel->num);
				network[hash2].dist=network[hash1].dist+1;
				network[hash2].visit=1;	/* set visit flag to 1, status: in queue but not visit */
			}
			travel=travel->next;
		}
	}	/* end while */

	printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", counter, TotalNode-visitCounter, num, step);
	counter++;

	return;
}

static void push(int num)
{
	queue[front]=num;
	front=(front+1)%MAX_NODE;
}

static int pop(void)
{
	int tmp=queue[rear];
	rear=(rear+1)%MAX_NODE;
	return tmp;
}

static void FreeList(void)
{
	struct Node* prev, *cur;
	int i;
	
	for(i=0;i<TotalNode;i++){
		cur=network[i].next;
		while(cur!=NULL){
			prev=cur;
			cur=cur->next;
			free(prev);
		}
	}

	return;
}
