#define SUCCESS 1;
#define ERROR 0;

typedef struct list {
  struct list* prox;
  int value;
  int key;
} LIST;

LIST* LIST_create();
int LIST_size(LIST* list);
int LIST_insert(LIST* list, int key, int val);
void LIST_print(LIST* list);