'use strict';

let n = 2;
let temp = n;
let N = n;
n = Math.pow(n, 3);

for (let i = 3 - 1; i > 0; i --) {
    console.log(N);
    N *= temp;
}

    console.log(N);
// console.log(`n = ${n}`);
// console.log(`N = ${N}`);