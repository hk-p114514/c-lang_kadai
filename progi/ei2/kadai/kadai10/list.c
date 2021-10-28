#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/*
    概要:空リストを取得する
*/
// 第1引数: なし
// 返り値  : 空リストへのポインタ
List *getEmptyList(void) {
	return ((List *)NULL);
}

/*
    概要:新しいセルをひとつ作る
*/
// 第1引数: セルへ格納するデータ
// 第2引数: 次のセルを指すポインタ
// 返り値  : 正しくつくれた：作ったセルを指すポインタ、失敗：空リスト
Cell *createCell(int data, List *next) {
	Cell *p;
	if ((p = (Cell *)malloc(sizeof(Cell))) != NULL) {
		setCellData(p, data);
		setNextCell(p, next);
		return (p);
	} else {
		return (getEmptyList());
	}
}

/*
    概要:指定したセルにデータを格納する(既存のデータを更新する)
*/
// 第1引数: 操作対象になるセルへのポインタ
// 第2引数: セルへ格納する整数のデータ
// 返り値  : returnValue
void setCellData(Cell *cell, int data) {
	cell->data = data;
	return;
}

/*
    概要:指定したセルのデータを取り出す
*/
// 第1引数: 操作対象になるセルへのポインタ
// 返り値  : 取り出した整数のデータ
int getCellData(Cell *cell) {
	return (cell->data);
}

/*
    概要:指定したセルに次のセルのポインタを格納する
*/
// 第1引数: 操作対象になるセルへのポインタ
// 第2引数: 次のセルを指すポインタ
// 返り値  : なし
void setNextCell(Cell *cell, List *next) {
	cell->next = next;
	return;
}

/*
    概要:指定したセルにつながる次のセルのポインタを取り出す
*/
// 第1引数: 操作対象になるセルへのポインタ
// 返り値  : 次のセルを指すポインタ
List *getNextCell(Cell *cell) {
	return (cell->next);
}

/*
    概要:与えられたリストが空リストかどうか調べる
*/
// 第1引数: リストの先頭へのポインタ
// 返り値  : headが空リストの時：1、headが空リストで無い時：0
int isEmptyList(List *head) {
	if (head == getEmptyList()) {
		return (1);
	} else {
		return (0);
	}
}

/*
    概要:新しいセルをリストの先頭へ挿入する
*/
// 第1引数: リストの先頭アドレスを格納している変数へのポインタ
// 第2引数: リストの先頭へ挿入するセルの整数データ
// 返り値  : 追加に成功した時：1、失敗した時：0
int insertHead(List **head, int data) {
	// 新しいセルをひとつ作る -> この時、現在のheadがnextになる
	Cell *p;
	p = createCell(data, *head);

	// エラーチェック
	if (isEmptyList(p) == 1) {
		return (0);
	}

	// 新しく作ったセルリストの先頭にする
	*head = p;

	return (1);
}

/*
    概要:リストの先頭セルを削除する
*/
// 第1引数: リストの先頭アドレスを格納している変数へのポインタ
// 返り値  : 正しく削除できた時：1、失敗した時：0
int removeHead(List **head) {
	// 現在の先頭を保存しておく
	List *p;
	p = *head;

	// 現在の先頭のnextを新たな先頭にする
	*head = getNextCell(*head);

	// エラーチェック
	if (isEmptyList(*head) == 1) {
		return (0);
	}

	// 保存してあった古いheadをfree()
	free(p);

	return (1);
}

/*
    概要:リスト内のデータを先頭から順に表示する
*/
// 第1引数: リストの先頭アドレスを格納している変数へのポインタ
// 返り値  : なし
void printList(List *head) {
	Cell *cell;
	cell = head;
	int data;
	while (isEmptyList(cell) != 1) {
		// データを取得
		data = getCellData(cell);
		// 表示
		printf("%d ", data);

		// 次のセルを取得
		cell = getNextCell(cell);
		// 空かどうか確認
		if (isEmptyList(cell) != 1) {
			// 次のデータを取得
			data = getCellData(cell);
			// 次のデータがあるので矢印表示
			printf("-> ");
		}
	}

	return;
}

// ======= (2) =======

/*
   概要:次のセルを指すポインタを保持しているメンバ変数のアドレスを取得する
*/
// 第1引数: 操作対象になるセルへのポインタ
// 返り値  : 次のセルへのへのポインタを保持しているメンバ変数のアドレス
List **getNextCellHead(Cell *cell) {
	return (&(cell->next));
}

/*
    概要:先頭からデータが昇順に並ぶようにセルを追加
*/
// 第1引数: リストの先頭アドレスを格納している変数へのポインタ
// 第2引数: 新たに挿入するセルの整数値データ
// 返り値  : 追加に成功した時：1、失敗した時：0(元のリストは不変)
int insertUpOrder(List **head, int data) {
	// 対象のセルが空でない、かつ、対象のセルのデータが新しいデータより小さい場合
	while (isEmptyList(*head) == 0 && getCellData(*head) < data) {
		// 対象のセルを次のセルへ移動
		head = getNextCellHead(*head);
	}

	/*
	 * insertHead()の返り値は、
	 * 成功時：1、失敗時：0なので、
	 * その結果をそのまま返す
	 */
	return (insertHead(head, data));
}

/*
    概要:リストの最後のセルの削除
*/
// 第1引数: リストの先頭アドレスを格納している変数へのポインタ
// 返り値  : 正しく削除できた時：1、空リストから削除しようとした時：0
int removeTail(List **head) {
	Cell **before = getNextCellHead(*head);
	while (isEmptyList(*head) == 0 && isEmptyList(getNextCell(*head)) == 0 && isEmptyList(*before) == 0) {
		before = head;
		head = getNextCellHead(*head);
	}

	return (removeHead(before));
}

/*
    概要:リスト全体を削除
*/
// 第1引数: リストの先頭アドレスを格納している変数へのポインタ
// 返り値  : なし
void removeList(List **head);
