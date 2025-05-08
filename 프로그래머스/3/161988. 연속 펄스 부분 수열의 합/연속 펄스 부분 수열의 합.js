function solution(sequence) {
    // 50만이기때문에 이중포문을 쓰거나 하면 무조건 통과하지 못한다.
    // 힌트 : 연속 부분 수열의 합 -> 이전값들이 현재값보다 작다면? -> 굳이 더할 필요가 없음, 최대값을 가지는 연속수열을 다시 시작하는게 맞다..!
    
    
    //대신 펄스는 바뀌기 때문에 2가지 경우를 확인해줘야함!
    
    let maxPurse1 = -Infinity;
    let maxPurse2 = -Infinity;
    
    
    let sum1=0;
    let sum2=0;
    for(let i=0;i<sequence.length;i++)
        {
            let purse1= i % 2 === 0 ? 1:-1;
            let purse2= i % 2 === 0 ? -1:1;
            
            sum1 = Math.max(sequence[i] * purse1 , sum1 + sequence[i] * purse1);
            sum2 = Math.max(sequence[i] * purse2 , sum2 + sequence[i] * purse2);
        
            maxPurse1 = Math.max(maxPurse1,sum1);
            maxPurse2 = Math.max(maxPurse2,sum2);
        }
    
    return Math.max(maxPurse1,maxPurse2);
}


