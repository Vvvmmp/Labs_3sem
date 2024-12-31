#pragma once
namespace Out { // работа с протоколом
	struct OUt { // протокол
		wchar_t outfile[PARM_MAX_SIZE]; // имя файла протокола
		ofstream* stream; // выходной поток
	};

	static const OUt INITLOG{ L"", NULL };
	OUt getout(wchar_t logfile[]); // для создания и открытия потокового вывода протокола
	void WriteOut(wchar_t outfile[], In::iN in); // запись о содержании файла
	void WriteError(OUt out, Error::ERROr error);
	void Close(OUt out); // закрытие потока для записи
}