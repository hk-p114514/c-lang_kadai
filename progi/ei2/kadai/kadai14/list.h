typedef struct cell {
	int data;          // 格納される整数値データ
	struct cell *next; // 次のセルを指すポインタ
} List;

typedef List Cell; // 使用場面に応じて応じてListとCellを使い分ける

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

// New!
int removeSearch(List **head, int data);
int countCells(List *head);
int sumOfCellsData(List *head);
void removeList(List **head);
int appendTail(List **head, int data);
List *reverseList(List *head);
