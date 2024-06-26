# [Gold V] 태상이의 훈련소 생활 - 19951 

[문제 링크](https://www.acmicpc.net/problem/19951) 

### 성능 요약

메모리: 45040 KB, 시간: 384 ms

### 분류

누적 합

### 제출 일자

2024년 6월 30일 19:42:33

### 문제 설명

<p>2020년 5월 14일 논산훈련소에 입대한 태상이는 첫 총기 훈련에서 가스 조절기를 잃어버리는 중대한 실수를 범했다. 그로 인해, 태상이는 조교들에게 눈총을 받게 되었다. 조교들은 태상이에게 연병장(운동장)의 흙을 옮기는 일을 주고 제대로 수행하지 못하면 징계를 내리려고 한다.</p>

<p>연병장은 일렬로 이어진 <em>N</em>개의 칸으로 이루어져 있으며 각 칸마다 높이를 가지고 있고, 첫 번째 칸부터 순서대로 1번, 2번, 3번, ..., <em>N</em>번 칸으로 명칭이 붙어있다. 조교들은 총 <em>M</em>명이 있으며, 각 조교들은 태상이에게 <em>a</em>번 칸부터 <em>b</em>번 칸까지 높이 <em>k</em>만큼 흙을 덮거나 파내라고 지시한다. 흙은 주변 산에서 얼마든지 구할 수 있으므로 절대로 부족하지 않다.</p>

<p>태상이는 각 조교의 지시를 각각 수행하면, 다른 조교의 지시로 흙을 덮어둔 칸을 다시 파내기도 하는 비효율적인 일이 발생하는 것을 깨달았다. 그래서 태상이는 각 조교의 지시를 모아 연병장 각 칸의 최종 높이를 미리 구해 한 번에 일을 수행하려고 한다.</p>

<p>불쌍한 태상이를 위해 조교들의 지시를 모두 수행한 뒤 연병장 각 칸의 높이를 구하자.</p>

### 입력 

 <p>첫 줄에 연병장의 크기 <em>N</em>과 조교의 수 <em>M</em>이 주어진다.</p>

<p>둘째 줄에 연병장 각 칸의 높이 <em>H<sub>i</sub></em>가 순서대로 <em>N</em>개 주어진다.</p>

<p>셋째 줄부터 <em>M</em>개의 줄에 각 조교의 지시가 주어진다.</p>

<p>각 조교의 지시는 세 개의 정수 <em>a</em>, <em>b</em>, <em>k</em>로 이루어져 있다.</p>

<ul>
	<li><em>k </em>≥ 0인 경우 <em>a</em>번 칸부터 <em>b</em>번 칸까지 높이가 각각 |<em>k</em>| 만큼 늘어나도록 흙을 덮어야 한다.</li>
	<li><em>k</em> < 0인 경우 <em>a</em>번 칸부터 <em>b</em>번 칸까지 높이가 각각 |<em>k</em>| 만큼 줄어들도록 흙을 파내야 한다.</li>
</ul>

### 출력 

 <p>모든 지시를 수행한 뒤 연병장 각 칸의 높이를 공백을 사이에 두고 출력한다.</p>

## 영역에 대해서 누적합을 이용해 풀수 있다.
(0000회사)에서 영역에 대한 누적합 문제가 나왔다... 이걸 나오고 풀어보네..

아래 풀이는 특정 블로그의 글이 가져왔다.

출처: https://yabmoons.tistory.com/729 [얍문's Coding World..:티스토리]

# 2. 누적합을 이용한 방법
그래서 이 문제를 "누적합" 을 이용한 방법으로 해결해 볼 것이다.
아까와 똑같은 배열을 다시한번 가져와보자.

[ 1 , 2 , 3 , 4 , 5 ]
이 때, "1번 칸부터 3번칸까지 + 2 만큼 하세요" 라고 한다면, 저 배열에서 바로 계산을 하는게 아니라, 새로운 배열에서 계산을 해줄 것이다. 그러기 위해서 먼저 모든 값이 0으로 초기화 되어 있는 새로운 배열을 하나 선언해보자.

[ 0 , 0 , 0 , 0 , 0 ]
그리고 "1번 칸부터 3번칸까지 + 2 만큼 하세요" 라는 명령을 수행하기 위해서 다음과 같이 연산을 진행해줄 것이다.

[ 2 , 0 , 0 , -2 , 0 ] 
1번 칸에는 + 2를, 4번 칸에는 -2를 시켜준 것이다. 왜 갑자기 이런 계산을 했을까 ???

그 전에, 위의 상태에서 이 배열에서 앞에서부터의 누적값을 한번 구해보자. 구해보면 다음과 같을 것이다.

[ 2 , 2 , 2 , 0 , 0 ]
첫 번째 칸 = 이전의 칸이 없으므로 '2' 그대로 유지.

두 번째 칸 = 이전 칸 까지의 총합이 '2'였고, 두 번째 칸의 값이 '0'이였으므로 2 + 0 = '2'

세 번째 칸 = 이전 칸 까지의 총합이 '2'였고, 세 번째 칸의 값이 
'0'이였으므로 2 + 0 = '2'

네 번째 칸 = 이전 칸 까지의 총합이 '2'였고, 네 번째 칸의 값이 '-2' 였으므로 2 + (-2) = '0'

다섯번째 칸 = 이전 칸 까지의 총합이 '0' 이였고, 다섯 번째 칸의 값이 '0'이였으므로 '0'.

위와 같이 계산이 되는 것이다.  그리고 원본의 배열인 [ 1 , 2 , 3 , 4 , 5 ] 와 [ 2 , 2 , 2 , 0 , 0 ]을 더하게 되면
[ 3 , 4 , 5 , 4 , 5 ] 와 같이 우리가 원했던 1번칸 ~ 3번칸만 +2가 된 결과를 얻을 수가 있다.


즉 ! "A번째 칸 부터 B번째 칸 까지 +a를 하세요" 라고 한다면, 우리는 새로운 배열에서  "A번째 칸에 +a를, B + 1번째 칸에 -a"를 한 후에, 이 배열에서의 누적합을 구하고, 원본 배열과 합쳐주기만 한다면 우리가 원하는 결과를 구할 수가 있다.

이렇게 값을 변경해야 하는 경우가 여러 번 있더라도 여러 번에 대해서 모두 계산해 준 후에, 최종적으로 누적합을 구한 후, 원본 배열과 합쳐주기만 하면 된다.

이렇게 계산을 하게 되면, 몇 개의 명령어가 몇 개의 범위에 대해서 주어지더라도, A 번째 칸에 +a, B + 1 번째 칸에 -a를 하고 이를 누적합을 구하기 위해서 더하기 위해서 N번 탐색, 그리고 원본 배열과 합치기 위해서 N번 탐색 만으로 해결할 수가 있다.
