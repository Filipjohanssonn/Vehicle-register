prog: 			main.o filhantering.o
			gcc -o program main.o filhantering.o
			

main.o:			main.c filhantering.c
			gcc -c main.c


filhantering.o:		filhantering.c filhantering.h
			gcc -c filhantering.c


clean: 
	rm *.o




prog: 			main.o drive.o list.o
			gcc -o program main.o drive.o
			

main.o:			main.c drive.c list.c
			gcc -c main.c

drive.o:		drive.c drive.h
			gcc -c filhantering.c
			
list.o:			list.c list.h
			gcc -c list.c

clean: 
	rm *.o




prog: 			main.o driv.o list.o
			gcc -o program main.o driv.o
			

main.o:			main.c driv.c list.c
			gcc -c main.c

driv.o:			driv.c driv.h
			gcc -c driv.c
			
list.o:			list.c list.h
			gcc -c list.c

clean: 
	rm *.o
