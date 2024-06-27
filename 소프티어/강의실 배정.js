const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split("\n");

let arr =[];
let n= +input[0].trim();
for(let i=1;i<=n;i++)
{
  let [x,y] = input[i].trim().split(" ").map(Number);
  arr.push({x,y});  
}

arr.sort((a, b) => {
  if (a.y === b.y) return a.x - b.x;
  return a.y - b.y;
});
let cnt=1;
let end=arr[0].y;
for(let i=1;i<arr.length;i++)
{
    if(end<=arr[i].x)
    {
       cnt++;
       end= arr[i].y
    }
}
console.log(cnt);