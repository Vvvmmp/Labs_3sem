#include <Windows.h>
#include <iostream>

extern "C"
{
	unsigned int __stdcall lenght(char* str)
	{
		if (str == nullptr) {
			return 0;
		}

		unsigned int len = 0;
		while (str[len] != '\0' && len < 256) {
			len++;
		}

		return len;
	}

	unsigned int __stdcall atoii(char* buffer, char* ptr)
	{
		int n = 0;
		while (*ptr >= '0' && *ptr <= '9')
		{
			n *= 10;
			n += *ptr++;
			n -= '0';
		}
		return n;

	}

	unsigned int __stdcall outnum(unsigned int value)
	{
		std::cout << value;
		return 0;
	}

	unsigned int __stdcall outstr(char* ptr)
	{
		if (ptr == nullptr)
		{
			std::cout << std::endl;
		}

		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];

		return 0;
	}

	unsigned int __stdcall factorial(unsigned int number)
	{
		if (number == 0) 
			return 1;
		if (number < 0)
			return 0;
		if (number >= 13) {
			MessageBoxA(NULL, "Выход за предел Int", "Факториал числа", MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			return 0;
		}
		int F = 1;
		for (int i = 1; i <= number; i++)
		{
			F *= i;
		}

		return F;
	}
	unsigned int __stdcall power(unsigned int number, unsigned int pow)
	{
		if (pow == 0)
			return 1;

		unsigned long long result = 1;
		for (unsigned int i = 1; i <= pow; ++i) {
			result *= number;
		}
		if (result > UINT_MAX) {
			MessageBoxA(NULL, "Выход за предел Int", "Степенная функция", MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			return 0;
		}
		return static_cast<unsigned int>(result);
	}

	unsigned int __stdcall fibonachi(unsigned int number)
	{
		if (number == 1 || number == 2) 
			return 1;
		
		if (number >= 48) {
			MessageBoxA(NULL, "Выход за предел Int", "Числа Фибоначчи", MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
			return 0;
		}

		unsigned int num1 = 1; 
		unsigned int num2 = 1; 
		unsigned int num_next = 0;

		for (unsigned int i = 3; i <= number; i++) {
			num_next = num1 + num2;
			num1 = num2;
			num2 = num_next;
		}

		return num2;
	}
}
