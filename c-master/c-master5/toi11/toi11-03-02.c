#include <stdio.h>

// #define 名前　値 の後にはセミコロンはつけない
#define SIZE 10
#define FUDGE SIZE - 2

int main() {
	int size; //  実際に用いるサイズ

	// size に代入したいのは、10 - 2であり、「10; -2;」ではない
	size = FUDGE;
	// size = 10 - 2;は8になるが
	/* size = 10; -2;はsizeには10が格納され、その後の-2;は、式の結果が未使用
	という、警告としてのみ現れ、エラーとして認識されない。 */

	printf("サイズは %d\n", size);

	return (0);
}
