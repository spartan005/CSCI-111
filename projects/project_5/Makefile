all: cypher decypher

cypher: encrypt.o Machine.o Rotor.o
	g++ encrypt.o Machine.o Rotor.o -o cypher

decypher: decrypt.o Machine.o Rotor.o
	g++ decrypt.o Machine.o Rotor.o -o decypher

decrypt.o: decrypt.cpp Machine.h
	g++ -c decrypt.cpp

encrypt.o: encrypt.cpp Machine.h
	g++ -c encrypt.cpp

Machine.o: Machine.cpp Machine.h Rotor.h
	g++ -c Machine.cpp

Rotor.o: Rotor.cpp Rotor.h
	g++ -c Rotor.cpp

clean:
	rm *.o cypher decypher
