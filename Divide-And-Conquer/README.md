## 분할 정복 

### ● 분할 정복 알고리즘
 그대로 해결할 수 없는 문제를 __작은 문제로 분할__ 하여 문제를 해결하는 방법이나 알고리즘이다. 
__빠른 정렬__ 이나 __합병 정렬__ 로 대표되는 정렬 알고리즘 문제와 __고속 푸리에 변환(FFT)__ 문제가 대표적이다.

### ● 설계

__분할__: 문제를 더이상 분할할 수 없을 때까지 동일한 유형의 여러 하위 문제로 나눈다.   
__정복__: 가장 작은 단위의 하위 문제를 해결하여 정복한다.   
__조합__: 하위 문제에 대한 결과를 원래 문제에 대한 결과로 조합한다.   

### ● 구현
__분할 정복 알고리즘__ 은 보통 __재귀 함수__(recursive function)를 통해 자연스럽게 구현된다.   
빠른 실행이나 부문제 해결 순서 선택을 위해, 재귀호출을 사용하지 않고 스택, 큐(queue) 등의 자료구조를 이용하여 분할 정복법을 구현하는 것도 가능하다.

### ● 장점
__문제를 나눔__ 으로써 __어려운 문제를 해결__ 할 수 있다는 장점이 있다. 그리고 이 방식이 그대로 사용되는 효율적인 알고리즘들도 여럿 있으며, 문제를 나누어 해결한다는 특징상 병렬적으로 문제를 해결하는 데 큰 강점이 있다.

### ● 단점 
함수를 재귀적으로 호출한다는 점에서 함수 호출로 인한 __오버헤드가 발생__ 하며, 스택에 다양한 데이터를 보관하고 있어야 하므로 __스택 오버플로우가 발생__ 하거나 __과도한 메모리 사용__ 을 하게 되는 __단점__ 이 있다. 
가장 중요한 것은 이 알고리즘의 핵심인 "F(x)가 간단"이 어떤 것이냐에 따라 알고리즘의 퍼포먼스가 생각보다 꽤 차이나게 된다는 것이다. 이 "F(x)가 간단하다"라는 것을 정의하는 것의 난해함 역시 단점 중에서 중요하게 다루어지고 있다.
