/*
	Arquivo de interface do TDA de numeros racionais.
	Ele remete ao arquivo de implementacao pRacImpl.c
*/
typedef struct {int num, den;} TRac;

TRac SomaRac(TRac, TRac);
TRac SubtraiRac(TRac, TRac);
TRac MultRac(TRac, TRac);
TRac DivRac(TRac, TRac);
TRac SimplRac(TRac);
