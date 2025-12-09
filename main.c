#include <stdio.h>
#include "include/ft_printf.h"

static void	divider(const char *title)
{
	printf("\n==================== %s ====================\n", title);
}

static void run_test(const char *label, int r1, int r2)
{
	printf("%s -> ret ft=%d, org=%d\n\n", label, r1, r2);
}

int	main(void)
{
	int		r1;
	int		r2;
	char	ch1 = 'A';
	char	ch2 = 'z';
	char	ch3 = '\0';
	char	ch4 = ' ';
	char	ch5 = '0';
	char	*str1 = "Abdullah";
	char	*str2 = "";
	char	*str3 = "Hello 42 Abu Dhabi";
	char	*str_null = NULL;
	int		d1 = 0;
	int		d2 = 42;
	int		d3 = -42;
	int		d4 = 2147483647;
	int		d5 = -2147483648;
	unsigned int u1 = 0u;
	unsigned int u2 = 1u;
	unsigned int u3 = 42u;
	unsigned int u4 = 4000000000u;
	unsigned int hx1 = 0u;
	unsigned int hx2 = 0x1u;
	unsigned int hx3 = 0xau;
	unsigned int hx4 = 0xffu;
	unsigned int hx5 = 0x1234u;
	int		a = 1;
	int		b = 2;
	int		c = 3;

	/* ==================== %c ==================== */
	divider("%c TESTS");
	r1 = ft_printf("ft : [%c]\n", ch1);
	r2 = printf("org: [%c]\n", ch1);
	run_test("c #1", r1, r2);

	r1 = ft_printf("ft : [%c]\n", ch2);
	r2 = printf("org: [%c]\n", ch2);
	run_test("c #2", r1, r2);

	r1 = ft_printf("ft : [%c]\n", ch3);
	r2 = printf("org: [%c]\n", ch3);
	run_test("c #3 (NUL)", r1, r2);

	r1 = ft_printf("ft : [%c]\n", ch4);
	r2 = printf("org: [%c]\n", ch4);
	run_test("c #4 (space)", r1, r2);

	r1 = ft_printf("ft : [%c]\n", ch5);
	r2 = printf("org: [%c]\n", ch5);
	run_test("c #5 ('0')", r1, r2);

	r1 = ft_printf("ft : [%c][%c][%c]\n", 'A', 'B', 'C');
	r2 = printf("org: [%c][%c][%c]\n", 'A', 'B', 'C');
	run_test("c #6 (3 chars)", r1, r2);

	r1 = ft_printf("ft : start-%c-end\n", 'X');
	r2 = printf("org: start-%c-end\n", 'X');
	run_test("c #7", r1, r2);

	r1 = ft_printf("ft : [%c][%c]\n", '\t', '\n');
	r2 = printf("org: [%c][%c]\n", '\t', '\n');
	run_test("c #8 (tab/newline)", r1, r2);

	r1 = ft_printf("ft : [%c]\n", 127);
	r2 = printf("org: [%c]\n", 127);
	run_test("c #9 (DEL)", r1, r2);

	r1 = ft_printf("ft : [%c]\n", -1);
	r2 = printf("org: [%c]\n", -1);
	run_test("c #10 (negative)", r1, r2);

	/* ==================== %s ==================== */
	divider("%s TESTS");
	r1 = ft_printf("ft : [%s]\n", str1);
	r2 = printf("org: [%s]\n", str1);
	run_test("s #1 (normal)", r1, r2);

	r1 = ft_printf("ft : [%s]\n", str2);
	r2 = printf("org: [%s]\n", str2);
	run_test("s #2 (empty)", r1, r2);

	r1 = ft_printf("ft : [%s]\n", str3);
	r2 = printf("org: [%s]\n", str3);
	run_test("s #3 (sentence)", r1, r2);

	r1 = ft_printf("ft : [%s]\n", str_null);
	r2 = printf("org: [%s]\n", str_null);
	run_test("s #4 (NULL)", r1, r2);

	r1 = ft_printf("ft : begin-%s-end\n", "middle");
	r2 = printf("org: begin-%s-end\n", "middle");
	run_test("s #5", r1, r2);

	r1 = ft_printf("ft : [%s][%s]\n", "A", "B");
	r2 = printf("org: [%s][%s]\n", "A", "B");
	run_test("s #6 (two strings)", r1, r2);

	r1 = ft_printf("ft : [%s %s]\n", "Hello", "World");
	r2 = printf("org: [%s %s]\n", "Hello", "World");
	run_test("s #7 (two words)", r1, r2);

	r1 = ft_printf("ft : [%s]\n", "42\tAbu\tDhabi");
	r2 = printf("org: [%s]\n", "42\tAbu\tDhabi");
	run_test("s #8 (tabs)", r1, r2);

	r1 = ft_printf("ft : [%s]\n", "line1\nline2");
	r2 = printf("org: [%s]\n", "line1\nline2");
	run_test("s #9 (newlines)", r1, r2);

	r1 = ft_printf("ft : [%s]\n", "   spaces   ");
	r2 = printf("org: [%s]\n", "   spaces   ");
	run_test("s #10 (spaces)", r1, r2);

	/* ==================== %p ==================== */
	divider("%p TESTS");
	r1 = ft_printf("ft : [%p]\n", &a);
	r2 = printf("org: [%p]\n", &a);
	run_test("p #1 (&a)", r1, r2);

	r1 = ft_printf("ft : [%p]\n", &b);
	r2 = printf("org: [%p]\n", &b);
	run_test("p #2 (&b)", r1, r2);

	r1 = ft_printf("ft : [%p]\n", &c);
	r2 = printf("org: [%p]\n", &c);
	run_test("p #3 (&c)", r1, r2);

	r1 = ft_printf("ft : [%p]\n", (void *)0);
	r2 = printf("org: [%p]\n", (void *)0);
	run_test("p #4 (NULL)", r1, r2);

	r1 = ft_printf("ft : [%p][%p]\n", &a, &b);
	r2 = printf("org: [%p][%p]\n", &a, &b);
	run_test("p #5 (two ptrs)", r1, r2);

	r1 = ft_printf("ft : begin-%p-end\n", &a);
	r2 = printf("org: begin-%p-end\n", &a);
	run_test("p #6", r1, r2);

	r1 = ft_printf("ft : [%p]\n", (void *)&str1);
	r2 = printf("org: [%p]\n", (void *)&str1);
	run_test("p #7 (&str1)", r1, r2);

	r1 = ft_printf("ft : [%p]\n", (void *)&u1);
	r2 = printf("org: [%p]\n", (void *)&u1);
	run_test("p #8 (&u1)", r1, r2);

	r1 = ft_printf("ft : [%p]\n", (void *)&hx1);
	r2 = printf("org: [%p]\n", (void *)&hx1);
	run_test("p #9 (&hx1)", r1, r2);

	r1 = ft_printf("ft : [%p %p %p]\n", &a, &b, &c);
	r2 = printf("org: [%p %p %p]\n", &a, &b, &c);
	run_test("p #10 (3 ptrs)", r1, r2);

	/* ==================== %d / %i ==================== */
	divider("%d / %i TESTS");
	r1 = ft_printf("ft : [%d]\n", d1);
	r2 = printf("org: [%d]\n", d1);
	run_test("d #1 (0)", r1, r2);

	r1 = ft_printf("ft : [%d]\n", d2);
	r2 = printf("org: [%d]\n", d2);
	run_test("d #2 (42)", r1, r2);

	r1 = ft_printf("ft : [%d]\n", d3);
	r2 = printf("org: [%d]\n", d3);
	run_test("d #3 (-42)", r1, r2);

	r1 = ft_printf("ft : [%d]\n", d4);
	r2 = printf("org: [%d]\n", d4);
	run_test("d #4 (INT_MAX)", r1, r2);

	r1 = ft_printf("ft : [%d]\n", d5);
	r2 = printf("org: [%d]\n", d5);
	run_test("d #5 (INT_MIN)", r1, r2);

	r1 = ft_printf("ft : [%i]\n", d2);
	r2 = printf("org: [%i]\n", d2);
	run_test("i #6 (42)", r1, r2);

	r1 = ft_printf("ft : [%i]\n", d3);
	r2 = printf("org: [%i]\n", d3);
	run_test("i #7 (-42)", r1, r2);

	r1 = ft_printf("ft : [%d %d]\n", -1, 1);
	r2 = printf("org: [%d %d]\n", -1, 1);
	run_test("d #8 (-1,1)", r1, r2);

	r1 = ft_printf("ft : [%d]\n", 123456);
	r2 = printf("org: [%d]\n", 123456);
	run_test("d #9 (123456)", r1, r2);

	r1 = ft_printf("ft : [%i]\n", -99999);
	r2 = printf("org: [%i]\n", -99999);
	run_test("i #10 (-99999)", r1, r2);

	/* ==================== %u ==================== */
	divider("%u TESTS");
	r1 = ft_printf("ft : [%u]\n", u1);
	r2 = printf("org: [%u]\n", u1);
	run_test("u #1 (0)", r1, r2);

	r1 = ft_printf("ft : [%u]\n", u2);
	r2 = printf("org: [%u]\n", u2);
	run_test("u #2 (1)", r1, r2);

	r1 = ft_printf("ft : [%u]\n", u3);
	r2 = printf("org: [%u]\n", u3);
	run_test("u #3 (42)", r1, r2);

	r1 = ft_printf("ft : [%u]\n", u4);
	r2 = printf("org: [%u]\n", u4);
	run_test("u #4 (large)", r1, r2);

	r1 = ft_printf("ft : [%u %u]\n", 123u, 456u);
	r2 = printf("org: [%u %u]\n", 123u, 456u);
	run_test("u #5 (two)", r1, r2);

	r1 = ft_printf("ft : [%u]\n", 999999999u);
	r2 = printf("org: [%u]\n", 999999999u);
	run_test("u #6 (999999999)", r1, r2);

	r1 = ft_printf("ft : [%u]\n", 10u);
	r2 = printf("org: [%u]\n", 10u);
	run_test("u #7 (10)", r1, r2);

	r1 = ft_printf("ft : [%u]\n", 1000u);
	r2 = printf("org: [%u]\n", 1000u);
	run_test("u #8 (1000)", r1, r2);

	r1 = ft_printf("ft : [%u]\n", 429u);
	r2 = printf("org: [%u]\n", 429u);
	run_test("u #9 (429)", r1, r2);

	r1 = ft_printf("ft : [%u]\n", 1234567890u);
	r2 = printf("org: [%u]\n", 1234567890u);
	run_test("u #10 (1234567890)", r1, r2);

	/* ==================== %x / %X ==================== */
	divider("%x / %X TESTS");
	r1 = ft_printf("ft : [%x]\n", hx1);
	r2 = printf("org: [%x]\n", hx1);
	run_test("x #1 (0)", r1, r2);

	r1 = ft_printf("ft : [%x]\n", hx2);
	r2 = printf("org: [%x]\n", hx2);
	run_test("x #2 (1)", r1, r2);

	r1 = ft_printf("ft : [%x]\n", hx3);
	r2 = printf("org: [%x]\n", hx3);
	run_test("x #3 (0xa)", r1, r2);

	r1 = ft_printf("ft : [%x]\n", hx4);
	r2 = printf("org: [%x]\n", hx4);
	run_test("x #4 (0xff)", r1, r2);

	r1 = ft_printf("ft : [%x]\n", hx5);
	r2 = printf("org: [%x]\n", hx5);
	run_test("x #5 (0x1234)", r1, r2);

	r1 = ft_printf("ft : [%x]\n", 0xabcdefu);
	r2 = printf("org: [%x]\n", 0xabcdefu);
	run_test("x #6 (0xabcdef)", r1, r2);

	r1 = ft_printf("ft : [%X]\n", 0xabcdefu);
	r2 = printf("org: [%X]\n", 0xabcdefu);
	run_test("X #7 (0xABCDEF)", r1, r2);

	r1 = ft_printf("ft : [%x %X]\n", 0x42u, 0x42u);
	r2 = printf("org: [%x %X]\n", 0x42u, 0x42u);
	run_test("x #8 (pair)", r1, r2);

	r1 = ft_printf("ft : [%x]\n", 16u);
	r2 = printf("org: [%x]\n", 16u);
	run_test("x #9 (16)", r1, r2);

	r1 = ft_printf("ft : [%X]\n", 4095u);
	r2 = printf("org: [%X]\n", 4095u);
	run_test("X #10 (4095)", r1, r2);

	/* ==================== %% ==================== */
	divider("%% TESTS");
	r1 = ft_printf("ft : [%%]\n");
	r2 = printf("org: [%%]\n");
	run_test("%% #1 (single)", r1, r2);

	r1 = ft_printf("ft : [%%%%]\n");
	r2 = printf("org: [%%%%]\n");
	run_test("%% #2 (double)", r1, r2);

	r1 = ft_printf("ft : start%%end\n");
	r2 = printf("org: start%%end\n");
	run_test("%% #3 (middle)", r1, r2);

	r1 = ft_printf("ft : %%c=%%, %%d=%%\n");
	r2 = printf("org: %%c=%%, %%d=%%\n");
	run_test("%% #4 (text)", r1, r2);

	r1 = ft_printf("ft : 100%%%%\n");
	r2 = printf("org: 100%%%%\n");
	run_test("%% #5 (100%%)", r1, r2);

	r1 = ft_printf("ft : [%%][%c]\n", 'A');
	r2 = printf("org: [%%][%c]\n", 'A');
	run_test("%% #6 (with %%c)", r1, r2);

	r1 = ft_printf("ft : [%%][%s]\n", "test");
	r2 = printf("org: [%%][%s]\n", "test");
	run_test("%% #7 (with %%s)", r1, r2);

	r1 = ft_printf("ft : %%\n");
	r2 = printf("org: %%\n");
	run_test("%% #8 (line)", r1, r2);

	r1 = ft_printf("ft : begin%%%%end\n");
	r2 = printf("org: begin%%%%end\n");
	run_test("%% #9 (begin/end)", r1, r2);

	r1 = ft_printf("ft : no args but %%\n");
	r2 = printf("org: no args but %%\n");
	run_test("%% #10 (no args)", r1, r2);

	return (0);
}
