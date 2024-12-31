#include "stdafx.h"
#include "LexAnaliz.h"
#include "Graphs.h"
#include<stack>
#include<string>

#define SYMBOL 'm'

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <limits>


char* get10from2(char* t) {
	size_t len = strlen(t);
	if (len > 32) {
		return nullptr; 
	}
	unsigned long long number = 0;

	for (size_t i = 0; i < len; ++i) {
		number = (number << 1) | (t[i] - '0'); 
		if (number > std::numeric_limits<unsigned int>::max()) {
			return nullptr; 
		}
	}
	char* str = new char[50]; 
	snprintf(str, 50, "%llu", number); 
	return str;
}

char* get10from8(char* t)
{
	size_t len = strlen(t);
	if (len > 11) {		
		return nullptr; 
	}
	unsigned long long number = strtoull(t, nullptr, 8);
 	if (number > std::numeric_limits<unsigned int>::max()) {
		return nullptr; 
	}
	number = strtol(t, NULL, 8);

	char* str = new char[50];
	snprintf(str, 50, "%llu", number);
	return str;
}

char* get10from16(char* t)
{
	size_t len = strlen(t);
	if (len > 8) {
		return nullptr;
	}
	unsigned long long number = strtoull(t, nullptr, 16);
	if (number > std::numeric_limits<unsigned int>::max()) {
		return nullptr;
	}
	char* str = new char[50];
	snprintf(str, 50, "%llu", number);
	return str;
}


unsigned int DecimicalNotation(std::string input, unsigned int scaleofnot)
{
	std::string num = input.substr(1, input.size());
	return std::stoi(num, nullptr, scaleofnot);
}

namespace Lexer
{
	Graph graphs[N_GRAPHS] =
	{
		{ LEX_SEPARATORS, FST::FST(GRAPH_SEPARATORS) },
		{ LEX_LITERAL, FST::FST(GRAPH_INT_LITERAL) },
		{ LEX_LITERAL, FST::FST(GRAPH_STRING_LITERAL) },
		{ LEX_NEW, FST::FST(GRAPH_TYPE) },
		{ LEX_START, FST::FST(GRAPH_ROOT) },
		{ LEX_ID_TYPE, FST::FST(GRAPH_NUMBER) },
		{ LEX_ID_TYPE, FST::FST(GRAPH_STRING) },
		{ LEX_ID_TYPE, FST::FST(GRAPH_SYMBOL) },
		{ LEX_FUNCTION, FST::FST(GRAPH_FUNCTION) },
		{ LEX_PROCEDURE, FST::FST(GRAPH_INANE) },
		{ LEX_RETURN, FST::FST(GRAPH_FINISH) },
		{ LEX_WRITE, FST::FST(GRAPH_WRITE) },
		{ LEX_NEWLINE, FST::FST(GRAPH_NEWLINE) },
		{ LEX_CONDITION, FST::FST(GRAPH_WHEN) },
		{ LEX_CYCLE, FST::FST(GRAPH_CYCLE) },
		{ LEX_ISFALSE, FST::FST(GRAPH_ISFALSE) },
		{ LEX_ISTRUE, FST::FST(GRAPH_ISTRUE) },
		{ LEX_LITERAL, FST::FST(GRAPH_V_LITERAL) },
		{ LEX_LITERAL, FST::FST(GRAPH_HEX_LITERAL) },
		{ LEX_ID, FST::FST(GRAPH_ID) },
		{LEX_LITERAL, FST::FST(GRAPH_BINARY_LITERAL)},
		{LEX_LITERAL, FST::FST(GRAPH_SYMBOL_LITERAL)}
	};

	char* getScopeName(IT::IdTable idtable, char* prevword)
	{
		char* a = new char[5];
		a[0] = 'r';
		a[1] = 'o';
		a[2] = 'o';
		a[3] = 't';
		a[4] = '\0';
		if (strcmp(prevword, ROOT) == 0)
			return a;
		for (int i = idtable.size - 1; i >= 0; i--)
			if (idtable.table[i].idtype == IT::IDTYPE::F)
				return idtable.table[i].id;
		return nullptr;
	}

	int getLiteralIndex(IT::IdTable ittable, char* value, IT::IDDATATYPE type) // получаем индекс повторного литерала(по значению)
	{
		for (int i = 0; i < ittable.size; i++)
		{
			if (ittable.table[i].idtype == IT::IDTYPE::L && ittable.table[i].iddatatype == type)
			{
				switch (type)
				{
				case IT::IDDATATYPE::NUM:
					if (ittable.table[i].value.vint == atoi(value))
						return i;
					break;
				case IT::IDDATATYPE::STR:
					char buf[STR_MAXSIZE];
					for (unsigned j = 1; j < strlen(value) - 1; j++)
						buf[j - 1] = value[j];
					buf[strlen(value) - 2] = IN_CODE_NULL;
					if (strcmp(ittable.table[i].value.vstr.str, buf) == 0)
						return i;
					break;
				}
			}
		}
		return NULLIDX_TI;
	}

	IT::IDDATATYPE getType(char* curword, char* idtype)
	{
		if (!strcmp(TYPE_PROCEDURE, idtype))
			return IT::IDDATATYPE::PROC;
		if (!strcmp(TYPE_STRING, idtype))
			return IT::IDDATATYPE::STR;
		if (!strcmp(TYPE_NUMBER, idtype))
			return IT::IDDATATYPE::NUM;
		if (isdigit(*curword) || *curword == LEX_MINUS)
			return IT::IDDATATYPE::NUM;
		else if (*curword == IN_CODE_QUOTE)
			return IT::IDDATATYPE::STR;

		return IT::IDDATATYPE::UNDEF;
	}

	int getIndexInLT(LT::LexTable& lextable, int itTableIndex)
	{
		if (itTableIndex == NULLIDX_TI)		// если идентификатор встречается впервые
			return lextable.size;
		for (int i = 0; i < lextable.size; i++)
			if (itTableIndex == lextable.table[i].idxTI)
				return i;
		return NULLIDX_TI;
	}

	bool isLiteral(char* id)
	{
		if (isdigit(*id) || *id == IN_CODE_QUOTE || *id == '\'') {

			return true;
		}

		return false;
	}

	IT::STDFNC getStandFunction(char* id)
	{
		if (!strcmp(LENGHT, id))
			return IT::STDFNC::F_LENGHT;
		if (!strcmp(ATOII, id))
			return IT::STDFNC::F_ATOII;
		if (!strcmp(FIBONACHI, id))
			return IT::STDFNC::F_FIBONACHI;
		if (!strcmp(FACTORIAL, id))
			return IT::STDFNC::F_FACTORIAL;
		if (!strcmp(POWER, id))
			return IT::STDFNC::F_POWER;

		return IT::STDFNC::F_NOT_STD;
	}


	char* getNextLiteralName()						// сгенерировать следующее имя литерала
	{
		static int literalNumber = 1;
		char* buf = new char[SCOPED_ID_MAXSIZE], num[3];
		strcpy_s(buf, MAXSIZE_ID, "LTRL");
		_itoa_s(literalNumber++, num, 10);
		strcat(buf, num);
		return buf;
	}

	IT::Entry* getEntry(		// формирует и возвращает строку ТИ
		Lexer::LEX& tables,						// ТЛ + ТИ
		char lex,								// лексема
		char* id,								// идентификатор
		char* idtype,							// предыдущая (тип)
		bool isParam,							// признак параметра функции
		bool isFunc,							// признак функции
		Log::LOG log,							// протокол
		int line,								// строка в исходном тексте
		bool& lex_ok)							// флаг ошибки(по ссылке)
	{
		// тип данных
		IT::IDDATATYPE type = getType(id, idtype);
		int index = IT::isId(tables.idtable, id);	// индекс существующего идентификатора или -1
		if (lex == LEX_LITERAL)
			index = getLiteralIndex(tables.idtable, id, type);
		if (index != NULLIDX_TI)
			return nullptr;	// уже существует

		IT::Entry* itentry = new IT::Entry;
		itentry->iddatatype = type; // сохраняем тип данных

		// индекс первой строки в таблице лексем 
		itentry->idxfirstLE = getIndexInLT(tables.lextable, index);

		if (lex == LEX_LITERAL) // литерал
		{
			bool int_ok = IT::SetValue(itentry, id);
			if (!int_ok)
			{
				// превышен максимальный размер числового литерала
				Log::writeError(log.stream, Error::GetError(313, line, 0));
				lex_ok = false;
			}
			if (itentry->iddatatype == IT::IDDATATYPE::STR&& itentry->value.vstr.len == 0)
			{
				// пустой строковый литерал
				Log::writeError(log.stream, Error::GetError(310, line, 0));
				lex_ok = false;
			}
			strcpy_s(itentry->id, getNextLiteralName());
			itentry->idtype = IT::IDTYPE::L;
		}
		else // идентификатор
		{
			switch (type)
			{
			case IT::IDDATATYPE::STR:
				strcpy_s(itentry->value.vstr.str, "");
				itentry->value.vstr.len = STR_DEFAULT;
				break;
			case IT::IDDATATYPE::NUM:
				itentry->value.vint = NUM_DEFAULT;
				break;
			}

			if (isFunc)
			{
				switch (getStandFunction(id))
				{
				case IT::STDFNC::F_LENGHT:
				{
					itentry->idtype = IT::IDTYPE::S;
					itentry->iddatatype = LENGHT_TYPE;
					itentry->value.params.count = LENGHT_PARAMS_CNT;
					itentry->value.params.types = new IT::IDDATATYPE[LENGHT_PARAMS_CNT];
					for (int k = 0; k < LENGHT_PARAMS_CNT; k++)
						itentry->value.params.types[k] = IT::LENGHT_PARAMS[k];
					break;
				}
				case IT::STDFNC::F_ATOII:
				{
					itentry->idtype = IT::IDTYPE::S;
					itentry->iddatatype = ATOII_TYPE;
					itentry->value.params.count = ATOII_PARAMS_CNT;
					itentry->value.params.types = new IT::IDDATATYPE[ATOII_PARAMS_CNT];
					for (int k = 0; k < ATOII_PARAMS_CNT; k++)
						itentry->value.params.types[k] = IT::ATOII_PARAMS[k];
					break;
				}
				case IT::STDFNC::F_FIBONACHI:
				{
					itentry->idtype = IT::IDTYPE::S;
					itentry->iddatatype = FIBONACHI_TYPE;
					itentry->value.params.count = FIBONACHI_PARAMS_CNT;
					itentry->value.params.types = new IT::IDDATATYPE[FIBONACHI_PARAMS_CNT];
					for (int k = 0; k < FIBONACHI_PARAMS_CNT; k++)
						itentry->value.params.types[k] = IT::FIBONACHI_PARAMS[k];
					break;
				}
				case IT::STDFNC::F_FACTORIAL:
				{
					itentry->idtype = IT::IDTYPE::S;
					itentry->iddatatype = FACTORIAL_TYPE;
					itentry->value.params.count = FACTORIAL_PARAMS_CNT;
					itentry->value.params.types = new IT::IDDATATYPE[FACTORIAL_PARAMS_CNT];
					for (int k = 0; k < FACTORIAL_PARAMS_CNT; k++)
						itentry->value.params.types[k] = IT::FACTORIAL_PARAMS[k];
					break;
				}
				case IT::STDFNC::F_POWER:
				{
					itentry->idtype = IT::IDTYPE::S;
					itentry->iddatatype = POWER_TYPE;
					itentry->value.params.count = POWER_PARAMS_CNT;
					itentry->value.params.types = new IT::IDDATATYPE[POWER_PARAMS_CNT];
					for (int k = 0; k < POWER_PARAMS_CNT; k++)
						itentry->value.params.types[k] = IT::POWER_PARAMS[k];
					break;
				}
				case IT::STDFNC::F_NOT_STD:
					itentry->idtype = IT::IDTYPE::F;
					break;
				}
			}
			else if (isParam)
				itentry->idtype = IT::IDTYPE::P;
			else
				itentry->idtype = IT::IDTYPE::V;

			strncpy_s(itentry->id, id, SCOPED_ID_MAXSIZE);
		}

		int i = tables.lextable.size; // индекс в ТЛ текущего ИД

		if (i > 1 && itentry->idtype == IT::IDTYPE::V && tables.lextable.table[i - 2].lexema != LEX_NEW)
		{
			// в объявлении отсутствует ключевое слово type
			Log::writeError(log.stream, Error::GetError(304, line, 0));
			lex_ok = false;
		}
		if (i > 1 && itentry->idtype == IT::IDTYPE::F && tables.lextable.table[i - 1].lexema != LEX_FUNCTION)
		{
			// в объявлении не указан тип функции
			Log::writeError(log.stream, Error::GetError(303, line, 0));
			lex_ok = false;
		}
		
		if (itentry->iddatatype == IT::IDDATATYPE::UNDEF)
		{
			// невозможно определелить тип
 			Log::writeError(log.stream, Error::GetError(300, line, 0));
			lex_ok = false;
		}
		return itentry;
	}

	bool analyze(LEX& tables, In::IN& in, Log::LOG& log, Parm::PARM& parm)
	{
		static bool lex_ok = true;
		tables.lextable = LT::Create(MAXSIZE_LT);
		tables.idtable = IT::Create(MAXSIZE_TI);

		bool isParam = false, isFunc = false;
		int enterPoint = NULL;
		char curword[STR_MAXSIZE], nextword[STR_MAXSIZE];
		int curline;
		std::stack <char*> scopes;

		for (int i = 0; i < In::InWord::size; i++)
		{
			strcpy_s(curword, in.words[i].word);
			if (i < In::InWord::size - 1)
				if (strlen(in.words[i + 1].word) <= STR_MAXSIZE)
					strcpy_s(nextword, in.words[i + 1].word);
				else
				{
					lex_ok = false;
					throw ERROR_THROW_IN(313, -1, 0);
					break;
				}

			if (i < In::InWord::size - 1)
				strcpy_s(nextword, in.words[i + 1].word);
			curline = in.words[i].line;
			isFunc = false;
			int idxTI = NULLIDX_TI;

			for (int j = 0; j < N_GRAPHS; j++)
			{
				FST::FST fst(curword, graphs[j].graph);
				if (FST::execute(fst))
				{
					bool is_moreorlessandequal = false;
					char lexema = graphs[j].lexema;
					switch (lexema)
					{
					case LEX_START:
						enterPoint++;
						break;
					case LEX_SEPARATORS:
					{
						switch (*curword)
						{
						case LEX_LEFTHESIS:
						{
							isParam = true;
							if (*nextword == LEX_RIGHTTHESIS || ISTYPE(nextword))
							{
								char* functionname = new char[MAXSIZE_ID];
								char* scopename = getScopeName(tables.idtable, in.words[i - 1].word);
								if (scopename == nullptr)
									break;

								strcpy_s(functionname, MAXSIZE_ID, scopename);
								scopes.push(functionname);
							}
							break;
						}
						case LEX_RIGHTTHESIS:
						{
							
							if (!isParam)
							{
								lex_ok = false;
								Log::writeError(log.stream, Error::GetError(317, curline, 0));
								break;
							}
							isParam = false;

							if ((*in.words[i - 1].word == LEX_LEFTHESIS || (i > 2 && (tables.lextable.table[tables.lextable.size - 2].lexema == LEX_ID_TYPE))) && curline != 1)
								scopes.pop();
							break;

						}
						case LEX_LEFTBRACE:
						{
							if (i > 0 && *in.words[i + 1].word == LEX_ISFALSE || *in.words[i + 1].word == LEX_ISTRUE || *in.words[i + 1].word == LEX_CYCLE)
								break;
							char* functionname = new char[MAXSIZE_ID];
							char* scopename = getScopeName(tables.idtable, in.words[i - 1].word);
							if (scopename == nullptr)  break;
							strcpy_s(functionname, MAXSIZE_ID, scopename);
							scopes.push(functionname);
							break;
						}
						case LEX_BRACELET:
						{
							if (*in.words[i + 1].word == LEX_ID_TYPE || *in.words[i + 1].word == LEX_PROCEDURE || *in.words[i + 1].word == LEX_START)
							{
								if (!scopes.empty())
									scopes.pop();
							}
							break;
						}
						}
						if (*curword == '<' && *nextword == '=')
						{
							lexema = LEX_LESSANDEQUAL;
							break;
						}
						if (*curword == '>' && *nextword == '=')
						{
							lexema = LEX_MOREANDEQUAL;
							break;
						}
						if (*curword == '=' && *in.words[i - 1].word == '<' || *curword == '=' && *in.words[i - 1].word == '>')
						{
							is_moreorlessandequal = true;
							break;
						}
						lexema = *curword;
						break;
					}

					case LEX_ID:
					case LEX_LITERAL:
					{
						if (i == 0) {
							Log::writeError(log.stream, Error::GetError(303, curline, 0));
							lex_ok = false;
							break;
						}
						char id[STR_MAXSIZE] = "";
						idxTI = NULLDX_TI;  // индекс идентификатора в ТИ
						if (*nextword == LEX_LEFTHESIS)
							isFunc = true;						// идентификатор функции
						char* idtype = (isFunc && i > 1) ?	// тип идентификатора
							in.words[i - 2].word : in.words[i - 1].word;
						if (!isFunc && ((strcmp(curword, ATOII) == 0) || (strcmp(curword, LENGHT) == 0) || (strcmp(curword, FACTORIAL) == 0) || (strcmp(curword, POWER) == 0) || (strcmp(curword, FIBONACHI) == 0))) {
							Log::writeError(log.stream, Error::GetError(321, curline, 0));
							lex_ok = false;
						}


						// пропускаем ключевое слово function
						if (!isFunc && !scopes.empty())
							strncpy_s(id, scopes.top(), MAXSIZE_ID);
						strncat(id, curword, MAXSIZE_ID);

						if (isLiteral(curword)) {
							if (curword[0] == OCTAL_SYSTEM && curword[1] == 'x') {
								char str[STR_MAXSIZE];
								strcpy_s(str, &curword[2]);
								char* a = get10from8(str);
								if (!a) {
									Log::writeError(log.stream, Error::GetError(320, curline, 0));
									lex_ok = false;
									break;
								}
								strcpy_s(id, a);
							}
							else if (curword[0] == BINARY_SYSTEM && curword[1] == 'x') {
								char* a = get10from2(&curword[2]);
								if (!a) {
									Log::writeError(log.stream, Error::GetError(320, curline, 0));
									lex_ok = false;
									break;
								}
								strcpy_s(id, a);
							}
							else if (curword[0] == '1' && curword[1] == '6' && curword[2] == 'x') {

								char* a = get10from16(&curword[3]);
								if (!a) {
									Log::writeError(log.stream, Error::GetError(320, curline, 0));
									lex_ok = false;
									break;
								}
								strcpy_s(id, a);
							}
							else
							{
								strcpy_s(id, curword); // литерал заменяется своим значением
							}

						}


						IT::Entry* itentry = getEntry(tables, lexema, id, idtype, isParam, isFunc, log, curline, lex_ok);
						if (itentry != nullptr) // первая встреча - объявление
						{
							if (isFunc)  // если функция - сохранить список параметров
							{
								if (getStandFunction(id) == IT::STDFNC::F_NOT_STD) // стандартная функция или нет
								{
									itentry->value.params.count = NULL;
									itentry->value.params.types = new IT::IDDATATYPE[MAX_PARAMS_COUNT];
									for (int k = i; in.words[k].word[0] != LEX_RIGHTTHESIS; k++)
									{
										if (k == In::InWord::size || in.words[k].word[0] == LEX_SEPARATOR)
											break;
										if (ISTYPE(in.words[k].word))
										{
											if (itentry->value.params.count >= MAX_PARAMS_COUNT)
											{
												Log::writeError(log.stream, Error::GetError(306, curline, 0));
												lex_ok = false;
												break;
											}
											itentry->value.params.types[itentry->value.params.count++] = getType(NULL, in.words[k].word);
										}
									}
								}
									
							}

							IT::Add(tables.idtable, *itentry);
							idxTI = tables.idtable.size - 1;
						}
						else // повторный идентификатор (уже есть)
						{
							int i = tables.lextable.size - 1; // попытка переопределить идентификатор
							if (i > 0 && tables.lextable.table[i - 1].lexema == LEX_NEW || tables.lextable.table[i].lexema == LEX_NEW
								|| tables.lextable.table[i - 1].lexema == LEX_FUNCTION || tables.lextable.table[i].lexema == LEX_FUNCTION
								|| tables.lextable.table[i - 1].lexema == LEX_ID_TYPE || tables.lextable.table[i].lexema == LEX_ID_TYPE
								|| tables.lextable.table[i - 1].lexema == LEX_PROCEDURE || tables.lextable.table[i].lexema == LEX_PROCEDURE)
							{
								Log::writeError(log.stream, Error::GetError(305, curline, 0));
								lex_ok = false;
							}
							idxTI = IT::isId(tables.idtable, id);	// индекс существующего идентификатора
							if (lexema == LEX_LITERAL)
								idxTI = getLiteralIndex(tables.idtable, curword, getType(id, in.words[i - 1].word)); // или литерала
						}
					}
					break;
					}
					if (is_moreorlessandequal) break;
					LT::Entry* ltentry = new LT::Entry(lexema, curline, idxTI);
					LT::Add(tables.lextable, *ltentry);
					break;
				}
				else if (j == N_GRAPHS - 1)
				{
					Log::writeError(log.stream, Error::GetError(201, curline, 0));
					lex_ok = false;
				}
			}
		}

		if (enterPoint == NULL)
		{
			Log::writeError(log.stream, Error::GetError(301));
			lex_ok = false;
		}
		if (enterPoint > 1)
		{
			Log::writeError(log.stream, Error::GetError(302));
			lex_ok = false;
		}
		return lex_ok;
	}
};