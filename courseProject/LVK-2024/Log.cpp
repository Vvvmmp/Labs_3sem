#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <fstream>
#pragma warning(disable : 4996)
//#define W(x, y)  << std::setw(x) << (y) <<
//#define STR(n, line, type, id)\
//	"|" W(4,n) " |  " W(5,line) "    |" W(17,type) " |  " W(SCOPED_ID_MAXSIZE, id) " |"

using namespace std;

namespace Log
{

	LOG getstream(wchar_t  logfile[])
	{
		LOG stream;
		stream.stream = new std::ofstream;
		stream.stream->open(logfile);
		if (!stream.stream->is_open())
			throw ERROR_THROW(103);
		wcscpy_s(stream.logfile, logfile);
		return stream;
	}

	void writeLog(LOG& log)
	{
		char buffer[80];
		time_t seconds = time(NULL);
		tm* timeinfo = localtime(&seconds);
		const char* format = "%d.%m.%Y %H:%M:%S";
		strftime(buffer, 80, format, timeinfo);
		*log.stream << "\n~~~~~~~~~~~ Ïðîòîêîë ~~~~~~~~~~~~ Äàòà: " << buffer << " ~~~~~~~~~~~~ \n\n";
	}

	void writeLine(std::ostream* stream, string a, string b)
	{
		string result = a + b;
		*stream << result << std::endl;
	}

	void writeParm(LOG& log, Parm::PARM& parm)
	{
		char inTxt[PARM_MAX_SIZE],
			outTxt[PARM_MAX_SIZE],
			logTxt[PARM_MAX_SIZE];
		wcstombs(inTxt, parm.in, wcslen(parm.in) + 1);
		wcstombs(outTxt, parm.out, wcslen(parm.out) + 1);
		wcstombs(logTxt, parm.log, wcslen(parm.log) + 1);
		*log.stream << "\n~~~~~ Ïàðàìåòðû ~~~~~~~~";
		*log.stream << "\n-in: " << inTxt
			<< "\n-out: " << outTxt
			<< "\n-log: " << logTxt;

	}

	void writeIn(std::ostream* stream, In::IN& in)
	{
		*stream << "\n~~~~ ÈÑÕÎÄÍÛÅ ÄÀÍÍÛÅ ~~~~";
		*stream << "\nAmount of characters: " << std::setw(3) << in.size
			<< "\nIgnored: " << std::setw(3) << in.ignor
			<< "\nAmount of lines: " << std::setw(3) << in.lines << "\n\n";
	}

	void writeError(std::ostream* stream, Error::ERROR e)
	{



		if (stream == NULL)
		{
			if (e.position.col == -1 || e.position.line == -1)
				std::cout << std::endl << "Error" << e.id << ": " << e.message << std::endl;
			else if (e.position.col == NULL)
				std::cout << std::endl << "Error" << e.id << ": " << e.message
				<< " Line: " << e.position.line << std::endl;
			else
				std::cout << std::endl << "Error" << e.id << ": " << e.message
				<< " Line: " << e.position.line
				<< " Position in line: " << e.position.col << std::endl;
			system("pause");
		}
		else
		{

			if (e.position.col == -1 || e.position.line == -1) {
				*stream << std::endl << "Error N" << e.id << ": " << e.message;

			}

			else if (e.position.col == NULL) {
				*stream << std::endl << "Error N" << e.id << ": " << e.message
					<< " Line: " << e.position.line;

			}
			else {
				*stream << std::endl << "Error N" << e.id << ": " << e.message
					<< " Line: " << e.position.line
					<< " Position in line: " << e.position.col;
				*stream << std::endl;


			}

		}

	}

	void writeWords(std::ostream* stream, In::InWord* words)
	{
		*stream << " ~~~~~~~~~~~~~~~~~~ ÒÀÁËÈÖÀ: ~~~~~~~~~~~~~~~~" << std::endl;
		for (int i = 0; i < words->size; i++)
			*stream << std::setw(2) << i << std::setw(3) << words[i].line << " |  " << words[i].word << std::endl;
		*stream << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	}

	void Close(LOG& log)
	{
		(*log.stream).close();
	}
};