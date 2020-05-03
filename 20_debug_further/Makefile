all:
	cc -o bubble_debug -g -Wall *.c *.h

debugs:
	gdb --batch --ex r --ex bt --ex q --args bubble_debug 1 82 39 44 1 2 3 4 9 8 01 10 11
