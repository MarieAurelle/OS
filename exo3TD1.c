#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	
	int fp = open("toto.txt",O_RDONLY);
	
	
	return 0;
}
