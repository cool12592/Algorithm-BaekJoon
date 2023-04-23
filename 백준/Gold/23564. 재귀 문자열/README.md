# [Gold II] 재귀 문자열 - 23564 

[문제 링크](https://www.acmicpc.net/problem/23564) 

### 성능 요약

메모리: 8036 KB, 시간: 16 ms

### 분류

애드 혹, 구성적, 문자열

### 문제 설명

<p>길이가 $n$인 문자열 $S=s_1s_2\cdots s_n$와 길이가 $n$인 양의 정수 수열 $A=(a_1, a_2, \cdots a_n)$를 이용하여 다음과 같이 새로운 문자열 $T$를 만들 수 있다.</p>

<ul>
	<li>$X_0$는 빈 문자열이다.</li>
	<li>$X_i = X_{i-1} s_i X_{i-1} s_i \cdots s_i X_{i-1}$, $s_i$는 $a_i$번, $X_{i-1}$은 $a_i + 1$번 등장한다.</li>
	<li>$T = X_n$이다.</li>
</ul>

<p>예를 들어 $S=abc$고, $A=(1,2,1)$이면 $X_1=a, X_2=ababa, X_3=T=ababacababa$가 된다.</p>

<p style="text-align: center;"><img alt="" src="" style="height: 214px; width: 400px;"></p>

<p>$S$와 $A$를 이용하여 $T$를 만드는 것은 쉬우니, 반대로 $T$가 주어졌을 때 $T$를 만들어내는 $S$와 $A$를 찾아보자.</p>

### 입력 

 <p>문자열 $T$가 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 $S$를 출력한다.</p>

<p>두 번째 줄에 $A$를 공백으로 구분하여 출력한다.</p>

<p>정답이 여러 개인 경우 아무 거나 한 가지만 출력한다.</p>

