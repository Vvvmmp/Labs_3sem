#include "Error.h"
#include "stdafx.h"
#include "Out.h"
#include "in.h"
using namespace std;

namespace Out {
	OUt getout(wchar_t outfile[]) {		
		OUt out;
		out.stream = new ofstream;	
		out.stream->open(outfile);
		if (!out.stream->is_open()) { 
			throw ERROR_THROW(112); 
		}
		wcscpy_s(out.outfile, outfile);
		return out;
	}

	void WriteOut(wchar_t outfile[], In::iN in)
	{
		ofstream fout(outfile);
		fout << in.text;
		fout.close();
	}
	void WriteError(OUt out, Error::ERROr er) { 
		if (out.stream) { 
			*out.stream << "Ошибка " << er.id << ": " << er.message; 
			if (er.inext.line != -1) { 
				*out.stream << ", строка " << er.inext.line << ", позиция " << er.inext.col << '\n';
			}
			else {
				*out.stream << '\n';
			}
		}
		else { 
			cout << "Ошибка " << er.id << ": " << er.message << '\n';
			cout << "Строка " << er.inext.line << ", позиция " << er.inext.col << '\n';
		}
	}

	void Close(OUt out) { 
		out.stream->close();
		delete out.stream;
	}
}