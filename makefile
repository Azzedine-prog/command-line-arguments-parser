CC=gcc
FLAG=-Wall
parser.exe:
	$(CC) $(FLAG) parser.c test.c -o parser.exe
clean:
	 rm -f parser-project.exe
run:parser.exe
	parser.exe