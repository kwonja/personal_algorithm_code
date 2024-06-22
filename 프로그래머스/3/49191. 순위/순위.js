function solution(n, results) {
    let graph = new Array(n+1);
    for(let i=1;i<=n;i++)
    {
        graph[i]=new Array(n+1).fill(null);        
        graph[i][i]=0;
    }
    
    for(let [a,b] of results){
        graph[a][b]=1;
        graph[b][a]=-1;
    }
    
    
    //판정에 기준이 될 선수를 선택
    for(let k=1;k<=n;k++)
    {
        //비교 a
        for(let i=1;i<=n;i++)
        {
            //비교 b
            for(let j=1;j<=n;j++)
            {
                if(graph[i][k] === 1 && graph[k][j]===1)
                 {
                     graph[i][j]= 1;
                     graph[j][i]= -1;
                 }   
            }
        }
    }
    let answer=0;
    for(let i=1;i<=n;i++)
    {
        let arr = graph[i].filter((a) => a === null );
        if(arr.length ===1) answer++
    }
    return answer;
}