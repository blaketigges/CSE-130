#include <stdio.h>

void input(float e, float f);
void add(float c, float d);

int main() {
	float a = 0;
	float b = 0;
	add(a, b);
}
void add(float& c, float& d); {
	input(c, d);
	print("%f + %f", c, d);
}
void input(float& e, float& f);{
	printf("Enter first number: ");		scanf("%f", &e);
	printf("Enter second number: ");	scanf("%f", &f);
}
