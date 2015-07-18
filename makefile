CC = g++
FILES = Main.cpp DecodeZip.cpp ReadWriteZip.cpp Encoding.cpp
FILES_O = Encoding.o DecodeZip.o ReadWriteZip.o Main.o
OUT_EXE = jzip.exe

build: $(FILES_O)
	$(CC) -g -o $(OUT_EXE) $(FILES_O)
DecodeZip.o: DecodeZip.cpp
	$(CC) -c DecodeZip.cpp
Encoding.o: Encoding.cpp
	$(CC) -c Encoding.cpp
Main.o: Main.cpp
	$(CC) -c Main.cpp
ReadWriteZip.o: ReadWriteZip.cpp
	$(CC) -c ReadWriteZip.cpp

clean:
	rm $(FILES_O)

rebuild: clean build