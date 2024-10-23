function solution(a) {

    //백만이상일때 Math.min은 에러를 발생시킴
    let t= [...a];
    t.sort( (a,b)=>a-b)
    
    let idx = a.indexOf(t[0]);
    
    let left = a.slice(0,idx);
    let right =a.slice(idx+1);
    
    let answer=0;
    
    
    let temp =1000000001;
    
    for(let i=0;i<left.length;i++)
    {
        if(temp>=left[i]){
            temp=left[i];
            answer++;
        }        
    }
    temp=1000000001;
    for(let i=right.length;i>=0; i--)
    {
          if(temp>=right[i]){
            temp=right[i];
            answer++;
        }  
    }
      
    //왼쪽 + 작은걸 안터트림(1) + 오른쪽
    return answer+1;
}


// 마지막에 작은 풍선을 터트림
// 그러면 왼쪽 ,오른쪽에 나올 수 있느ㅜㄴ것 -> 이때는 큰 풍선을 터트림
// 


