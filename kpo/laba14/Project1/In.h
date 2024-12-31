#pragma once
#define IN_MAX_LEN_TEXT 1024*1024 // ������������ ������ ��������� ����
#define IN_CODE_ENDL '\n' // ������ ����� ������

// ������� �������� ������� ����������, ������ - ���(Windows-1251) �������
// �������� iN::F - ����������� ������, iN::T -����������� ������, iN::I - ������������(�� ��������)
// ���� 0 <= �������� < 256 - �� ��������� ������ ��������
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
	struct iN { // �������� ������
		enum { T = 1024, F = 2048, I = 4096 }; // T - ���������� ������, F - ������������ ������, i - ������������, ����� ��������
		int size; // ������ ��������� ����
		int lines; // ���������� �����
		int ignor; // ���������� ����������������� ��������
		unsigned char* text; // �������� ���(Windows-1251)

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
	iN getin(wchar_t infile[]); // ������ � ��������� ������� �����
}