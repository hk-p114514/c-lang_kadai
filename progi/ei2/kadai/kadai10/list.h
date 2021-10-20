typedef struct cell {
	int data;
	struct cell *next;
} List;

typedef List Cell;

List *getEmptyList(void);
Cell *createCell(int data, List *next);

void setCellData(Cell *cell, int data);
int getCellData(Cell *cell);
void setNextCell(Cell *cell, List *next);
List *getNextCell(Cell *cell);

int isEmptyList(List *head);
int insertHead(List **head, int data);
int removeHead(List **head);
void printList(List *head);

List **getNextCellHead(Cell *cell);
int insertUpOrder(List **head, int data);

int removeTail(List **head);

void removeList(List **head);
