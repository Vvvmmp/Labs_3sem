#pragma once
#include "LT.h"
#include "In.h"
#include "Log.h"
#include "FST.h"

#define TYPE_NUMBER		"num"
#define TYPE_STRING		"symbol"
#define TYPE_PROCEDURE 	"inane"
#define ATOII			"atoii"
#define ROOT			"root"
#define LENGHT			"lenght"
#define FACTORIAL		"factorial"
#define POWER			"power"
#define FIBONACHI		"fibonachi"

#define OCTAL_SYSTEM '8'
#define BINARY_SYSTEM '2'



#define ISTYPE(str) ( !strcmp(str, TYPE_NUMBER) || !strcmp(str, TYPE_STRING) )

namespace Lexer
{
	struct LEX
	{
		LT::LexTable lextable;
		IT::IdTable	idtable;
		LEX() {}
	};
	struct Graph
	{
		char lexema;
		FST::FST graph;
	};



	IT::Entry* getEntry
	(
		Lexer::LEX& tables,
		char lex,
		char* id,
		char* idtype,
		bool isParam,
		bool isFunc,
		Log::LOG log,
		int line,
		bool& rc_err
	);

	struct ERROR_S
	{
		int id;
		char message[ERROR_MAXSIZE_MESSAGE];
		struct
		{
			short line = -1;
			short col = -1;
		} position;
	};
	bool analyze(LEX& tables, In::IN& in, Log::LOG& log, Parm::PARM& parm);
	int	getIndexInLT(LT::LexTable& lextable, int itTableIndex);
};

