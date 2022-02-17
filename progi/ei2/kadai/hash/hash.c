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
		// searchElementInSynonym()は該当するシノニムが無かった時NULLを返す
		return (searchElementInSynonym(elem, key));
	} else {
		// シノニムなし
		return (elem);
	}
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

/*	概要:ハッシュテーブルの一要素の値を設定する
 */
// 第1引数: ハッシュテーブルの一要素
// 第2引数: 設定する値
// 返り値  : なし
void setValue(HashElement *elem, char *value) {
	elem->value = value;
	return;
}

/*	概要:ハッシュテーブルの一要素のキーを取得する
 */
// 第1引数: ハッシュテーブルの一要素
// 返り値  : 渡されたハッシュテーブルの一要素のキー
char *getKey(HashElement *elem) {
	return (elem->key);
}

/* 概要:ハッシュテーブルの一要素のキーを設定する
 */
// 第1引数: ハッシュテーブルの一要素
// 第2引数: 設定するキー
// 返り値  : なし
void setKey(HashElement *elem, char *key) {
	elem->key = key;
	return;
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
	// todo:コアダンプ
	// キーから配列上の添字を演算
	int p = hash(key, TBL_SIZE);
	// 対象となるテーブル箇所
	HashEntry *entry = &tbl[ p ];
	// 要素を作成
	HashElement *elem = createElement(key, value);

	if (isEmptyEntry(tbl, key)) {
		// 該当箇所が未使用
		setHashElementProps(getHashElement(entry), key, value, NULL);
	} else {
		// 既に要素がある（シノニムとして追加）
		increaseCount(entry);
		// todo
	}

	return (0);
}

// 操作関数⑥   ：指定したキーがあればその値を更新し、なければ新たに要素を挿入する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      value   ：キーに対応する値
//      戻り値  ：更新または追加できたとき ＝ 1
//              ：メモリ確保に失敗したとき ＝ 0
int updateElement(HashEntry tbl[], char *key, char *value) {
	int p = hash(key, TBL_SIZE);
	if (isEmptyEntry(tbl, key)) {
		// 該当箇所に要素は存在しないので新たに作る
		if (insertElement(tbl, key, value)) {
			return (1);
		}
	}
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
	setKey(elem, key);
	setValue(elem, value);
	setHashElementNext(elem, next);

	return;
}

/*
    概要:シノニムの中からキーが一致する要素を探す
*/
// 第1引数: ハッシュテーブルの一要素
// 返り値  : キーの一致した要素、なければNULL
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

/*
    概要:ハッシュテーブルの該当箇所が未使用かどうか調べる
*/
// 第1引数: ハッシュテーブル
// 第2引数: キー
// 返り値  : 該当箇所が未使用：1、使用済み：0
int isEmptyEntry(HashEntry tbl[], char *key) {
	if (getValue(tbl, key) != NULL) {
		return (0);
	} else {
		return (1);
	}
}

/*
    概要:シノニムの個数を表すカウントを増加させる
*/
// 第1引数: ハッシュテーブルの一要素
// 返り値  : 変化後の値
int increaseCount(HashEntry *entry) {
	entry->count++;
	return (entry->count);
}

/*
    概要:シノニムの個数を表すカウントを減少させる
*/
// 第1引数: ハッシュテーブルの一要素
// 返り値  : 正常に減少させた：変化後の値、0から引こうとした：-1
int decreaseCount(HashEntry *entry) {
	if (entry->count > 0) {
		entry->count--;
		return (entry->count);
	} else {
		return (-1);
	}
}