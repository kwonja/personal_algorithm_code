const fs = require('fs');
let n = +fs.readFileSync('/dev/stdin').toString().trim();
let arr = new Array(n+1).fill(0);
if(n>=1){
    arr[1]=1;
}
if(n>=2){
    arr[2]=2;
}
for(let i=3; i<=n; i++){
    arr[i]=(arr[i-1]+arr[i-2])% 15746;
}
console.log(arr[n]);