//k에 따라서 정렬을 계속하면 시간이 너무 길어짐
// enemy길이를 이분탐색으로 라운드를 세면  logn의 시간으로 짧게 구할수 있다.
function solution(n, k, enemy) {
    
    let left=0, right = enemy.length;
    
    while(left <= right)
    {
        let mid = Math.floor((left + right)/2);
        //mid 라운드가 최대인지 판별해야함
        if(check(n,k,mid,enemy))
        {
              left=mid+1;      
        }
        else right= mid-1;
        
    }
    
    return left-1;
}

function check(n,k,mid,enemy)
{
    let e = enemy.slice(0,mid).sort( (a,b)=> b-a)
    let sum=0;
    for(let i=k;i<e.length;i++)
    {
        sum +=e[i];
        if(sum > n) return false;
    }
    return true;
}