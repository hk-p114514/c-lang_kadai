all:
	gcc -c -shared -fPIC -o libhash.so hash.c

a:
	gcc -c -shared -fPIC -o libhash.so hash.c && gcc -D TBL_SIZE=1009 prog37-main.c -L . -l hash

b:
	gcc -c -shared -fPIC -o libhash.so hash.c && gcc -D TBL_SIZE=2003 prog37-main.c -L . -l hash

c:
	gcc -c -shared -fPIC -o libhash.so hash.c && gcc -D TBL_SIZE=6007 prog37-main.c -L . -l hash

d:
	gcc -c -shared -fPIC -o libhash.so hash.c && gcc -D MY_HASH prog37-main.c -L . -l hash