#include "tree.h"
#include <hamakou.h>
#include <stdio.h>
#include <stdlib.h>

int mkBinSearchTree(Tree **root, int data);
int rmBinSearchTreeNode(Tree **root, int target);
Tree **maxValueNode(Tree **root);

int main() {
	Tree *root;
	int n, i, data, found;

	n = getint("データ数: ");
	putchar('\n');
	root = getEmptyTree();
	for (i = 1; i <= n; i++) {
		data = getint("追加データ: "); // データの入力
		putchar('\n');
		found = mkBinSearchTree(&root, data); // 二分探索木の生成
		printf("found: %d\n\n", found);
		printTree2(root); // 木の表示(データ数付き)
		putchar('\n');
	}

	do {                               // 二分探索木から指定した節を削除する
		data = getint("削除データ: "); // 削除するデータの値を入力
		putchar('\n');
		found = rmBinSearchTreeNode(&root, data); // 削除に成功すれば 1
		printf("found: %d\n\n", found);
		printTree2(root); // バランス木の表示(データ数付き)
		putchar('\n');
		// 削除対象のデータが存在しないか、または空木になるまで繰り返す
	} while (found == 1 && !isEmptyTree(root));

	rmTree(&root); // 生成した二分探索木を削除して終了

	return (0);
}

//--------------------------------------------------------------------------------
//  二分探索木を生成する(既に格納されている値のときはノードカウンタを1つ増やす）
//  ［引　数］root : データを追加する二分探索木のルートへのポインタ
//            data : 追加する整数データ
//
//  ［戻り値］data が既に木に格納されているとき(探索成功)      :  1
//            data が新たに木へ追加されたとき(探索失敗)        :  0
//            新規ノードの追加に失敗したとき(ノード生成に失敗) : -1
//--------------------------------------------------------------------------------
int mkBinSearchTree(Tree **root, int data) {
	//
	// prog34-03.c の mkBinSearchTree() をここにコピーする
	//
	Tree *new_node;
	int found;

	if (isEmptyTree(*root)) { // 対象データがまだ木に格納されていないとき
		*root = createNode(data);
		if (isEmptyTree(*root)) {
			return (-1); // ノード生成に失敗した
		}
		found = 0;
	} else {
		if (data < getNodeData(*root)) {
			// 対象データが部分木の根の値より小さいとき
			found = mkBinSearchTree(getSubTreeRoot(*root, 'L'), data);
		} else if (data > getNodeData(*root)) {
			// 対象データが部分木の根の値より大きいとき
			found = mkBinSearchTree(getSubTreeRoot(*root, 'R'), data);
		} else {
			// 対象データが部分木の根の値と一致したとき
			found = 1;
			// rootと同じ値なら左部分木に追加する
			incrementEqualValueCount(*root);
		}
	}
	return (found);
}

//--------------------------------------------------------------------------------
//  二分探索木から指定した値を持つノードを削除
//  ［引　数］root   : 削除対象の二分探索木のルートへのポインタ
//            target : 削除する整数データ
//
//  ［戻り値］target が存在し、削除が成功したとき     : 1
//            target がが存在せず、削除に失敗したとき : 0
//--------------------------------------------------------------------------------
int rmBinSearchTreeNode(Tree **root, int target) {
	int found;
	if (isEmptyTree(*root)) {
		// 指定した値を持つノードが存在しないとき
		return (0);
	} else if (target < getNodeData(*root)) {
		// 左部分木から探し出す
		found = rmBinSearchTreeNode(getSubTreeRoot(*root, 'L'), target);
	} else if (target > getNodeData(*root)) {
		// 右部分木から探し出す
		found = rmBinSearchTreeNode(getSubTreeRoot(*root, 'R'), target);
	} else {
		// 指定した値を持つノードを見つけたとき
		/**
		 * 1.同じ値を持つノードが複数存在する
		 *  - カウントを一つ減らすだけ
		 *  - 終了
		 * 2.指定した値を持つノードが一つだけの場合
		 * - 削除ノードが...部分木を持つ(持たない)場合...
		 * - 35-01と同様 -
		 */
		if (isExistEqualValueNode(*root)) {
			decrementEqualValueCount(*root);
			found = 1;
		} else {
			Node *rm_node = *root;
			Node **maxvalue_node;
			if (isEmptyTree(getSubTree(rm_node, 'R'))) {
				// 削除ノードが右部分木を持たないとき、削除ノードの左部分木でつなぎ替える
				*root = getSubTree(*root, 'L');
				freeNode(&rm_node);
			} else if (isEmptyTree(getSubTree(rm_node, 'L'))) {
				// 削除ノードが左部分木を持たないとき、削除ノードの右部分木でつなぎ替える
				*root = getSubTree(*root, 'R');
				freeNode(&rm_node);
			} else {
				// 削除ノードが２つの子を持つとき、左部分木の最大値(最右端)で置き換える
				maxvalue_node = maxValueNode(getSubTreeRoot(*root, 'L'));
				setNodeData(*root, getNodeData(*maxvalue_node));
				rm_node = *maxvalue_node;
				*maxvalue_node = getSubTree(*maxvalue_node, 'L');
				freeNode(&rm_node);
			}
			found = 1;
		}
	}
	return (found);
}

//--------------------------------------------------------------------------
//  最大値を保持するノード(最右端ノード)を探す
//  ［引　数］root : 最大値を探す木のルートを保持するポインタ
//  ［戻り値］最大値のノードを指すポインタを保持するポインタ
//            ただし、rootが空木のときはNULLポインタ
//--------------------------------------------------------------------------
Tree **maxValueNode(Tree **root) {
	if (isEmptyTree(*root)) {
		return (NULL);
	} else if (!isEmptyTree(getSubTree(*root, 'R'))) {
		return (maxValueNode(getSubTreeRoot(*root, 'R')));
	} else {
		return (root);
	}
}
