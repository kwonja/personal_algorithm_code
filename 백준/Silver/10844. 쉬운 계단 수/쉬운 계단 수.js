const fs = require('fs');

const n = +fs.readFileSync('/dev/stdin').toString().trim();

let arr =[];

arr = new Array(10);

for(let i=0;i<10;i++)
{
    arr[i]= new Array(n).fill(0)
    arr[i][0]=1;
}

for(let i=1;i<n;i++)
{
    for(j=0;j<10;j++)
    {
        if(j==0) arr[j][i]=arr[j+1][i-1];
        else if(j==9) arr[j][i]= arr[j-1][i-1];
        else arr[j][i] = (arr[j-1][i-1] + arr[j+1][i-1])%1000000000;
    }

}
let ans=0;
for(let i=1;i<10;i++)
    {
        ans += arr[i][n-1];
        ans %= 1000000000;
    }
console.log(ans);