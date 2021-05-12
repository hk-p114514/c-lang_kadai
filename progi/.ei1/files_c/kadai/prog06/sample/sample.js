'use strict';

let i, n, j;

n = 1000000000;
console.log(2);

for (i = 0; i <= n; i ++) {
    j = 3;
    while(j < i && i % j !== 0) {
        j += 2;
    }
    if (i === j) {
        console.log(i);
    }
}