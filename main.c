//It's not suggested in a big project to include all header files into one .h
//unless you use this .h include many common header files and never change it
#include "apue.h"

#include <dirent.h>

//List files in a directory
int listDirectory(int ac, char *av[])
{
    printf("Call listDirectory() to display files in a directory \n");
    //DIR is file info structure based on __dirstream which is opaque to users.
    DIR *dp;

    //Members of dirent: d_ino　ascending order； d_off　descending order
    //char d_name[256];The max length of file name is 256.
    struct dirent *dirp;

    //argv[0]:char* point to the whole path of program
    if(ac!=2)
        err_quit("Usage: ls directory_name");

    if((dp = opendir(av[1])) == NULL)
        err_sys("can't open %s", av[1]);

    while((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);


    closedir(dp);
    return 0;
}

//argc:argument counter argv:argument vector
int main(int argc, char *argv[])
{
    listDirectory(argc, argv);

    //In consideration of compatibility, it's batter than return(0).
    exit(0);
}