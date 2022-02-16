#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
//      key     ：キー
//      value   ：キーに対応する値
//      戻り値  ：正常に生成できたとき     ＝ 生成した要素へのポインタ
//	            ：メモリ確保に失敗したとき ＝ NULL
HashElement *createElement(char *key, char *value) {
	HashElement *elem = (HashElement *)malloc(sizeof(HashElement));
	setHashElementProps(elem, key, value, NULL);

	return (elem);
}

// 操作関数③   ：キーに対応する要素を検索する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      戻り値  ：キーが見つかったとき ＝ キーに対応する要素へのポインタ
//              ：キーが見つからなかったとき ＝ NULL
HashElement *searchElement(HashEntry tbl[], char *key) {
	// キーから配列上の添字を取得
	int p = hash(key, TBL_SIZE);

	// 添字から要素を検索
	HashEntry *entry = &tbl[ p ];
	HashElement *elem = getHashElement(entry);

	if (hasSynonym(entry)) {
		// シノニム有り
		elem = searchElementInSynonym(elem, key);
		if (elem) {
			// シノニムの中からキーに対応する要素が見つかった
			return (elem);
		}
	} else {
		// シノニムなし
		return (elem);
	}

	return (NULL);
}

// 操作関数④   ：キーに対応する値のみを取得する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      戻り値  ：キーが見つかったとき       ＝ キーに対応する値（文字列）へのポインタ
//              ：キーが見つからなかったとき ＝ NULL
char *getValue(HashEntry tbl[], char *key) {
	HashElement *target = searchElement(tbl, key);
	if (target) {
		return (target->value);
	}
	return (NULL);
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
	// キーから配列上の添字を演算
	int p = hash(key, TBL_SIZE);
	// 要素を作成
	HashElement *elem = createElement(key, value);

	// ハッシュテーブルに要素を挿入
	// todo:

	return (0);
}

// 操作関数⑥   ：指定したキーがあればその値を更新し、なければ新たに要素を挿入する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      value   ：キーに対応する値
//      戻り値  ：更新または追加できたとき ＝ 1
//              ：メモリ確保に失敗したとき ＝ 0
int updateElement(HashEntry tbl[], char *key, char *value) {
	return (0);
}

// 操作関数⑦   ：キーで要素を検索し、見つかった要素を削除する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      戻り値  ：キーが見つかり要素を削除したとき ＝ 1
//              ：キーが見つからなかったとき       ＝ 0
int removeElement(HashEntry tbl[], char *key) {
	return (0);
}

// 操作関数⑧   ：ハッシュテーブルの要素をすべて削除する（メモリを解放する）
//      tbl[]   ：ハッシュテーブル
//      tbl_size：ハッシュテーブルのサイズ
//      戻り値  ：なし
void freeHashTable(HashEntry tbl[], int tbl_size) {
	return;
}

// 操作関数⑨   ：ハッシュテーブルのすべての要素をキーと値のペアで表示する
//      tbl[]   ：ハッシュテーブル
//      tbl_size：ハッシュテーブルのサイズ
// i     戻り値  ：なし
void printHashTable(HashEntry tbl[], int tbl_size) {
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

/*
    概要:ハッシュテーブル内のある一ハッシュ値に於けるシノニムの個数を返す
*/
// 第1引数: ハッシュテーブル内の一要素
// 返り値  : シノニムの数
int getSynonymCount(HashEntry *entry) {
	return (entry->count);
}

/*
    概要:ハッシュテーブルの一要素の次の要素（シノニム）を返す
*/
// 第1引数: ハッシュテーブルの一要素
// 返り値  : 次の要素（シノニム）
HashElement *getNextSynonym(HashElement *elem) {
	return (elem->next);
}

/*	概要:ハッシュテーブルのある一要素がシノニムを持つかどうかを返す
 */
// 第1引数: ハッシュテーブルの一要素
// 返り値  : シノニムを持つ：1、持たない：0
int hasSynonym(HashEntry *entry) {
	if (getSynonymCount(entry) > 0) {
		return (1);
	} else {
		return (0);
	}
}

/*
    概要:ハッシュの一要素を取り出す
*/
// 第1引数: ハッシュテーブル配列の一要素
// 返り値  : ハッシュの一要素
HashElement *getHashElement(HashEntry *entry) {
	return (entry->element);
}

/* 概要:ハッシュテーブルの一要素のキーを設定する
 */
// 第1引数: ハッシュテーブルの一要素
// 第2引数: 設定するキー
// 返り値  : なし
void setHashElementKey(HashElement *element, char *key) {
	element->key = key;
	return;
}

/*	概要:ハッシュテーブルの一要素のキーを取得する
 */
// 第1引数: ハッシュテーブルの一要素
// 返り値  : 渡されたハッシュテーブルの一要素のキー
char *getKey(HashElement *element) {
	return (element->key);
}

/*	概要:ハッシュテーブルの一要素の値を設定する
 */
// 第1引数: ハッシュテーブルの一要素
// 第2引数: 設定する値
// 返り値  : なし
void setHashElementValue(HashElement *element, char *value) {
	element->value = value;
	return;
}

/*	概要:ハッシュテーブルの一要素の次の要素（シノニム）を設定する
 */
// 第1引数: シノニムを設定する要素
// 返り値  : 既に次の要素が設定サれていた：0、新しく次の要素を設定した：1
int setHashElementNext(HashElement *element, HashElement *next) {
	int isExistNext = 0;
	if (getHashElementNext(element)) {
		isExistNext = 1;
	}

	element->next = next;

	return (isExistNext);
}

HashElement *getHashElementNext(HashElement *element) {
	return (element->next);
}

void setHashElementProps(HashElement *elem, char *key, char *value, HashElement *next) {
	setHashElementKey(elem, key);
	setHashElementValue(elem, value);
	setHashElementNext(elem, next);

	return;
}

/*
    概要:シノニムの中からキーが一致する要素を探す
*/
// 第1引数: ハッシュテーブルの一要素
// 返り値  : キーの一致した要素、なければNULLポインタ
HashElement *searchElementInSynonym(HashElement *elem, char *key) {
	if (getNextSynonym(elem)) {
		return (NULL);
	} else {
		if (strcmp(key, getKey(elem)) == 0) {
			// 探したいキーと一致した
			return (elem);
		}
		// 次のシノニムと比較しに行く
		return (searchElementInSynonym(getHashElementNext(elem), key));
	}
}