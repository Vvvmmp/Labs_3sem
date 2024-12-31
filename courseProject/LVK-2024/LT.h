#pragma once
#include <fstream>

#define LEX_SEPARATORS	 'S'	
#define	LEX_ID_TYPE    	 't'	
#define	LEX_ID			 'i'	
#define	LEX_LITERAL		 'l'	
#define	LEX_FUNCTION     'f'	
#define	LEX_START		 'm'	
#define	LEX_SEPARATOR	 ';'	
#define	LEX_COMMA		 ','	
#define	LEX_LEFTBRACE	 '['	
#define	LEX_BRACELET	 ']'	
#define LEX_LEFT         '{'    
#define LEX_RIGHT        '}'    
#define	LEX_LEFTHESIS	 '('	
#define	LEX_RIGHTTHESIS	 ')'	
#define	LEX_PLUS		 '+'	
#define	LEX_MINUS		 '-'	
#define	LEX_STAR		 '*'	
#define LEX_DIRSLASH	 '/'	
#define	LEX_EQUAL		 '='	
#define LEX_CONDITION	 '?'	
#define LEX_DIEZ		 '~'
#define	LEX_LITERAL_NUMO 'q'    
#define LEX_ISTRUE		 'w'	
#define LEX_ISFALSE		 'r'	
#define LEX_CYCLE		 'c'	
#define LEX_WRITE		 'o'	
#define LEX_NEWLINE		 '^'	
#define LEX_RETURN		 'e'	
#define LEX_PROCEDURE	 'p'	
#define LEX_NEW			 '#'	
#define LEX_MORE		 '>'	
#define LEX_LESS		 '<'	
#define LEX_MOREANDEQUAL 'x'	
#define LEX_LESSANDEQUAL 'y'	
#define LEX_EQUALS		 '&'	
#define LEX_NOTEQUALS	 '!'	
#define LEX_QUOTES_ONE   '\''
#define	LEXEMA_FIXSIZE   1	    
#define	MAXSIZE_LT		 4096	
#define	NULLDX_TI	 0xffffffff	


namespace LT
{
	struct Entry
	{
		char lexema;
		int sn;
		int idxTI;

		Entry();
		Entry(char lexema, int snn, int idxti = NULLDX_TI);
	};

	struct LexTable
	{
		int maxsize;
		int size;
		Entry* table;
	};

	LexTable Create(int size);
	void Add(LexTable& lextable, Entry entry);
	void writeLexTable(std::ostream* stream, LT::LexTable& lextable);
	void writeLexemsOnLines(std::ostream* stream, LT::LexTable& lextable);
};
