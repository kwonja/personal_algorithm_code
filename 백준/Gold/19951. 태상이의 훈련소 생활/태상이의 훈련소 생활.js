const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let [n, m] = input[0].trim().split(" ").map(Number);

let round = input[1].trim().split(" ").map(Number);


let temp = new Array(n+1).fill(0);

// O(m)
for(let i=0;i<m;i++)
{
    let [a,b,k]=input[i+2].trim().split(" ").map(Number);
    temp[a]+=k;
    if(b+1 <= n)temp[b+1]-=k;
}

for(let i=2;i<=n;i++)
{
    temp[i]+=temp[i-1];
}
for(let i=1;i<=n;i++)
{
    round[i-1]+=temp[i];
}
console.log(round.join(" "));