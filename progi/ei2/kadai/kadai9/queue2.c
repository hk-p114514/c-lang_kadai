#include "queue.h"
#include <stdio.h>

/* initQueue()
    概要:キューを初期化し、からの状態にする
*/
// 第1引数: 初期化するキュー
// 返り値  : なし
void initQueue(Queue *q) {
	q->head = QUEUE_SIZE - 1;
	q->tail = QUEUE_SIZE - 1;

	return;
}

/* enQueue()
    概要:キューにデータを格納する
*/
// 第1引数: データの格納対象になるキュー
// 返り値  : 正常終了：1、キューが満杯：0
int enQueue(Queue *q, int data) {
	if (q->head == (q->tail + 1) % QUEUE_SIZE) {
		// キューが満杯の時は1を返す
		return (0);
	} else {
		q->tail++;
		q->tail %= QUEUE_SIZE;
		q->storage[ q->tail ] = data;
		return (1);
	}
}

/* deQueue()
    概要:キューからデータを取り出す
*/
// 第1引数: データの取り出し対象になるキュー
// 第2引数: キューから取り出したデータ
// 返り値  : 正常終了：1、キューが空：0
int deQueue(Queue *q, int *data) {
	if (q->head == q->tail) {
		return (0);
	} else {
		q->head++;
		q->head %= QUEUE_SIZE;
		*data = q->storage[ q->head ];
		return (1);
	}
}
