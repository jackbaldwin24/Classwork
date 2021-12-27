proj09: proj09.support.o proj09.driver.o
	gcc proj09.support.o proj09.driver.o -o proj09

proj09.support.o: proj09.support.s /user/cse320/Projects/project09.support.h
	gcc -march=native -c proj09.support.s /user/cse320/Projects.project09.support.h

proj09.driver.o: proj09.driver.c /user/cse320/Projects/project09.support.h
	gcc -Wall -c proj09.driver.c
