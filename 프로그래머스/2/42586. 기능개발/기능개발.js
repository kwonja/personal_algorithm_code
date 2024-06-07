function solution(progresses, speeds) {
    let answer = [];
    console.log(progresses);
    
    
    while(progresses.length>0)
    {
        let popcount=0;
        for(let i=0;i<progresses.length;i++)
        {
            progresses[i]+=speeds[i];
        }
       
        while(progresses[0]>=100)
        {
             progresses.shift();
             speeds.shift();
             popcount++;
        }
        if(popcount>0)
        {
            answer.push(popcount);
        }
    }
    return answer;
}