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

void initHashTable(HashEntry tbl[], int tbl_size);      // 操作関数①
HashElement *createElement(char *key, char *value);     // 操作関数②
HashElement *searchElement(HashEntry tbl[], char *key); // 操作関数③
char *getValue(HashEntry tbl[], char *key);             // 操作関数④
int setValue(HashElement *element, char *value);
int insertElement(HashEntry tbl[], char *key, char *value); // 操作関数⑤
int updateElement(HashEntry tbl[], char *key, char *value); // 操作関数⑥
int removeElement(HashEntry tbl[], char *key);              // 操作関数⑦
void freeHashTable(HashEntry tbl[], int tbl_size);          // 操作関数⑧
void printHashTable(HashEntry tbl[], int tbl_size);         // 操作関数⑨
unsigned int hash(char *key, int tbl_size);                 // 操作関数⑩

int increaseCount(HashEntry *entry);
int decreaseCount(HashEntry *entry);
int getSynonymCount(HashEntry *entry);
int setKey(HashElement *elem, char *key);
char *getKey(HashElement *elem);
int setHashElementNext(HashElement *elem, HashElement *next);
HashElement *getHashElementNext(HashElement *elem);
void setHashElementProps(HashElement *elem, char *key, char *value);
HashElement *searchElementInSynonym(HashElement *elem, char *key);
HashElement *getNextSynonym(HashElement *elem);
/* HashElement *getHashElement(HashEntry *entry); */
int hasSynonym(HashEntry *entry);
int isEmptyEntry(HashEntry tbl[], char *key);
