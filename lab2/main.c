#include <stdio.h>
#include <stdlib.h>

#include <time.h>

struct node {

    int type;

    struct node *next;
    struct node *prev;

};

struct queue {

    int size;

    struct node *head;
    struct node *tail;

};

struct node *malloc_node(void)
{
    struct node *node;

    return node = (struct node *) malloc(sizeof (struct node));
}

void queue_init(struct queue *queue)
{
    queue->size = 0;

    queue->head = NULL;
    queue->tail = NULL;
}

int queue_push(struct queue *queue, int type)
{
    queue->size++;
    
    struct node *node;

    node = malloc_node();
    node->type = type;
    node->prev = NULL;
    node->next = queue->head;
    queue->head = node;
    if (queue->size == 1) {
        queue->tail = node;
        return 0;
    }

    queue->head->next->prev = queue->head;
    return 0;
}

void queue_pop(struct queue *queue, int *type)
{
    if (queue->size == 0) return;
    *type = queue->tail->type;
    struct node *node;

    
    node = queue->tail->prev;
    free(queue->tail);
    queue->tail = node;
    queue->size--;
}

void queue_free(struct queue *queue)
{
    int type;

    while (queue->size != 0) queue_pop(queue, &type);
}

int main()
{
    int T = 100000;
    double P1 = 0.005;
    double P2 = 0.05;

    srand(time(NULL));

    double r1, r2;
    int read = 0, write = 0, r_complete = 0, w_complete = 0;
    int type = -1;
    struct queue queue;
    int count;

    queue_init(&queue);

    for (int i = 0; i < T; ++i) {
        r1 = (double) rand() / (double) RAND_MAX;
        r2 = (double) rand() / (double) RAND_MAX;
        if (r1 <= P1) {
            ++write;
            queue_push(&queue, 0);
        }
        if (r2 <= P2) {
            ++read;
            queue_push(&queue, 1);
        }
        if (type == -1) {
            queue_pop(&queue, &type);
            if (type == -1) continue;
            count = 10;
        }

        if (--count == 0) {
            if (type == 0) ++w_complete;
            else ++r_complete;

            type = -1;
        }
    }

    queue_free(&queue);

    printf("All processes: %d", write + read);
    printf("\nRead processes: %d", read);
    printf("\nWrite processes: %d", write);
    printf("\nComplete processes: %d", r_complete + w_complete);
    printf("\nComplete read processes: %d", r_complete);
    printf("\nComplete write processes: %d\n", w_complete);

    return 0;
}
