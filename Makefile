all : unjzp packjzp
unjzp : unjzp.o jzp.o CBitReader.o COutBuffer.o BinFile.o
	g++ -o unjzp unjzp.o jzp.o CBitReader.o COutBuffer.o BinFile.o
unjzp.o : 
	g++ -c unjzp.cpp -I ./
jzp.o : 
	g++ -c jzp.cpp
CBitReader.o : 
	g++ -c CBitReader.cpp
COutBuffer.o : 
	g++ -c COutBuffer.cpp
BinFile.o : 
	g++ -c ./util/BinFile.cpp

packjzp : packjzp.o CBitWriter.o
	g++ -o packjzp packjzp.o jzp.o CBitWriter.o BinFile.o
packjzp.o :
	g++ -c packjzp.cpp -I ./
CBitWriter.o:
	g++ -c CBitWriter.cpp
clean :
	rm *.o
	rm packjzp
	rm unjzp
