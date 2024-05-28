#include "ft_printf.h"
#include <stdio.h>

int main()
{
	//case: test numbers
	printf("sys-char_printed=%d\n", printf("%d\n", 123));
	ft_printf("own-char_printed=%d\n\n", ft_printf("%d\n", 123));

	// printf("sys-char_printed=%d\n", printf("%d\n", -78));
	// ft_printf("own-char_printed=%d\n\n", ft_printf("%d\n", -78));

	// printf("sys-char_printed=%d\n", printf("%d\n", 0));
	// ft_printf("own-char_printed=%d\n\n", ft_printf("%d\n", 0));
	

	// printf("sys-char_printed=%d\n", printf("%u\n", 420));
	// ft_printf("own-char_printed=%d\n\n", ft_printf("%u\n", 420));

	// printf("sys-char_printed=%d\n", printf("%u\n", -420));
	// ft_printf("own-char_printed=%d\n\n", ft_printf("%u\n", -420));

	//case: output address of a pointer
	// int n = 14;
	// int *p = &n;
	// printf("char_printed=%d\n", printf("%p\n", p));
	
	// // case: format = NULL
	// int char_printed;
	// char *str;
	// char_printed = printf(str);
	// printf("\n");
	// printf("char_printed=%d\n", char_printed);

	// // case: *format = NULL
	// puts("when the format=NULL, the output of printf=");
	// printf("");
	// puts("\n");

	// printf("%-10d\n", 123);      // 左对齐，输出宽度至少为10
	// printf("%+10d\n", 123);      // 右对齐，带正号，输出宽度至少为10
	// printf("%010d\n", 123);      // 右对齐，用零填充，输出宽度至少为10
	// printf("%0.2f\n", 3.14159);   // 输出3.14，保留两位小数
	// printf("%#x\n", 255);        // 输出0xff，十六进制前缀
	// printf("%.*s\n", 5, "Hello, World!"); // 输出Hello，只输出前5个字符


	// printf("a%k");

	// printf("char_printed=%d\n", printf("%x %X\n", 123, 123));


}