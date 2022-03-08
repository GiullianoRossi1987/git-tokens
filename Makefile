
test_db: src/testdb.cpp database.o
	g++ src/testdb.cpp -o out/test_db.e -W
	out/test_db.e

database.o: src/database/Tokens.h src/database/Tokens.cpp
	g++ -S src/database/Tokens.cpp src/database/Tokens.cpp -W
