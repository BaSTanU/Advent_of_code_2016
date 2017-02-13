run: build
	@./part1.exe
	@./part2.exe

build: clean part1 part2

part1: part1.cpp
	@g++ part1.cpp -o part1.exe

part2: part2.cpp
	@g++ part2.cpp -o part2.exe

clean:
	@rm -f *.exe
