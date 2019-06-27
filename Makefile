INCLDIR=.

LIBDIR1=.
LIBDIR2=.


WX_CONFIG=/usr/bin/wx-config


WXCFLAGS=$(shell wx-config --cppflags)  -std=c++11  -std=c++0x
WXLIBFLAGS=$(shell wx-config --libs std)


CFLAGS=$(WXCFLAGS) -I$(INCLDIR) -I.

LIBS=$(WXLIBFLAGS) -L$(LIBDIR1) -L$(LIBDIR2)  -lm 


main:	main.o V01.o V03.o V05.o V09.o
	g++ -o main main.o V01.o V03.o V05.o V09.o  $(LIBS)

main.o:	main.C
	g++ -c $(CFLAGS) main.C


prakAufg03Main:	prakAufg03Main.o PrakAufg03.o
	g++ -o prakAufg03Main prakAufg03Main.o PrakAufg03.o $(LIBS)

prakAufg03Main.o:	prakAufg03Main.C
	g++ -c $(CFLAGS) -DUNIX -D_REENTRANT  prakAufg03Main.C

PrakAufg03.o:	PrakAufg03.H PrakAufg03.C	
	g++ -c $(CFLAGS) -DUNIX -D_REENTRANT PrakAufg03.C

V01.o:	V01.C V01.H
	g++ -c $(CFLAGS) V01.C

V03.o:	V03.C V03.H
	g++ -c $(CFLAGS) V03.C

V05.o:	V05.C V05.H
	g++ -c $(CFLAGS) V05.C

V09.o:	V09.C V09.H
	g++ -c $(CFLAGS) V09.C

runMain:	main
	./main


clean:
	rm  *.o  main prakAufg03Main

