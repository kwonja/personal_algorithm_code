function solution(fees, records) {
    var answer = [];
    let lists=[];
    let carType = new Map();
    for(let i=0;i<records.length;i++)
    {
        let temp = records[i].split(" ");
        //차량이 있을때는 출차를 진행
        if(carType.has(temp[1]))
        {
           
            let time = calculateMinute(carType.get(temp[1]),temp[0]);
            
            //차량번호가 있다면?
            let index= checkList(lists,temp[1]);
            if(index !== false)
            {
                lists[index].time += time;
            }
            carType.delete(temp[1]);
        }
        //차량이 없을때
        else{
            carType.set(temp[1], temp[0]);
            //차량 등록
            if(checkList(lists,temp[1]) ===false)lists.push({number : temp[1], time : 0});
        }
    }
    
    //리스트에 차량이 없을순 없다
    carType.forEach( (key,value)=>{
        let time = calculateMinute(key,"23:59");
        let index = checkList(lists,value);
        if(index !== false)
        {
            lists[index].time += time;
        }
        //차량번호가 없다면?
        else{
            lists.push({number : value, time : time});
        }
         
    })
    
    //정렬
    lists.sort((a, b) => {
        return parseInt(a.number) - parseInt(b.number); // 숫자로 변환 후 비교
    });
    console.log(lists);
    for(let i=0;i<lists.length;i++)
    {
        if(lists[i].time - fees[0] <= 0) answer.push(fees[1]);
        else answer.push(fees[1] + Math.ceil((lists[i].time-fees[0])/fees[2]) * fees[3] ) 
    }
    
    return answer;
}


//문자열 다섯개
function calculateMinute(start, end){
    let startMinute = (Number(start[0])*10 + Number(start[1]))*60 + Number(start[3])*10 + Number(start[4]);
    let endMinute =  (Number(end[0])*10 + Number(end[1]))*60 + Number(end[3])*10 + Number(end[4]);
    return endMinute - startMinute;
}

function checkList(lists,number){
    for(let i=0;i<lists.length;i++)
    {
       if(lists[i].number === number) return i;
    }
    return false;
}