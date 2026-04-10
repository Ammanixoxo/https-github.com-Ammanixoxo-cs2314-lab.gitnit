CC = gcc
CFLAGS = -std=c11 -Wall -Wextra  -O2

all: q1 q2

q1: Question1/student.c Question1/tests.c
	$(CC) $(CFLAGS) -o Question1/q1_test Question1/student.c Question1/tests.c

q2: Question2/student.c Question2/tests.c
	$(CC) $(CFLAGS) -o Question2/q2_test Question2/student.c Question2/tests.c

# New commands (what you want)
run1: q1
	./Question1/q1_test

run2: q2
	./Question2/q2_test

# Keep full test option
test: q1 q2
	./Question1/q1_test
	./Question2/q2_test

clean:
	rm -f Question1/q1_test Question2/q2_test