CC = g++
CFLAGS = -Wall -g
SRCS = main.cpp Performance.cpp Example.cpp DataSet.cpp Cond.cpp Rule.cpp RuleSet.cpp
OBJS = ${SRCS:.cpp=.o}
LIBS = -lm

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(INCL) $(OBJS) $(LIBS)

$(OBJS):
	$(CC) $(INCL) $(CFLAGS) -c $*.cpp

depend:
	$(CC) $(INCL) -MM $(SRCS) > Makefile.dep

clean:
	rm -f $(OBJS) a.out core

Makefile.dep:
	touch Makefile.dep

include Makefile.dep

