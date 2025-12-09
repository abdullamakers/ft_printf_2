#include <stdio.h>
#include "include/ft_printf.h"

void divider(char *title)
{
	printf("\n==================== %s ====================\n", title);
}

int main(void)
{
	int r1, r2;

	divider("BASIC TESTS");
	r1 = ft_printf("ft : Hello %s %d %i %u %x %X %p %%\n",
		"Abdullah", -42, 42, 4242u, 255u, 255u, (void *)0x1234);
	r2 = printf("org: Hello %s %d %i %u %x %X %p %%\n",
		"Abdullah", -42, 42, 4242u, 255u, 255u, (void *)0x1234);
	printf("ret: ft=%d | org=%d\n", r1, r2);

	divider("WIDTH");
	ft_printf("ft : '%10d'\n", 42);
	printf("org: '%10d'\n", 42);

	ft_printf("ft : '%-10d'\n", 42);
	printf("org: '%-10d'\n", 42);

	ft_printf("ft : '%010d'\n", 42);
	printf("org: '%010d'\n", 42);

	divider("+ and SPACE FLAGS");
	ft_printf("ft : '%+d'\n", 42);
	printf("org: '%+d'\n", 42);

	ft_printf("ft : '% d'\n", 42);
	printf("org: '% d'\n", 42);

	divider("HASH FLAG");
	ft_printf("ft : '%#x'\n", 255);
	printf("org: '%#x'\n", 255);

	ft_printf("ft : '%#X'\n", 255);
	printf("org: '%#X'\n", 255);

	divider("PRECISION");
	ft_printf("ft : '%.5d'\n", 42);
	printf("org: '%.5d'\n", 42);

	ft_printf("ft : '%.0d'\n", 0);
	printf("org: '%.0d'\n", 0);

	divider("STRING PRECISION");
	ft_printf("ft : '%.3s'\n", "Abdullah");
	printf("org: '%.3s'\n", "Abdullah");

	ft_printf("ft : '%10.3s'\n", "Abdullah");
	printf("org: '%10.3s'\n", "Abdullah");

	divider("POINTER");
	void *ptr = (void *)0x7ffee4fa1234;
	ft_printf("ft : %p\n", ptr);
	printf("org: %p\n", ptr);

	ft_printf("ft : %p\n", NULL);
	printf("org: %p\n", NULL);

	divider("UNSIGNED");
	ft_printf("ft : %u\n", 3000000000u);
	printf("org: %u\n", 3000000000u);

	divider("HEX");
	ft_printf("ft : %x %X\n", 0xabcdef, 0xabcdef);
	printf("org: %x %X\n", 0xabcdef, 0xabcdef);

	divider("MIXED COMPLEX");
	ft_printf("ft : number=%+08d, hex=%#10x, str=%.5s, char=%c\n",
		-123, 255, "HelloWorld", 'A');
	printf("org: number=%+08d, hex=%#10x, str=%.5s, char=%c\n",
		-123, 255, "HelloWorld", 'A');

	divider("MAX / MIN INT");
	ft_printf("ft : %d | %lld\n", 2147483647, -2147483648LL);
	printf("org: %d | %lld\n", 2147483647, -2147483648LL);

	divider("EXTREME HEX");
	ft_printf("ft : %#016lx\n", 0xffffffffffffffffUL);
	printf("org: %#016lx\n", 0xffffffffffffffffUL);

	divider("EXTREME WIDTH");
	ft_printf("ft : '%50d'\n", 12345);
	printf("org: '%50d'\n", 12345);

	ft_printf("ft : '%-50d END'\n", 12345);
	printf("org: '%-50d END'\n", 12345);

	divider("NULL STRING");
	char *null_str = NULL;
	ft_printf("ft : '%s'\n", null_str);
	printf("org: '%s'\n", null_str);

	divider("MULTI FORMAT CHAOS");
	ft_printf("ft : %d-%x-%s-%p-%c-%u-END\n",
		-1234, 0xff22, "ABC", (void*)0x42, 'Z', 99999);
	printf("org: %d-%x-%s-%p-%c-%u-END\n",
		-1234, 0xff22, "ABC", (void*)0x42, 'Z', 99999);

	divider("ZERO + MINUS CONFLICT");
	ft_printf("ft : '%-05d'\n", 42);

	divider("RANDOM NUMBERS");
	for (int i = -5; i <= 5; i++)
	{
		ft_printf("ft : '%10d'\n", i);
		printf("org: '%10d'\n", i);
	}

	divider("DONE");
	return 0;
}
