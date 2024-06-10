function solution(n) {
   let answer=0;
    
    for(let i=1; i<=n;i++)
    {
        let sum=0;
        for(let j=i;j<=n;j++)
        {
            sum+=j;
            if(sum===n)answer++;
            if(sum>n)break;
        }
    }
    return answer;
}


// 1 2 3 4 5 6
// 2 3 4 5 6
// 3 4 5 6
// 4 5 6
// 5 6
// 6