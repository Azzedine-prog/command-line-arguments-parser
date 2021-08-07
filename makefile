CC=gcc
FLAG=-Wall
parser-project.exe:
	$(CC) $(FLAG) parser-project.c -o parser-project.exe
clean:
	 [ -e  parser-project.exe ] && rm -f parser-project.exe
run:parser-project.exe
	./parser-project.exe