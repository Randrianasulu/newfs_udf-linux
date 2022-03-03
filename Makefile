CFLAGS=`pkg-config --cflags libbsd-overlay`
LDFLAGS=`pkg-config --libs libbsd-overlay`
all:
	gcc *.c $(LDFLAGS) $(CFLAGS) -o newfs_udf
