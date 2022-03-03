#ifndef TBL_SIZE      // もしTBL_SIZEが定義されていなければ
#define TBL_SIZE 2003 // TBL_SIZE(ハッシュテーブルサイズ)を2003にする
#endif

#define KEY_LEN 32  // キーの最大サイズ
#define VAL_LEN 256 // 値の最大サイズ

typedef struct hash_element {  // ハッシュテーブルに格納される一要素
	char *key;                 // キー
	char *value;               // キーに対応する値
	struct hash_element *next; // 次の要素(シノニム)へのポインタ
} HashElement;

typedef struct {          // ハッシュテーブルはこのデータ型の配列
	int count;            // このエントリを共有するシノニムの数
	HashElement *element; // 格納する要素(キーと値のペア)へのポインタ
} HashEntry;

char *getstring(char *msg, char *input);
void initHashTable(HashEntry tbl[], int tbl_size);          // 操作関数①
HashElement *createElement(char *key, char *value);         // 操作関数②
HashElement *searchElement(HashEntry tbl[], char *key);     // 操作関数③
char *getValue(HashEntry tbl[], char *key);                 // 操作関数④
int insertElement(HashEntry tbl[], char *key, char *value); // 操作関数⑤
int updateElement(HashEntry tbl[], char *key, char *value); // 操作関数⑥
int removeElement(HashEntry tbl[], char *key);              // 操作関数⑦
void freeHashTable(HashEntry tbl[], int tbl_size);          // 操作関数⑧
void printHashTable(HashEntry tbl[], int tbl_size);         // 操作関数⑨
unsigned int hash(char *key, int tbl_size);                 // 操作関数⑩
int elemCmp(HashEntry tbl[], HashElement *elem1, HashElement *elem2);

HashElement *searchInSynonymByKey(HashEntry *entry, char *key);
HashElement *searchInNextByKey(HashElement *elem, char *key);

int setValue(HashElement *elem, char *value);
int setKey(HashElement *elem, char *key);
char *getValue2(HashElement *elem);
char *getKey(HashElement *elem);

HashElement *getElementNext(HashElement *elem);
HashElement **getElementNextHead(HashElement *elem);
void setElementNext(HashElement *elem, HashElement *next);
HashElement **getElementNextHead(HashElement *elem);

void freeElement(HashElement **elem);
int removeSynonym(HashEntry tbl[], char *key);
int removeSynonymRec(HashElement *current, char *key);
int removeSynonymHead(HashElement **head);
void removeAllSynonyms(HashEntry *entry);

void printElement(HashElement *elem, int index);
void printAllSynonyms(HashElement *elem, int index);

int addSynonym(HashEntry tbl[], char *key, char *value);
int addSynonymRec(HashElement *head, char *key, char *value);
int insertSynonymHead(HashElement **head, char *key, char *value);

void printHashTableStatus(HashEntry tbl[], int tbl_size);