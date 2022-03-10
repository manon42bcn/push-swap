#include <stdio.h>
#include <unistd.h>

int main()
{
	 printf("stdin->_flags = %hd\n", stdin->_flags);
    printf("STDIN_FILENO  : %d\n", STDIN_FILENO);
    write(stderr, "hola\n", 5);
	return 0;
}