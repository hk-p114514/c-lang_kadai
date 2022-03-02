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
	HashEntry entry = tbl[ n ];

	if (entry.element != NULL) {
		// シノニムの有無を確認
		if (entry.count > 0) {
			// シノニム有り
		} else {
			// シノニムなし
			return (entry.element);
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

		return (1);
	} else {
		// 既にハッシュ値(テーブルに於ける添字)を使っている(リストが存在する)
		// リストに要素を追加する
		return (addSynonym(&tbl[ hash(key, TBL_SIZE) ], key, value));
	}

	// 同一のキーと値を持つ要素が存在する
	return (2);
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
	/*! TODO: Replacing a synonym pointer
	 *  \todo Replacing a synonym pointer
	 *  \todo free memory of key and value
	 *  \todo free element themselves
	 */

	return (0);
}

// 操作関数⑧   ：ハッシュテーブルの要素をすべて削除する（メモリを解放する）
//      tbl[]   ：ハッシュテーブル
//      tbl_size：ハッシュテーブルのサイズ
//      戻り値  ：なし
void freeHashTable(HashEntry tbl[], int tbl_size) {
	printf("FREE HASH TABLE\n");
	return;
}

// 操作関数⑨   ：ハッシュテーブルのすべての要素をキーと値のペアで表示する
//      tbl[]   ：ハッシュテーブル
//      tbl_size：ハッシュテーブルのサイズ
// i     戻り値  ：なし
void printHashTable(HashEntry tbl[], int tbl_size) {
	printf("PRINT HASH TABLE\n");
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
int addSynonym(HashEntry *entry, char *key, char *value) {
	HashElement *new_elem;
	new_elem = createElement(key, value);

	if (new_elem == NULL) {
		return (0);
	}

	// add new element to the list
	new_elem->next = entry->element;
	*entry->element = *new_elem;

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
		return (addSynonymRec(head->next, key, value));
	}

	return (0);
}

/**
 * @brief remove the element which has the specified key.
 *
 * @param entry Pointer to the entry with element to be removed.
 * @param key the key of the element to be removed.
 *
 * @return successfull: 1, not found: 0
 */
int removeSynonym(HashEntry *entry, char *key) {
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
	return (searchInNextByKey(entry->element, key));
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

	if (strcmp(key, elem->key) == 0) {
		return (elem);
	}

	return (searchInNextByKey(elem->next, key));
}
