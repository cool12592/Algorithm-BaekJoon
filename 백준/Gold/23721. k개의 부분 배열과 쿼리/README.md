# [Gold II] k개의 부분 배열과 쿼리 - 23721 

[문제 링크](https://www.acmicpc.net/problem/23721) 

### 성능 요약

메모리: 4372 KB, 시간: 112 ms

### 분류

애드 혹, 누적 합

### 문제 설명

<p>nlog는 다음과 같은 <a href="https://www.acmicpc.net/problem/22965">문제</a>를 만들었다.</p>

<blockquote>
<p>$N$개의 서로 다른 정수를 가진 배열 $A$가 주어진다. 당신은 공격력이 양의 정수 $k$인 칼을 받았다. 이 칼이 있으면 배열에 아래와 같은 연산을 적용할 수 있다.</p>

<ol>
	<li>배열을 $k$개의 조각으로 자른다.</li>
	<li>$k$개의 조각을 원하는 순서대로 재배열한다.</li>
	<li>재배열한 순서대로 조각들을 다시 합친다.</li>
</ol>

<p>당신은 배열 $A$에 이 연산을 원하는 횟수만큼 적용하여 (한 번도 적용하지 않아도 괜찮다) 오름차순으로 정렬하려고 한다. $k$의 값에 따라 이 연산을 적절히 적용하면 $A$를 정렬하는 것이 가능할 수도 있고, 연산을 어떻게 잘 적용해도 정렬할 수 있는 방법이 없을 수도 있다. 이 때, 배열 $A$를 정렬할 수 있는 가장 작은 양의 정수 $k$의 값을 구하는 프로그램을 작성하자.</p>
</blockquote>

<p>하지만, 문제가 너무 쉬워 보여 질의를 주기로 했다.</p>

<p>$l, r$이 주어지면 $A_l, A_{l + 1}, \cdots , A_r$로 구성된 연속 부분 배열에서 문제의 정답을 출력하자.</p>

### 입력 

 <p>첫째 줄에 배열의 길이 $N$이 주어진다.</p>

<p>둘째 줄에 $N$개의 정수 $A_1, A_2, \cdots , A_n$이 공백으로 구분되어 주어진다.</p>

<p>셋째 줄에 질의의 개수 $Q$가 주어진다.</p>

<p>넷째 줄부터 $Q$개의 줄에 질의의 정보 $l$과 $r$이 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>각 질의마다 주어진 수열을 오름차순으로 만들 수 있는 가장 작은 양의 정수 $k$의 값을 출력한다.</p>

