function solution(n, roads, sources, destination) {
    let answer = [];
    
    let graph = new Array(n+1);
    for(let i=1;i<n+1;i++)
    {
      graph[i]=[];
    }
    let distances = new Array(n + 1).fill(-1);
    //목적지부터 갈수 있는 곳을 탐색,
    distances[destination]=0;
    let queue = [destination];
    
    for(let [a,b] of roads)
    {
        graph[a].push(b);
        graph[b].push(a);
    }
    while(queue.length)
    {
        let current = queue.shift();
        for(let i=0;i<graph[current].length; i++)
        {
            if(distances[graph[current][i]] === -1)
            {
                queue.push(graph[current][i]);
                distances[graph[current][i]]=distances[current]+1;
            }
        }
    }
    answer= sources.map( (source) => distances[source]);
    
    return answer;
}