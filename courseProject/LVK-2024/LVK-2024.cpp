#include <iostream>
#include "stdafx.h"
#include "Log.h"
#include "Error.h"
#include "Parm.h"
#include "LexAnaliz.h"
#include "In.h"
#include "IT.h"
#include "LT.h"
#include "PolishNotation.h"
#include "SemAnaliz.h"
#include "MFST.h"
#include "Generator.h" 
#include <conio.h>
#include <string>
#include <cstdlib> 
#include <thread>  
#include <chrono> 
using namespace std;

void showAnimation(bool isSuccess, const string& message) {
	const char* successText = "\033[32mУспех!\033[0m";
	const char* errorText = "\033[31mОшибка!\033[0m"; 

	const char* text = isSuccess ? successText : errorText;
	cout << "\r" << text << " " << message << "                " << endl; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus");

	string LexicalAnalyzerError = "Лексический анализ завершен с ошибками\n";
	string SyntacticAnalyzerError = "Синтаксический анализ завершен с ошибками\n";
	string SemanticAnalyzerError = "Семантический анализ завершен с ошибками\n";
	string PolishSpellingError = "Произошла ошибка при преобразовании выражения\n";

	string LexicalAnalyzerGood = "Лексический анализ завершен без ошибок\n";
	string SyntacticAnalyzerGood = "Синтаксический анализ завершен без ошибок\n";
	string SemanticAnalyzerGood = "Семантический анализ завершен без ошибок\n";
	string PolishSpellingGood = "Преобразование выражения завершено без ошибок\n";

	string header = "\n~~~~~~~~~~~~~~Токен и Таблица идентификаторов~~~~~~~~~~~~~~";

	string FAIL = "Выполнение программы остановлено.\n";
	string PERFECT = "Программа завершена без ошибок.\n";
	bool coutInConsole = false;
	bool coutBatFile = true;
	Log::LOG log;

	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getstream(parm.log);
		Log::writeLog(log);
		Log::writeParm(log, parm);
		In::IN in = In::getin(parm.in, log.stream);
		if (in.faile != 0) {
			showAnimation(false, LexicalAnalyzerError);
			cerr << "Ошибка 200: Лексическая ошибка - недопустимый символ в исходном файле (-in)" << endl;
			return 0;
		}
		Log::writeIn(log.stream, in);

		in.words = In::getWordsTable(log.stream, in.text, in.code, in.size);
		Lexer::LEX tables;
		bool lex_ok = Lexer::analyze(tables, in, log, parm);

		Log::writeLine(log.stream, header, "");
		LT::writeLexTable(log.stream, tables.lextable);
		IT::writeIdTable(log.stream, tables.idtable);
		LT::writeLexemsOnLines(log.stream, tables.lextable);

		if (!lex_ok)
		{
			Log::writeLine(log.stream, LexicalAnalyzerError, "");
			showAnimation(lex_ok, LexicalAnalyzerError);
			return 0;
		}
		else
		{
				showAnimation(lex_ok, LexicalAnalyzerGood);
		}

		MFST_TRACE_START(log.stream);
		MFST::Mfst mfst(tables, GRB::getGreibach());
		bool synt_ok = mfst.start(log);
		mfst.savededucation();
		mfst.printrules(log);
		if (!synt_ok)
		{
			Log::writeLine(log.stream, SyntacticAnalyzerError, "");
			showAnimation(synt_ok, SyntacticAnalyzerError);
			return 0;
		}
		else {
			showAnimation(synt_ok, SyntacticAnalyzerGood);
		}
		bool sem_ok = Semantic::semanticsCheck(tables, log);
		if (!sem_ok)
		{
			Log::writeLine(log.stream, SemanticAnalyzerError, "");
			showAnimation(sem_ok, SemanticAnalyzerError);
			return 0;
		}
		else {
			showAnimation(sem_ok, SemanticAnalyzerGood);
		}
		bool polish_ok = Polish::PolishNotation(tables, log);

		if (!polish_ok)
		{
			Log::writeLine(log.stream, PolishSpellingError, "");
			showAnimation(polish_ok, PolishSpellingError);
			return 0;
		}
		else { 
			showAnimation(polish_ok, PolishSpellingGood);
		}

		if(coutInConsole){
		IT::writeIdTable(&cout, tables.idtable);
		LT::writeLexTable(&cout, tables.lextable);
		LT::writeLexemsOnLines(&cout, tables.lextable);
		}

		Log::writeLine(log.stream, header, "");
		LT::writeLexTable(log.stream, tables.lextable);
		IT::writeIdTable(log.stream, tables.idtable);
		LT::writeLexemsOnLines(log.stream, tables.lextable);




		Gener::CodeGeneration(tables, parm, log);
		Log::writeLine(log.stream, PERFECT, "");
		showAnimation((polish_ok && sem_ok && lex_ok && synt_ok), PERFECT);
		Log::Close(log);
		if(coutBatFile) system("start C:\\labi\\3sem\\courseProject\\LVK-2024\\bat\\Program.bat");

	}
	catch (Error::ERROR e)
	{
		Log::writeError(log.stream, e);
	}


}