function solution(s) {
    let answer="";
    let arr = s.split(' ');
    arr= arr.map( (str)=>Number(str));
    
    arr.sort(function(a,b){
        return a-b;
    });
    console.log(arr);
    answer= arr[0] + " "+ arr[arr.length-1];
    
    return answer;
}