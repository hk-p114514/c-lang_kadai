#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getstring(char *msg, char *input) {
	printf("%s", msg);
	char buff[ 1024 ];
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%s", input);

	return (input);
}

// 操作関数①   ：ハッシュテーブルの初期化（tbl[]の全要素のcountを0に、elementをNULLにする）
//      tbl[]   ：ハッシュテーブル
//      tbl_size：ハッシュテーブルのサイズ
//      戻り値  ：なし
void initHashTable(HashEntry tbl[], int tbl_size) {
	for (int i = 0; i < tbl_size; i++) {
		tbl[ i ].count = 0;
		tbl[ i ].element = NULL;
	}

	return;
}

// 操作関数②   ：キーと値からなる要素を動的に生成する
//      key   ：キー
//      value ：キーに対応する値
//      戻り値 ：正常に生成できたとき     ＝ 生成した要素へのポインタ
//            ：メモリ確保に失敗したとき ＝ NULL
HashElement *createElement(char *key, char *value) {
	HashElement *elem = (HashElement *)malloc(sizeof(HashElement));

	if (elem == NULL) {
		return (NULL);
	}

	// keyとvalueのメモリを確保し、それぞれのポインタを格納する
	elem->key = (char *)malloc(sizeof(char) * KEY_LEN);
	elem->value = (char *)malloc(sizeof(char) * VAL_LEN);

	if (elem->key == NULL || elem->value == NULL) {
		free(elem->key);
		free(elem->value);
		free(elem);
		return (NULL);
	}

	// keyとvalueに格納する
	strcpy(elem->key, key);
	strcpy(elem->value, value);
	elem->next = NULL;

	return (elem);
}

// 操作関数③   ：キーに対応する要素を検索する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      戻り値  ：キーが見つかったとき ＝ キーに対応する要素へのポインタ
//              ：キーが見つからなかったとき ＝ NULL
HashElement *searchElement(HashEntry tbl[], char *key) {
	// 配列上の添字を取得
	int n = hash(key, TBL_SIZE);
	HashEntry *entry = &tbl[ n ];

	if (entry->element != NULL) {
		// シノニムの有無を確認
		if (entry->count > 0) {
			// シノニム有り
			HashElement *synonym = searchInSynonymByKey(entry, key);
			if (synonym != NULL) {
				return (synonym);
			}
		} else {
			// シノニムなし
			return (entry->element);
		}
	}

	return (NULL);
}

/******************************************************************************
 * Description:     return the element's key
 *****************************************************************************/
char *getKey(HashElement *elem) {
	return (elem->key);
}

// 操作関数④   ：キーに対応する値のみを取得する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      戻り値  ：キーが見つかったとき       ＝ キーに対応する値（文字列）へのポインタ
//              ：キーが見つからなかったとき ＝ NULL
char *getValue(HashEntry tbl[], char *key) {
	HashElement *elem = searchElement(tbl, key);
	if (elem != NULL) {
		return (elem->value);
	} else {
		return (NULL);
	}
}

/**
 * @brief set the value of the element
 *
 * @param elem the element to set the value.
 * @param value the value to set.
 *
 * @return successfull: 1, failed to allocate memory: 0
 */
int setValue(HashElement *elem, char *value) {
	elem->value = (char *)malloc(sizeof(char) * TBL_SIZE);

	if (elem->value == NULL) {
		return (0);
	}

	strcpy(elem->value, value);

	return (1);
}

// 操作関数⑤   ：キーとそれに対応する値からなる要素をハッシュテーブルに挿入する
//              ：ただし、同一のキーと値の要素が、ハッシュテーブルに存在するときは何もしない
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      value   ：キーに対応する値
//      戻り値  ：新たに要素を追加したとき               ＝ 1
//              ：同一のキーと値を持つ要素が存在したとき ＝ 2
//              ：メモリ確保に失敗したとき               ＝ 0
int insertElement(HashEntry tbl[], char *key, char *value) {
	HashElement *search = searchElement(tbl, key);
	if (search == NULL) {
		//  まだ使われていないハッシュ値(まだリストが存在しない)

		// 要素を挿入
		HashElement *elem = createElement(key, value);

		if (elem == NULL) {
			return (0);
		}

		int n = hash(key, TBL_SIZE);
		tbl[ n ].element = elem;

	} else {
		int isSameKey = strcmp(getKey(search), key);
		int isSameValue = strcmp(getValue(tbl, key), value);

		if (isSameKey == 0) {
			// キーが同じ
			if (isSameValue == 0) {
				// 値も同じ
				return (2);
			}
			// キーが同じだが、値が違う -> 値を更新
			if (setValue(search, value) == 0) {
				return (0);
			}
			return (1);
		}
	}
	return (1);
}

// 操作関数⑥   ：指定したキーがあればその値を更新し、なければ新たに要素を挿入する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      value   ：キーに対応する値
//      戻り値  ：更新または追加できたとき ＝ 1
//              ：メモリ確保に失敗したとき ＝ 0
int updateElement(HashEntry tbl[], char *key, char *value) {
	int result = insertElement(tbl, key, value);

	if (result == 0) {
		// メモリ確保に失敗したとき
		return (0);
	} else if (result == 1) {
		// 新たに要素を追加したとき
		return (1);
	} else if (result == 2) {
		// 同一のキーと値を持つ要素が存在したとき
		// 値を更新する
		HashEntry *target = &tbl[ hash(key, TBL_SIZE) ];
		return (setValue(target->element, value));
	}

	return (0);
}

// 操作関数⑦   ：キーで要素を検索し、見つかった要素を削除する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      戻り値  ：キーが見つかり要素を削除したとき ＝ 1
//              ：キーが見つからなかったとき       ＝ 0
int removeElement(HashEntry tbl[], char *key) {
	HashElement *remove = searchElement(tbl, key);
	int n = hash(key, TBL_SIZE);
	int count = tbl[ n ].count;
	if (count > 0) {
		// シノニム(リスト)の中からkeyが同じものを探す必要がある
		return (removeSynonym(tbl, key));
	} else {
		// シノニム(リスト)が存在しない
		freeElement(&tbl[ n ].element);
	}

	return (0);
}

// 操作関数⑧   ：ハッシュテーブルの要素をすべて削除する（メモリを解放する）
//      tbl[]   ：ハッシュテーブル
//      tbl_size：ハッシュテーブルのサイズ
//      戻り値  ：なし
void freeHashTable(HashEntry tbl[], int tbl_size) {
	for (int i = 0; i < TBL_SIZE; i++) {
		HashEntry remove = tbl[ i ];
		int count = remove.count;
	}
	return;
}

// 操作関数⑨   ：ハッシュテーブルのすべての要素をキーと値のペアで表示する
//      tbl[]   ：ハッシュテーブル
//      tbl_size：ハッシュテーブルのサイズ
// i     戻り値  ：なし
void printHashTable(HashEntry tbl[], int tbl_size) {
	printf("Index\tKey\t\t\tValue\n");
	printf("------------------------------\n");
	for (int i = 0; i < TBL_SIZE; i++) {
		HashEntry entry = tbl[ i ];
		HashElement *elem = entry.element;
		if (elem != NULL) {
			printElement(elem, i);

			// シノニムの表示
		}
	}
	return;
}
void printElement(HashElement *elem, int index) {
	printf("%4d:\t%s\t\t%s\n", index, elem->key, elem->value);
	return;
}

void printAllSynonyms(HashElement *elem, int index) {
	if (elem == NULL) {
		return;
	}
	printElement(elem, index);
	if (strcmp(getKey(elem), getKey(getElementNext(elem))) != 0) {
		printAllSynonyms(getElementNext(elem), index);
	}
	return;
}

// 操作関数⑩   ：キーからハッシュ値を求める
//      tbl_size：ハッシュテーブルのサイズ
//      戻り値  ：ハッシュ値（ハッシュテーブルのサイズを超えない非負整数）
#ifndef MY_HASH
unsigned int hash(char *key, int tbl_size) {
	unsigned int hash_value;

	for (hash_value = 0; *key != '\0'; key++) {
		hash_value = hash_value + (unsigned int)((*key) * (*key));
	}

	return (hash_value % tbl_size);
}
#else
unsigned int hash(unsigned char *name, int tbl_size) {
	// ここに、自分で考えたハッシュ関数を記述する
}
#endif

/**
 * @brief Compare two elements and
 *        returns 0 if the contents are the same,
 *        otherwise returns non-zero.
 * @param tbl[] hash table
 * @param elem1 one of the elements to compare
 * @param elem2 one of the elements to compare
 *
 * @return same: 0. not same: 1
 */
int elemCmp(HashEntry tbl[], HashElement *elem1, HashElement *elem2) {
	// compare keys
	char key1[ KEY_LEN ];
	char key2[ KEY_LEN ];

	strcpy(getKey(elem1), key1);
	strcpy(getKey(elem2), key2);

	// compare keys
	if (strcmp(key1, key2) != 0) {
		return (1);
	}

	// compare values
	if (strcmp(getValue(tbl, key1), getValue(tbl, key2)) != 0) {
		return (1);
	}
	return (0);
}

/**
 * @brief add a new element as a synonym
 *        for the specified element.
 *
 * @param entry Pointer to head of list.
 * @param key the key of the synonym to be added.
 * @param value the value of the synonym to be added.
 *
 * @return successfull: 1, failed to allocate of memory: 0
 */
int addSynonym(HashEntry tbl[], char *key, char *value) {
	HashElement *elem = createElement(key, value);
	if (elem == NULL) {
		return (0);
	}

	/*
	 * リストの先頭に次々とシノニムを追加する
	 * */
	int n = hash(key, TBL_SIZE);
	HashElement **head = &tbl[ n ].element;

	// 追加するシノニムの次の要素を現在の先頭要素にする
	elem->next = *head;

	// 先頭に追加
	tbl[ n ].element = elem;

	tbl[ n ].count++;

	return (1);
}

/**
 * @brief add a new element as a synonym.
 *
 * @param head Pointer to pointer of the element to which the synonym is to be added.
 * @param key the key of the synonym to be added.
 * @param value the value of the synonym to be added.
 *
 * @return successfull: 1, failed to allocate of memory: 0, exist same key: 2
 */
int addSynonymRec(HashElement *head, char *key, char *value) {
	if (head == NULL) {
		// リストの最後尾
		head = createElement(key, value);
		if (head != NULL) {
			return (1);
		}
	} else if (strcmp(key, getKey(head)) == 0) {
		// 同じキーを持つ要素が存在する
		return (2);
	} else {
		return (addSynonymRec(getElementNext(head), key, value));
	}

	return (0);
}

/**
 * @brief	search the element which has the specified key.
 *
 * @param tbl[]	hash table
 * @param key	the key of the element to be searched.
 *
 * @return	Pointer to the element which has the specified key.
 *          NULL if the element is not found.
 */
HashElement *searchInSynonymByKey(HashEntry *entry, char *key) {
	HashElement *search = searchInNextByKey(entry->element, key);
	if (search != NULL) {
		return (search);
	} else {
		return (NULL);
	}
}

/**
 * @brief search the element which has the specified key.
 *
 * @param elem the element to be searched by key.
 * @param key the key of the element to be searched.
 *
 * @return	Pointer to the element which has the specified key.
 *          NULL if the element is not found.
 */
HashElement *searchInNextByKey(HashElement *elem, char *key) {
	if (elem == NULL) {
		return (NULL);
	}

	if (strcmp(key, getKey(elem)) == 0) {
		return (elem);
	}

	return (searchInNextByKey(getElementNext(elem), key));
}

/**
 * @brief return next element
 *
 * @param elem the element of list
 *
 * @return the next element of list
 */
HashElement *getElementNext(HashElement *elem) {
	if (elem == NULL) {
		return (NULL);
	}
	return (elem->next);
}

HashElement **getElementNextHead(HashElement *elem) {
	if (elem == NULL) {
		return (NULL);
	}
	return (&(elem->next));
}

/**
 * @brief free element
 *
 * @param elem the element to free
 */
void freeElement(HashElement **elem) {
	if (elem == NULL) {
		return;
	}

	HashElement **next = getElementNextHead(*elem);
	if (*next != NULL) {
		free(next);
	}
	HashElement *tmp = *elem;

	free(tmp->key);
	free(tmp->value);
	free(elem);

	return;
}

/**
 * @brief remove the synonym which has specified key
 *
 * @param tbl[] hash table
 * @param key the key to be removed
 *
 * @return successfull: 1, failed(not found the key): 0
 */
int removeSynonym(HashEntry tbl[], char *key) {
	int result = removeSynonymRec(tbl[ hash(key, TBL_SIZE), TBL_SIZE ].element, key);
	if (result == 0) {
		return (0);
	} else {
		tbl[ hash(key, TBL_SIZE) ].count--;
		return (1);
	}
}

int removeSynonymRec(HashElement *current, char *key) {
	if (current == NULL) {
		return (0);
	}

	// 先頭の要素を削除しようとしていた場合
	if (strcmp(key, getKey(current)) == 0) {
		return (removeSynonymHead(&current));
	}

	// 次のセルのキーがkeyと同じなら、その次のセルをnextとしてつなぎ替える
	HashElement *next = getElementNext(current);
	if (strcmp(key, getKey(current)) == 0) {
		return (removeSynonymHead(&next));
	}

	return (removeSynonymRec(next, key));
}

/**
 * @brief remove head of list and change head
 *
 * @param head   the element to be removed
 *
 * @return       successfull: 1, failed(when the head is empty): 0
 */
int removeSynonymHead(HashElement **head) {
	if (*head != NULL) {
		HashElement **p = head;

		// headをheadの次の要素につなぎ替える
		head = getElementNextHead(*head);

		free(p);

		return (1);
	}

	return (0);
}

/**
 * @brief remove and free all synonyms
 *
 * @param entry the entry which has elements to be removed
 */
void removeAllSynonyms(HashEntry *entry) {
	if (removeSynonymHead(getElementNextHead(entry->element)) == 1) {
		removeAllSynonyms(entry);
	}
}
