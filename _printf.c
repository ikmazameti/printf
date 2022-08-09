#include "main.h"

/**
  *_printf - displays to the stdout according to a format
  *@format: format string containg the characters and specifiers
  *Description: This function calls get_print(). get_priint() function 
  *determines what to print depending on the format specifiers contained in @fmt
  *Return: length of the formatted output string.
  */

int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list args;
	flags_t flags = {0, 0, 0};
	register int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if(*p == '%')
		{
			p++;
			if(*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while(get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(args, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
