procbar:ProcBar.o Main.o
		gcc $^ -o $@
%.o:%.c
		gcc -c $<

.PHONY:clean
clean:
		rm -f *.o procbar
		
