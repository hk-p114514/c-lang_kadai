"use strict";

const rand = (min, max) => {
  return (Math.floor(Math.random() * (max - min + 1)) + min);
};

const name = "aaaaabbbbbcccccdddddaaaaabbbbbcccccddddd";
const n = 100;

console.log(n);

for (let i = 1; i <= n; i ++) {
  console.log(`${i} ${name} ${name} ${rand(0, 100)} ${rand(0, 100)} ${rand(0, 100)}`);
}
