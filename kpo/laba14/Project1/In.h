#pragma once
#define IN_MAX_LEN_TEXT 1024*1024 // максимальный размер исходного кода
#define IN_CODE_ENDL '\n' // символ конца строки

// таблица проверки входной информации, индекс - код(Windows-1251) символа
// значения iN::F - запрещенный символ, iN::T -разрешенный символ, iN::I - игнорировать(не выводить)
// если 0 <= значение < 256 - то выводится данное значение
#define IN_CODE_TABLE {\
	iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::T, iN::F, iN::F, iN::I, iN::F, iN::F, \
	iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
	iN::T, iN::T, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
	iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
	iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::T, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
	iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::T, iN::I,   '!',  iN:F,  iN::F, iN::F, iN::F, iN::F, iN::F, \
	iN::F, iN::F, iN::F, iN::F, iN::T, iN::T, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::T, iN::F, iN::F, iN::T, \
	iN::F, iN::F, iN::T, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
																																																									\
  iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
  iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
  iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
  iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
  iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::T, iN::F, iN::F, iN::T, \
  iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
  iN::F, iN::F, iN::T, iN::F, iN::F, iN::T, iN::F, iN::F, iN::T, iN::T, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
  iN::T, iN::F, iN::T, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, iN::F, \
}
namespace In {
	struct iN { // исходные данные
		enum { T = 1024, F = 2048, I = 4096 }; // T - допустимый символ, F - недопустимый символ, i - игнорировать, иначе заменить
		int size; // размер исходного кода
		int lines; // количество строк
		int ignor; // количество проигнорированных символов
		unsigned char* text; // исходный код(Windows-1251)

		int code[256] = {
	F, F, F, F, F, F, F, F, F, F, T, F, F, I, F, F, \
	F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, \
	T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, \
	T, F, T, F, F, T, F, F, F, F, F, F, F, F, F, F, \
	F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, \
	F, F, F, F, F, F, T, F, I, F, F, F, F, F, F, F, \
	F, T, F, F, T, T, F, F, T, T, F, T, T, F, F, F, \
	F, F, F, T, T, T, T, F, F, T, T, F, F, F, F, F, \
																																																									\
	F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, \
	F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, \
	F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, \
	F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, \
	'-', F, T, F, F, F, F, F, T, T, T, T, F, F, F, F, \
	F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, \
	T, F, T, F, T, T, T, F, T, T, T, T, F, F, F, F, \
	F, T, F, T, F, F, T, F, F, F, F, F, F, F, F, F, \
		};
	};
	iN getin(wchar_t infile[]); // ввести и проверить входной поток
}