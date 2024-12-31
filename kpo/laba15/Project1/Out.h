#pragma once
namespace Out { // ������ � ����������
	struct OUt { // ��������
		wchar_t outfile[PARM_MAX_SIZE]; // ��� ����� ���������
		ofstream* stream; // �������� �����
	};

	static const OUt INITLOG{ L"", NULL };
	OUt getout(wchar_t logfile[]); // ��� �������� � �������� ���������� ������ ���������
	void WriteOut(wchar_t outfile[], In::iN in); // ������ � ���������� �����
	void WriteError(OUt out, Error::ERROr error);
	void Close(OUt out); // �������� ������ ��� ������
}