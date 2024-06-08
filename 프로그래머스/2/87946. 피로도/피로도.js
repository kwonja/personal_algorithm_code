let answer=-1;

function solution(k, dungeons) {
    
    
    dfs(k,0,dungeons,new Array(dungeons.length).fill(false),0);
    
    return answer;
}

function dfs(k,idx,dungeons,visited,cnt)
{
    //만약 모든 던전을 스캔했다면
    if(idx===dungeons.length)
    {
        
        answer=Math.max(cnt,answer);
        return;
    }
    //피로도가 다 떨어지면
    for(let i=0;i<dungeons.length;i++)
    {
        //방문했거나, 최소로 피로도를 만족한다면 입장
        if(!visited[i] && k>=dungeons[i][0])
        {
            visited[i]=true;
            dfs(k-dungeons[i][1],idx+1,dungeons,visited,cnt+1);
            visited[i]=false;
        }
        //방문하지 못하는 던전이면
        else
        {
            dfs(k,idx+1,dungeons,visited,cnt);        
        }
    }
    
}