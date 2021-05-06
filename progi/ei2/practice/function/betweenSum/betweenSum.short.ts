"use strict";

const betweenSum = (left: number, right: number): number => {
	return ((left + right) * (right - left + 1)) / 2;
};

console.log(betweenSum(1, 5));
