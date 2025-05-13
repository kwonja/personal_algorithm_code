// /dev/stdin

/**
 * 실버 3
 * 서로 다른 부분 문자열의 개수
 * 해시
 */

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

//set
//map

let set = new Set();

for (let i = 1; i <= input.length; i++) {
  for (let j = 0; j < input.length; j++) {
    let str = input.slice(j, j + i);
    if (set.has(str)) {
      continue;
    } else {
      set.add(str);
    }
  }
}

console.log(set.size);
