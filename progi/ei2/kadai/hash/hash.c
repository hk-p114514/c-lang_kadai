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

	return (elem);
}

// 操作関数③   ：キーに対応する要素を検索する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      戻り値  ：キーが見つかったとき ＝ キーに対応する要素へのポインタ
//              ：キーが見つからなかったとき ＝ NULL
HashElement *searchElement(HashEntry tbl[], char *key) {
	// キーから配列上の添字を取得
	int size = getTableSize(tbl);
	int p = hash(key, size);

	// 添字から要素を検索
	HashEntry *found;
	*found = tbl[ p ];
	// シノニムの個数を取得
	int synonym = getSynonymCount(found);

	if (synonym > 0) {
		// シノニム有り
	} else {
		// シノニムなし
		return (getHashElement(found));
	}
}

// 操作関数④   ：キーに対応する値のみを取得する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      戻り値  ：キーが見つかったとき       ＝ キーに対応する値（文字列）へのポインタ
//              ：キーが見つからなかったとき ＝ NULL
char *getValue(HashEntry tbl[], char *key) {
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
}

// 操作関数⑥   ：指定したキーがあればその値を更新し、なければ新たに要素を挿入する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      value   ：キーに対応する値
//      戻り値  ：更新または追加できたとき ＝ 1
//              ：メモリ確保に失敗したとき ＝ 0
int updateElement(HashEntry tbl[], char *key, char *value) {
}

// 操作関数⑦   ：キーで要素を検索し、見つかった要素を削除する
//      tbl[]   ：ハッシュテーブル
//      key     ：検索するキー
//      戻り値  ：キーが見つかり要素を削除したとき ＝ 1
//              ：キーが見つからなかったとき       ＝ 0
int removeElement(HashEntry tbl[], char *key) {
}

// 操作関数⑧   ：ハッシュテーブルの要素をすべて削除する（メモリを解放する）
//      tbl[]   ：ハッシュテーブル
//      tbl_size：ハッシュテーブルのサイズ
//      戻り値  ：なし
void freeHashTable(HashEntry tbl[], int tbl_size) {
}

// 操作関数⑨   ：ハッシュテーブルのすべての要素をキーと値のペアで表示する
//      tbl[]   ：ハッシュテーブル
//      tbl_size：ハッシュテーブルのサイズ
// i     戻り値  ：なし
void printHashTable(HashEntry tbl[], int tbl_size) {
}

// 操作関数⑩   ：キーからハッシュ値を求める
//      tbl_size：ハッシュテーブルのサイズ
//      戻り値  ：ハッシュ値（ハッシュテーブルのサイズを超えない非負整数）
#ifndef MY_HASH
unsigned int hash(unsigned char *key, int tbl_size) {
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
  概要:ハッシュテーブルのテーブルサイズを取得する
*/
// 第1引数: ハッシュテーブル
// 返り値  : テーブルのサイズ
int getTableSize(HashEntry tbl[]) {
	return (sizeof(tbl) / TBL_SIZE);
}

/*
    概要:ハッシュテーブル内のある一ハッシュ値に於けるシノニムの個数を返す
*/
// 第1引数: ハッシュテーブル内の一要素
// 返り値  : シノニムの数
int getSynonymCount(HashEntry *entry) {
	return (entry->count);
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
		// todo: 操作関数作る
		if (strcmp(key, elem->key) == 0) {
			return (elem);
		}
		return (searchElementInSynonym(elem->next, key));
	}
}

/*
    概要:ハッシュテーブルの一要素の次の要素（シノニム）を返す
*/
// 第1引数: ハッシュテーブルの一要素
// 返り値  : 次の要素（シノニム）
HashElement *getNextSynonym(HashElement *elem) {
	return (elem->next);
}

/*
    概要:ハッシュの一要素を取り出す
*/
// 第1引数: ハッシュテーブル配列の一要素
// 返り値  : ハッシュの一要素
HashElement *getHashElement(HashEntry *elem) {
	return (elem->element);
}

void setHashElement(HashElement *elem, char *key, char *value) {
	elem->key = key;
	elem->value = value;

	return;
}