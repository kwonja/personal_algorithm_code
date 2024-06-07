function solution(progresses, speeds) {
    let answer=[0];
    let days = progresses.map( (progress,index)=>{
        return Math.ceil( (100-progress)/speeds[index]);   
    })
    let maxDay=days[0];
    for(let i=0, j=0; i<progresses.length; i++)
    {
        if(days[i]<=maxDay)
        {
           answer[j]++;
        }
        else
        {
            answer[++j]=1;
            maxDay=days[i];
        }
    }
    return answer;
}