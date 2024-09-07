const fs = require('fs');
const input  = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let n = Number(input[0].trim());
//내구도, 무게

let arr =[];

for(let i=0;i<n; i++){
    let [hp,w] = input[i+1].trim().split(" ").map(Number);
    arr[i] = {hp ,w};
}
let ans=-1;

dfs(0,arr);
console.log(ans);
function dfs(pick,arr){

    if(pick === n){
        let cnt=0;
        for(let i=0;i<n;i++){
            if(arr[i].hp<=0)cnt++;
        }
        ans = Math.max(ans,cnt);
        return;
    }
    // 내가 든 계란이 깨지지 않고, 칠수 있는 계란이 존재할때 깨기를 진행
    if(arr[pick].hp <= 0) {
        dfs(pick+1,arr);
        return;
    }

    let allbreak=true;
    for(let i=0;i<n;i++){
        //깨지지 않았거나 내가 든 계란이 아닐때
        if(arr[i].hp > 0 && (i !== pick)){
            //계란깨기
            allbreak=false;
            arr[pick].hp-=arr[i].w;
            arr[i].hp-=arr[pick].w;

            dfs(pick+1,arr);
            
            arr[pick].hp+=arr[i].w;
            arr[i].hp+=arr[pick].w;


        }
    }
    if(allbreak){
        dfs(pick +1, arr);
        return;   
    }
}