COMPILER = gcc
FILESYSTEM_FILES = ssfs.c

build: $(FILESYSTEM_FILES)
	$(COMPILER) $(FILESYSTEM_FILES) -o ssfs `pkg-config fuse --cflags --libs`
	echo 'To Mount: ./ssfs -f [mount point]'
	echo 'To unmount: go to main directory and type: fusermount -u <Dir Name>'

clean:
	rm ssfs