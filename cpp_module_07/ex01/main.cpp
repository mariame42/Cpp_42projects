#include "iter.hpp"

int main(void)
{
	int i[3];
	i[0] = 1;
	i[1] = 2;
	i[2] = 3;
	iter(i, 3, function);

	char str[8] = "loooool";
	iter(str, strlen(str), function);

	return 0;
}
