const fs = require('fs');
const n = +fs.readFileSync('/dev/stdin').toString().trim();
let arr = new Array(10);

for (let i = 0; i <10; i++) {
    arr[i]= new Array(n).fill(0);
}

//초기 n===1일때
arr[9][0]=1;
for(let i=8;i>=0;i--)
{
    arr[i][0]=arr[i+1][0]+1;
}
for(let i=1;i<n;i++)
{
    arr[9][i]=1;
    for(let j=8;j>=0;j--){
        arr[j][i]= (arr[j+1][i]+arr[j][i-1]) % 10007;
    }
}
console.log(arr[0][n-1]);