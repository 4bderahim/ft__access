#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define FF_OK  0
#define XX_OK  S_IXGRP           
#define WW_OK  S_IWGRP          
#define RR_OK  S_IRGRP   
