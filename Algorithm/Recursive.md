# Recursive

## Fibonacci sequence

```C++
int f(int x) {
    if (x > 1) return f(x - 1) + f(x - 2);
    return x;
}
```

## Hanoi Tower

```C++
#include <iostream>
using namespace std;

void hanoi(int n, char start, char mid, char end) {
	if (n == 1) {
		cout << start << " -> " << end << endl;
		return;
	}
	hanoi(n - 1, start, end, mid);
	cout << start << " -> " << end << endl;
	hanoi(n - 1, mid, start, end);
}

int main()
{
	cout << "Enter disk value: " << endl;
	int n; cin >> n;
	hanoi(n, 'a', 'b', 'c');

	return 0;
}
```

output

```
Enter disk value:
3
a -> c
a -> b
c -> b
a -> c
b -> a
b -> c
a -> c
```

