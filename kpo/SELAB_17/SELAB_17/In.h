#pragma once
#include "Parm.h"
#define IN_MAX_LEN_TEXT 1024*1024 // ������������ ������ ��������� ����
#define IN_CODE_ENDL '\n' // ������ ����� ������

// ������� �������� ������� ����������, ������ - ���(Windows-1251) �������
// �������� iN::F - ����������� ������, iN::T -����������� ������, iN::I - ������������(�� ��������)
// ���� 0 <= �������� < 256 - �� ��������� ������ ��������
namespace In {
	struct iN { // �������� ������
		enum { T = 1024, F = 2048, I = 4096 }; // T - ���������� ������, F - ������������ ������, i - ������������, ����� ��������
		int size = 0; // ������ ��������� ����
		int lines = 0; // ���������� �����
		int ignore = 0; // ���������� ����������������� ��������
		unsigned char* text; // �������� ���(Windows-1251)
		
		int code[256] = { // ����� ������� ��������
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
																																																								\
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
		};
	};
	iN getin(wchar_t infile[]); // ������ � ��������� ������� �����
	void in_ignore(char* str, int index);
}