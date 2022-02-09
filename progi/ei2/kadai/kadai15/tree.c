#include "tree.h"
// #include <hamakou.h>
#include <stdio.h>
#include <stdlib.h>

void printTreeSub(Tree *root, int depth);

//-------------------------------------------------------------------------------
// ① 空木を取得する
//  ［引　数］なし
//  ［戻り値］空木へのポインタ(Tree *)NULL
//-------------------------------------------------------------------------------
Tree *getEmptyTree(void) {
	return ((Tree *)NULL);
}

//-------------------------------------------------------------------------------
// ② 新しいノードを１つ作る
//  ［引　数］data  : 作ったノードに格納する整数値
//  ［戻り値］ノードが正しく作れたとき　：　作られたノードへのポインタ
//  　　　　　ノードの生成に失敗したとき：　空木
//-------------------------------------------------------------------------------
Node *createNode(int data) {
	Node *node;
	if ((node = (Node *)malloc(sizeof(Node))) != NULL) {
		// 生成したノードに渡されたデータを格納
		setNodeData(node, data);
		// 左右の部分木に空木へのポインタを格納
		setSubTree(node, getEmptyTree(), 'L');
		setSubTree(node, getEmptyTree(), 'R');
		return (node);
	}

	return (getEmptyTree());
}

//-------------------------------------------------------------------------------
// ③ 指定したノードにデータを格納する（既存のデータを更新する）
//  ［引　数］node : 操作対象となるノードへのポインタ
//            data : ノードへ格納する整数値
//  ［戻り値］なし
//-------------------------------------------------------------------------------
void setNodeData(Node *node, int data) {
	node->data = data;
	return;
}

//-------------------------------------------------------------------------------
// ④ 指定したノードのデータを取り出す
//  ［引　数］node : 操作対象となるノードへのポインタ
//  ［戻り値］取り出した整数値
//-------------------------------------------------------------------------------
int getNodeData(Node *node) {
	return (node->data);
}

//-------------------------------------------------------------------------------
// ⑤ 指定したノードの左または右部分木に新たな部分木を格納する
//  ［引　数］cell    : 操作対象となるノードへのポインタ
//            subtree : 格納する部分木のポインタ
//            target  : 部分木の格納位置を指定する文字
//  ［戻り値］なし
//  ［機　能］targetが 'L' または 'l' のとき：subtreeを左部分木に格納する
//   　　　　 targetが 'R' または 'r' のとき：subtreeを右部分木に格納する
//   　　　　 targetが 'L','l','R','r' 以外のときは何もしない
//-------------------------------------------------------------------------------
void setSubTree(Node *node, Tree *subtree, char target) {
	switch (target) {
		// 右部分木を設定
		case 'R':
		case 'r':
			node->right = subtree;
			break;

		// 左部分木を設定
		case 'L':
		case 'l':
			node->left = subtree;
			break;
	}

	return;
}

//-------------------------------------------------------------------------------
// ⑥ 指定したノードにつながる部分木のポインタを取り出す
//  ［引　数］node  : 操作対象となるセルへのポインタ
//            target: 取り出したい部分木を指定する文字
//  ［戻り値］target = 'L' または 'l' のとき　　  : 左部分木を指すポインタ
//  　　　　　target = 'R' または 'r' のとき　　  : 左部分木を指すポインタ
//  　　　　　target = 'L','l','R','r' 以外のとき : NULLポインタ
//-------------------------------------------------------------------------------
Tree *getSubTree(Node *node, char target) {
	switch (target) {
		// 右部分木を返す
		case 'R':
		case 'r':
			return (node->right);
			break;

		// 左部分木を返す
		case 'L':
		case 'l':
			return (node->left);
			break;
	}

	return ((Tree *)NULL);
}
//-------------------------------------------------------------------------------
// ⑦ 指定したノードの左または右部分木を指すポインタを保持しているメンバ
//   変数のアドレスを取得する
//  ［引　数］node  : 操作対象となるノードへのポインタ
//            target: 取り出したい部分木を指定する文字
//  ［戻り値］target = 'L' または 'l' のとき
//  　　　　　　　　　 左部分木のポインタを保持するメンバ変数のアドレス
//  　　　　　target = 'R' または 'r' のとき
//  　　　　　　　　　 右部分木のポインタを保持するメンバ変数のアドレス
//  　　　　　target = 'L','l','R','r' 以外のときはNULLポインタを返す
//-------------------------------------------------------------------------------
Tree **getSubTreeRoot(Node *node, char target) {
	switch (target) {
		// 右部分木を返す
		case 'R':
		case 'r':
			return (&(node->right));
			break;

		// 左部分木を返す
		case 'L':
		case 'l':
			return (&(node->left));
			break;
	}

	return ((Tree **)NULL);
}

//-------------------------------------------------------------------------------
// ⑧ 与えられた木が空木かどうか調べる
//  ［関　数］int isEmptyTree(Tree *root);
//  ［引　数］root : 木の根を指すポインタ
//  ［戻り値］rootが空木のとき　　：１
//  　　　　　rootが空木でないとき：０
//-------------------------------------------------------------------------------
int isEmptyTree(Tree *root) {
	if (root == getEmptyTree()) {
		return (1);
	}

	return (0);
}

//-------------------------------------------------------------------------------
// ⑨ 指定したノードのメモリ領域を解放する
//  ［引　数］node：解放対象ノードへのポインタを格納している領域のアドレス
//  ［戻り値］空木でないノードを解放したとき：　１
//  　　　　　指定したノードが空木だったとき：　０
//  ［機　能］nodeで指定するノードのメモリ領域を解放する。メモリの解放後
//　　　　　　引数で渡されたnodeは空木にする。メモリを解放するのみで、
//　　　　　　枝のつなぎ替えは行わない。また、空木のときは何もしない。
//-------------------------------------------------------------------------------
int freeNode(Node **node) {
	if (isEmptyTree(*node) != 1) {
		// nodeを開放する
		free(*node);

		// nodeを空木にする
		*node = getEmptyTree();

		return (1);
	}
	return (0);
}

//-------------------------------------------------------------------------------
// ⑩ 指定した二分木のノードをすべて削除する
//  ［機　能］rootで指定した木のノードをすべて削除する
//-------------------------------------------------------------------------------
void rmTree(Tree **root) {
	/*
	    rootそのものが空で無い
	        rootの左の部分木が空で無い
	            左の部分木について同じ問いを調べる
	        rootの右の部分木が空で無い
	            右の部分木について同じ問いを調べる
	        rootの左右の部分木が空
	            終了
	*/
	if (isEmptyTree(*root) == 1) {
		return;
	}

	rmTree(getSubTreeRoot(*root, 'L'));
	rmTree(getSubTreeRoot(*root, 'R'));

	freeNode(root);
}

//-------------------------------------------------------------------------------
// ⑪ 与えられた二分木を表示する
//  ［関　数］void printTree(Tree *root);
//  ［引　数］root : 木の根を指すポインタ
//  ［戻り値］なし// 二分木の表示
//-------------------------------------------------------------------------------
void printTree(Tree *root) {
	printTreeSub(root, 0);
	return;
}

//-------------------------------------------------------------------------------
// 与えられた二分木を表示する（printTree()から呼び出すサブ関数）
//  ［関　　数］void printTree(Tree *root);
//  ［第１引数］root  : 木の根を指すポインタ
//  ［第２引数］depth : 表示対象部分木のレベル
//  ［戻 り 値］なし
//-------------------------------------------------------------------------------
void printTreeSub(Tree *root, int depth) {
	if (isEmptyTree(root) == 1) {
		return;
	}
	int i;

	printTreeSub(getSubTree(root, 'R'), depth + 1);
	for (i = 0; i < depth; i++) {
		printf("   ");
	}
	printf("%d\n", getNodeData(root));
	printTreeSub(getSubTree(root, 'L'), depth + 1);
	return;
}

//-------------------------------------------------------------------------------
// バランス木を生成する
//   [引　数］root：木の根を指すポインタを格納している領域のアドレス
//            n   ：ノードの総数
//  ［戻り値］木を正しく生成できたとき：　１
//            木の生成に失敗したとき　：　０
//  ［機　能］整数値を格納するｎ個のノードからなるバランス木を生成する。
//            各ノードに格納するデータは、ノードを作る際にキーボードより入力する
//            木の生成が途中で失敗したときは、そこで生成を中止する
//           （途中まで作られた木はそのまま残す）
//-------------------------------------------------------------------------------
int mkBalanceTree(Tree **root, int n) {
	/*
	    nが0
	        終了
	    データを受け取る
	    今見ているノードにデータを格納する
	    nが1
	        終了
	    n/2、rootの左部分木をmkBalanceTree()に渡す
	    n-(n/2)-1、右部分木をmkBalanceTree()に渡す
	 */
	if (n < 1) {
		/*
		 * n(ノードの個数)が0の場合、
		 * つまり、前回の再帰でノード1つの部分木(葉)を作成した場合、
		 * 木の生成に成功しているので、１を返す。
		 */
		*root = getEmptyTree();
		return (1);
	}

	int data;
	char buff[ 1024 ];
	printf("ノードへ格納する値: ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &data);

	// rootにノードを作成する
	*root = createNode(data);
	if (*root == getEmptyTree()) {
		return (0);
	}

	// 左部分木を作成する
	if (mkBalanceTree(getSubTreeRoot(*root, 'L'), n / 2) == 0) {
		return (0);
	}

	// 右部分木を作成する
	if (mkBalanceTree(getSubTreeRoot(*root, 'R'), n - (n / 2) - 1) == 0) {
		return (0);
	}

	return (1);
}
void printTree2(Tree *root) {
	printTreeSub(root, 0);
	return;
}

void incrementEqualValueCount(Tree *root) {
	root->count++;
}

void decrementEqualValueCount(Tree *root) {
	if (getEqualValueCount(root) > 0) {
		root->count--;
	}
}

int getEqualValueCount(Tree *root) {
	return (root->count);
}