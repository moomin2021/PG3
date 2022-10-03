#include <stdio.h>
#include <stdlib.h>

template <typename Type>

Type Min(Type a, Type b) {
	if (a < b) {
		return a;
	}

	return b;
}

template <>
char Min(char a, char b) {
	printf("”š‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ\n");
	return 0;
}

int main() {
	printf("%d\n", Min<int>(10, 5));
	printf("%f\n", Min<float>(7.5f, 5.5f));
	printf("%lf\n", Min<double>(11.1, 2.3));
	printf("%c\n", Min<char>('a', 'b'));
	return 0;
}