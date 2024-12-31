#include <iostream>
#include "stdafx.h"
#include "LT.h"

namespace LT {

	LexTable Create(int size) {
		if (size > LT_MAXSIZE) {
			throw ERROR_THROW(114);
		}
		LexTable lextable;
		lextable.maxsize = size;
		lextable.size = 0;
		lextable.table = new Entry[size];
		return lextable;
	}

	void Add(LexTable& lextable, Entry entry) {
		if (lextable.size + 1 > lextable.maxsize) {
			throw ERROR_THROW(115);
		}
		lextable.table[lextable.size] = entry;
		lextable.size++;
	}

	Entry GetEntry(LexTable& lextable, int n) {
		if (n < 0 || n > lextable.size - 1) {
			throw ERROR_THROW(116);
		}
		return lextable.table[n];
	}

	void Delete(LexTable& lextable) {
		delete lextable.table;
		lextable.maxsize = 0;
		lextable.size = 0;
	}
}