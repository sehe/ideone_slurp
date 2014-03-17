// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0.01
// date:	2012-10-16 11:24:45
// status:	0
// result:	15
// memory:	1812
// signal:	0
// public:	true
// ------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

const char* getfield(char* line, int num)
{
	const char* tok;
	for (tok = strtok(line, ";");
			tok && *tok;
			tok = strtok(NULL, ";\n"))
	{
		if (!--num)
			return tok;
	}
	return NULL;
}

int main()
{
	char line[1024];
    while (fgets(line, 1024, stdin))
	{
		char* tmp = strdup(line);
		printf("Field 3 would be %s\n", getfield(tmp, 3));
		// NOTE strtok clobbers tmp
		free(tmp);
	}
}

// ------------------------------------------------
#if 0 // stdin
lp;imie;nazwisko;ulica;numer;kod;miejscowosc;telefon;email;data_ur
1;Jan;Kowalski;ul. Nowa;1a;11-234;Budry;123-123-456;jan@go.xxx;1980.05.13
2;Jerzy;Nowak;ul. Konopnicka;13a/3;00-900;Lichowice;(55)333-44-55;jer@wu.to;1990.03.23
#endif
#if 0 // stdout
Field 3 would be nazwisko
Field 3 would be Kowalski
Field 3 would be Nowak

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
