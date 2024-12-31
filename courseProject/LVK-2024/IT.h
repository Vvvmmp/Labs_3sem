#pragma once
#include <iostream>

#define MAXSIZE_ID	9					
#define SCOPED_ID_MAXSIZE   MAXSIZE_ID*2
#define MAXSIZE_TI	  4096			
#define NUM_DEFAULT	  0x00000000		
#define STR_DEFAULT	  0x00			
#define NULLIDX_TI	  0xffffffff		
#define NULLIDX_TI	  0xffffffff		
#define STR_MAXSIZE	  255
#define NUM_MAXSIZE   4294967295
#define NUM_MINSIZE   0

#define MAX_PARAMS_COUNT		3
#define LENGHT_PARAMS_CNT		1
#define ATOII_PARAMS_CNT		1
#define FIBONACHI_PARAMS_CNT	1
#define FACTORIAL_PARAMS_CNT	1
#define POWER_PARAMS_CNT		2

#define LENGHT_TYPE IT::IDDATATYPE::NUM
#define ATOII_TYPE IT::IDDATATYPE::NUM
#define FIBONACHI_TYPE IT::IDDATATYPE::NUM
#define FACTORIAL_TYPE IT::IDDATATYPE::NUM
#define POWER_TYPE IT::IDDATATYPE::NUM



namespace IT
{
	enum IDDATATYPE { NUM = 1, STR = 2, PROC = 3, UNDEF };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, S = 5 };
	enum STDFNC { F_LENGHT, F_ATOII, F_FIBONACHI, F_FACTORIAL, F_POWER, F_NOT_STD };
	static const IDDATATYPE LENGHT_PARAMS[] = { IT::IDDATATYPE::STR };
	static const IDDATATYPE ATOII_PARAMS[] = { IT::IDDATATYPE::STR };
	static const IDDATATYPE FIBONACHI_PARAMS[] = { IT::IDDATATYPE::NUM };
	static const IDDATATYPE FACTORIAL_PARAMS[] = { IT::IDDATATYPE::NUM };
	static const IDDATATYPE POWER_PARAMS[] = { IT::IDDATATYPE::NUM, IT::IDDATATYPE::NUM };

	struct Entry
	{
		union
		{
			unsigned int	vint;
			struct
			{
				int len;
				char str[STR_MAXSIZE - 1];
			} vstr;
			struct
			{
				int count;
				IDDATATYPE* types;
			} params;
		} value;
		int			idxfirstLE;
		char		id[SCOPED_ID_MAXSIZE];
		IDDATATYPE	iddatatype;
		IDTYPE		idtype;

		Entry()
		{
			this->value.vint = NUM_DEFAULT;
			this->value.vstr.len = NULL;
			this->value.params.count = NULL;
		};
		Entry(char* id, int idxLT, IDDATATYPE datatype, IDTYPE idtype)
		{
			strncpy_s(this->id, id, SCOPED_ID_MAXSIZE - 1);
			this->idxfirstLE = idxLT;
			this->iddatatype = datatype;
			this->idtype = idtype;
		};
	};
	struct IdTable
	{
		int maxsize;
		int size;
		Entry* table;
	};
	IdTable Create(int size = NULL);
	void Add(
		IdTable& idtable,
		Entry entry);
	int isId(
		IdTable& idtable,
		char id[SCOPED_ID_MAXSIZE]);
	bool SetValue(IT::Entry* entry, char* value);
	bool SetValue(IT::IdTable& idtable, int index, char* value);
	void writeIdTable(std::ostream* stream, IT::IdTable& idtable);
};
