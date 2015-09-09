CC=g++
LIB=
LIBPATH=
INCLUDE= 
CXXFLAGS= -g -Wall -O2  $(INCLUDE) -fPIC
INSTALLPATH=../../lib
SOLIB=libjson.so
STATICLIB=libjson.a

OBJS=json_reader.o json_value.o json_writer.o

DLEXT=so

all: static shared test

static: libjson.a

shared: libjson.$(DLEXT)

libjson.a: $(OBJS)
	echo "  AR    $@"
	ar r $@ $(OBJS)

libjson.so: $(OBJS)
	echo "  LD    $@"
	$(CC) -fPIC -shared -Wl,-soname,$@ -o $@ $(OBJS)
test: jsoncpptest4.o $(SOLIB)
	$(CC)  -g -Wall -O2 -o test jsoncpptest4.o  -ljson -L./ -Wl,-rpath,$(RUNLIBPATH)
jsoncpptest4.o:jsoncpptest4.cpp 
	$(CC) -g -Wall  -O2 -c -o jsoncpptest4.o jsoncpptest4.cpp 
install:
	rm -rf $(INSTALLPATH)/$(STATICLIB)
	cp -r $(STATICLIB) $(INSTALLPATH)/$(STATICLIB)
	rm -rf $(INSTALLPATH)/$(SOLIB)
	cp -r $(SOLIB) $(INSTALLPATH)/$(SOLIB)
clean:
	rm -f *.o libjson.* test
