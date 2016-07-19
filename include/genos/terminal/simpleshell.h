#ifndef GENOS_SIMPLE_SHELL_H
#define GENOS_SIMPLE_SHELL_H

#include <gxx/container/dictionary.h>
#include <genos/sigslot/delegate.h>
#include <genos/datastruct/argvc.h>
#include "gxx/string.h"

class SShell {
	dictionary<const char*, delegate<int, int, char**>> dict;

public:
	static constexpr uint8_t RetCodeOK = 0;
	static constexpr uint8_t FunctionNotExist = -1;
	static constexpr uint8_t WrongArgsTotal = -3;
	static constexpr uint8_t WrongArgsData = -4;

	SShell() : dict() {};

	void add(const char* name, delegate<int, int, char**> dlg) {
		dict.insert(name, dlg);
	};

	int execute(char* str) {
		argvc_t argvc;
		
		char* v[10];

		argvc.v = v;
		argvc.internal_split(str);

		delegate<int,int,char**> ref;
		auto retcode = dict.get(ref, argvc.v[0]);
		if (retcode) return FunctionNotExist;
		
		return ref(argvc.c, argvc.v);
	}

	gxx::string strerr(int retcode) {
		switch (retcode) {
			case RetCodeOK: 
				return gxx::string("RetCodeOK");
			case FunctionNotExist: 
				return gxx::string("FunctionNotExist");
			case WrongArgsTotal: 
				return gxx::string("WrongArgsTotal");
			case WrongArgsData: 
				return gxx::string("WrongArgsData");
			default: 
				return gxx::string("UnregistredRetCode ") + retcode;
		};
	};
};

#endif