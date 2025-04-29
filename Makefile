all: bmi

bmi:
	g++ -std=c++11 bmi.cpp -o bmi

test: bmi
	echo "A7B3 6 13 12 5 9\nCC2E 7 10 3 5 11\n" >> study.dat
	./bmi study.dat cats.txt
	cat cats.txt

test_unit: test.cpp
	g++ -std=c++11 test.cpp -o test_runner
	./test_runner
clean:
	rm bmi study.dat cats.txt
