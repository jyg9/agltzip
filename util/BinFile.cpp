#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

unsigned long get_file_size(const char *path)
{
	unsigned long filesize = -1;
	struct stat statbuff;
	if(stat(path, &statbuff) < 0){
		return filesize;
	}else{
		filesize = statbuff.st_size;
	}
	return filesize;
}

unsigned char *LoadBinFile(const char *fname, unsigned *size)
{
	*size = 0;
	int hf = open(fname, O_RDONLY);
	if (hf<0)
		return 0;
	//*size = filelength(hf);
	*size = get_file_size(fname);
	unsigned char *buf = new unsigned char[*size];
	if (read(hf, buf, *size)!=*size)
	{
		delete buf;
		*size = 0;
		close(hf);
		return 0;
	}
	close(hf);
	return buf;
}

bool SaveBinFile(const char *fname, const void *data, unsigned size)
{
	int hf = open(fname, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP| S_IWGRP | S_IROTH);
	if (hf<0)
		return false;
	if (write(hf, data, size)!=size)
	{
		close(hf);
		return false;
	}
	close(hf);
	return true;
}
