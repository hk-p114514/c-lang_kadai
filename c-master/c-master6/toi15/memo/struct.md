# 構造体の書き方

## 毎回structを書く
`
struct {
`

`
	double x;
`

`
	double y;
`

`
} p = {2, 3}, q = {4, 1};
`
* ^^^毎回struct{}を書く必要がある

## 名前を付ける
`
struct point {...};
`

`
struct point p = {1, 2};
`
* 毎回 struct タグ名 変数名を書く必要がある

## 型名を付ける
`
typedef struct {
	...
} Point
`

`
Point p = {2, 3};
`

* つけた型名を書けばいい