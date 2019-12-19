#This is the Makefile for the students project
CC = g++
CFLAGS = -g -Wall
CCLINK = $(CC)
LIBS =
OBJS = Course.o CS_Course.o EE_Course.o main.o Person.h Student.h Person.o StArray.o Person.h Student.h Student.o Person.h
RM = rm -f
# Creating the executable (students)
students: $(OBJS)
	$(CCLINK) -o students $(OBJS) $(LIBS)

# Creating object files using default rules
Course.o: Course.cpp Course.h
CS_Course.o: CS_Course.cpp CS_Course.h Course.h
EE_Course.o: EE_Course.cpp EE_Course.h Course.h
main.o: main.cpp Proj.h StArray.h Course.h CS_Course.h EE_Course.h \
 Person.h Student.h
Person.o: Person.cpp Person.h
StArray.o: StArray.cpp StArray.h Proj.h Course.h CS_Course.h EE_Course.h \
 Person.h Student.h
Student.o: Student.cpp Student.h Proj.h Course.h CS_Course.h EE_Course.h \
 Person.h
# Cleaning old files before new make
clean:
	$(RM) students screen_test *.o *.bak *~ "#"* core
