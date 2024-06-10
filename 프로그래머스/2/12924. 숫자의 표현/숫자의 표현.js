function solution(n) {
    let answer=0;
    
    for(let i=1; i<=n/2;i++)
    {
        let num=i;
        let temp=n;
        while(temp > 0)
        {
            temp -=num++;
            if(!temp) answer++;
        }
    }
    return answer+1;
}


// 1 2 3 4 5 6
// 2 3 4 5 6
// 3 4 5 6
// 4 5 6
// 5 6
// 6