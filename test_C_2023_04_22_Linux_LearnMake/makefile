mybin_d:main.o mytest.o
		gcc $^ -o $@ -g
%.o:%.c
	gcc -c $< -g

.PHONY:clean
clean:
		rm -f *.o mybin_d

