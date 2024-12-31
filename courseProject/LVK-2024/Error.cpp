#include "stdafx.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "Системная ошибка: недопустимый код ошибки"),
		ERROR_ENTRY(1, "Системная ошибка: сбой системы"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Системная ошибка: необходимо указать параметр -in"),
		ERROR_ENTRY(101, "Системная ошибка: превышена длина входного параметра"),
		ERROR_ENTRY(102, "Системная ошибка: ошибка при открытии исходного файла (-in)"),
		ERROR_ENTRY(103, "Системная ошибка: ошибка создания файла журнала (-log)"),
		ERROR_ENTRY_NODEF(104), ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107), ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY_NODEF10(110), ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140),
		ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY(200, "Лексическая ошибка: недопустимый символ в исходном файле (-in)"),
		ERROR_ENTRY(201, "Лексическая ошибка: неизвестная последовательность символов"),
		ERROR_ENTRY(202, "Лексическая ошибка: превышен размер таблицы токенов"),
		ERROR_ENTRY(203, "Лексическая ошибка: превышен размер таблицы идентификаторов"),
		ERROR_ENTRY_NODEF(204), ERROR_ENTRY_NODEF(205), ERROR_ENTRY_NODEF(206), ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240),
		ERROR_ENTRY_NODEF10(250), ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY(300, "Семантическая ошибка: необъявленный идентификатор"),
		ERROR_ENTRY(301, "Семантическая ошибка: отсутствует начало точки входа"),
		ERROR_ENTRY(302, "Семантическая ошибка: найдено несколько точек входа"),
		ERROR_ENTRY(303, "Семантическая ошибка: тип идентификатора не указан в объявлении"),
		ERROR_ENTRY(304, "Семантическая ошибка: отсутствует ключевое слово # в объявлении"),
		ERROR_ENTRY(305, "Семантическая ошибка: попытка переопределить идентификатор"),
		ERROR_ENTRY(306, "Семантическая ошибка: превышено максимальное количество параметров функции"),
		ERROR_ENTRY(307, "Семантическая ошибка: слишком много параметров в вызове"),
		ERROR_ENTRY(308, "Семантическая ошибка: количество параметров, ожидаемых функцией, и переданные параметры не совпадают"),
		ERROR_ENTRY(309, "Семантическая ошибка: несоответствие типов передаваемых параметров"),
		ERROR_ENTRY(310, "Семантическая ошибка: использование пустого строкового/символьного литерала не допускается"),
		ERROR_ENTRY(311, "Семантическая ошибка: обнаружен символ \'\'\'\'. Возможно, не закрытый строковый литерал"),
		ERROR_ENTRY(312, "Семантическая ошибка: превышен размер строкового литерала"),
		ERROR_ENTRY(313, "Семантическая ошибка: недопустимый числовой литерал"),
		ERROR_ENTRY(314, "Семантическая ошибка: типы данных в выражении не совпадают"),
		ERROR_ENTRY(315, "Семантическая ошибка: тип функции и возвращаемое значение не совпадают"),
		ERROR_ENTRY(316, "Семантическая ошибка: недопустимое строковое выражение справа от знака \'=\'"),
		ERROR_ENTRY(317, "Семантическая ошибка: недопустимое условное выражение"),
		ERROR_ENTRY(318, "Семантическая ошибка: деление на ноль"),
		ERROR_ENTRY(319, "Семантическая ошибка: превышен размер типа данных"),
		ERROR_ENTRY(320, "Семантическая ошибка: выход за пределы типа данных"),
		ERROR_ENTRY(321, "Семантическая ошибка: название переменной совпадает с названием функции из статической библиотеки"),
		ERROR_ENTRY_NODEF10(322), ERROR_ENTRY_NODEF10(323), ERROR_ENTRY_NODEF10(324), ERROR_ENTRY_NODEF10(325),
		ERROR_ENTRY_NODEF10(326), ERROR_ENTRY_NODEF10(327), ERROR_ENTRY_NODEF10(328), ERROR_ENTRY_NODEF10(329),
		ERROR_ENTRY_NODEF10(330),ERROR_ENTRY_NODEF10(340),ERROR_ENTRY_NODEF10(350),
		ERROR_ENTRY_NODEF10(360),ERROR_ENTRY_NODEF10(370),ERROR_ENTRY_NODEF10(380),ERROR_ENTRY_NODEF10(390),
		ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600, "Синтаксическая ошибка: недопустимая структура программы"),
		ERROR_ENTRY(601, "Синтаксическая ошибка: список параметров функции не найден"),
		ERROR_ENTRY(602, "Синтаксическая ошибка: Ошибка в теле функции"),
		ERROR_ENTRY(603, "Синтаксическая ошибка: Ошибка в теле функции"),
		ERROR_ENTRY(604, "Синтаксическая ошибка: Ошибка в списке параметров функции"),
		ERROR_ENTRY(605, "Синтаксическая ошибка: Ошибка в вызове функции / выражения"),
		ERROR_ENTRY(606, "Синтаксическая ошибка: Ошибка в фактическом списке параметров функции"),
		ERROR_ENTRY(607, "Синтаксическая ошибка: Ошибка построения цикла / условного выражения"),
		ERROR_ENTRY(608, "Синтаксическая ошибка: Ошибка в теле цикла / условном выражении"),
		ERROR_ENTRY(609, "Синтаксическая ошибка: Ошибка в условии цикла / условном выражении"),
		ERROR_ENTRY(610, "Синтаксическая ошибка: Ошибка в условии цикла / условном выражении"),
		ERROR_ENTRY(611, "Синтаксическая ошибка: недопустимый арифметический оператор"),
		ERROR_ENTRY(612, "Синтаксическая ошибка: Недопустимое выражение. Ожидаются только идентификаторы / литералы"),
		ERROR_ENTRY(613, "Cинтаксическая ошибка: Ошибка в арифметическом выражении"),
		ERROR_ENTRY(614, "Синтаксическая ошибка: недопустимый синтаксис"),
		ERROR_ENTRY(615, "Синтаксическая ошибка: недопустимый синтаксис в теле цикла / условного выражения"),
		ERROR_ENTRY_NODEF(616), ERROR_ENTRY_NODEF(617),ERROR_ENTRY_NODEF(618), ERROR_ENTRY_NODEF(619),
		ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630), ERROR_ENTRY_NODEF10(640), ERROR_ENTRY_NODEF10(650),
		ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670), ERROR_ENTRY_NODEF10(680), ERROR_ENTRY_NODEF10(690),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};

	ERROR GetError(int id)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			for (int i = 0; i < 1000; i++) {
				if (id == errors[i].id) {
					return errors[i];
				}
			}
		return errors[0];
	}
		else
			return errors[0];
	}

	ERROR GetError(int id, int line, int col)
	{
		ERROR err = GetError(id);
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			for (int i = 0; i < 1000; i++) {
				if (id == errors[i].id) {
					err.position.col = col;
					err.position.line = line;
					return errors[i];
				}
			}
		}
		else
			return err;
	}
};