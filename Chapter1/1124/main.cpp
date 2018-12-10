#include <stdio.h>

int main()
{
	char c;
	while ((c = (char) getchar()) != EOF)
	{
		printf("%c", c);
	}
}