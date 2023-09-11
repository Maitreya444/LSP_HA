#First Make File

all: 
	@gcc Demo.c -o Myexe

run:
	@./Myexe ${Name}

clean:
	@rm Myexe

usage:
	@echo "use run target to execute the code"
