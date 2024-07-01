const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let [n, k] = input[0].trim().split(" ").map(Number);
let item=[];
for(let i=0;i<n;i++){
    let [weight, value] = input[i+1].trim().split(" ").map(Number);
    item.push({weight, value});
}
let arr = new Array(n+1);
for(let i=0;i<=n;i++){
    arr[i] = new Array(k+1).fill(0);
}

//해당 풀이가 가능한 이유는 1번물품,2번물품을 지나면서 가방에 들어갈수 있는 최대 가치를 따지기때문에
//마지막 물품을 평가했을때 가장 가치가 높게 계산된다.
for(let i=1;i<=n;i++){
    for(let j=0;j<=k;j++){

        if(item[i-1].weight > j){
            arr[i][j]=arr[i-1][j];
            continue;
        }

        //배낭에 아이템을 넣을 수 있다면
        //j만큼 무게를 넣었을때 j-item[i-1].weight만큼 넣었던 배낭이 있으면 더해준다.
        arr[i][j]= arr[i-1][j-item[i-1].weight]+item[i-1].value;

        //j만큼 무게를 넣은 가방에서 이전 조합이 더 가치가 클수 있다.
        arr[i][j]= Math.max(arr[i][j],arr[i-1][j]);
    }
}
console.log(Math.max(...arr[n]));