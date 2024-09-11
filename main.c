#include "header.h"

int	matched(char *neadle, char *str)
{
	int	i;

	i = 0;
	if (!str || !neadle)
		return (0);
	if (!(*str) || !(*neadle))
		return (0);
	while (str[i])
	{
		if (str[i] != neadle[i])
			return (0);
		i++;
	}
	if (neadle[i] != 0)
		return (0);
	return (1);
}
int get_file(char *file_path)
{
    int i;

    i = strlen(file_path) -1;
    while (i >= 0)
    {
        if (file_path[i] == '/')
            {
                return (i);
            }
        i--;
    }
    return (-1);
}
int file_exists(char *file_path, DIR *dir)
{
    /*
    check file existence bye reading the directory
    and check for a file match!
    */
    struct dirent  *dir_;
    dir_ = readdir(dir);
    while (dir_)
    {   
        if (matched(dir_->d_name, file_path) )
            return (1);
        dir_ = readdir(dir);
    }
    return (0);
}
void free_dir(DIR *dir)
{
    close(dir->__dd_fd);
    free(dir->__dd_buf);
    free(dir);
}
int ft__access(char *file_path,int check)
{

    DIR *dir;
    struct stat filestat;
    int file_index;

    dir = opendir(file_path);
    if (dir != NULL) // its a directory!   
       {
        free_dir(dir);
        return (-1);
       }
    file_index = get_file(file_path);// get index to the last '/'
    if (file_index ==  -1)// invalid path
        return (-1);
    file_path[file_index] = 0;
    if ((dir = opendir(file_path)) == NULL)// invalid path
        return (-1);
    if (!file_exists(file_path+file_index+1, dir))// file exists in directory
        return (free_dir(dir), -1);
    file_path[file_index] = '/';// file path as it was!
    if (stat(file_path ,&filestat) == -1)
        return (free_dir(dir), -1);
    if (check == FF_OK)
        return (free_dir(dir), 0);
    if (check == RR_OK)
        return (
            (filestat.st_mode & S_IROTH) ? (free_dir(dir), 0) : (free_dir(dir),-1));
    if (check == XX_OK)
        return (filestat.st_mode & S_IXGRP ? (free_dir(dir), 0) : (free_dir(dir),-1));
    if (check == WW_OK)
        return (filestat.st_mode & S_IWGRP ? (free_dir(dir), 0) : (free_dir(dir),-1));
    return (-1);
}
