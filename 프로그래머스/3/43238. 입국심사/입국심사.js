function solution(n, times) {
    var answer = 0;
    let left=1;
    let right = Math.max(...times)*n;
    
    while(left<=right){
        let people=0;
        let mid = Math.floor((left+right)/2);
        for(let time of times)
        {
            people += Math.floor(mid/time); //mid라는 시간동안 검사할수 있는 사람 수
        }
        console.log(people + " 사람")
        console.log(mid + " 기준값")
        //people과 n이 같아도, 더 적은 시간으로 해결할수도 있음
        if(people >= n) //너무 많은 시간 할당
        {
          answer=mid;
          right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return answer;
}