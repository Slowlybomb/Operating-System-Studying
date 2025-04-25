#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    FILE* file = fopen("somedata.txt", "r");
    char line[256];
    char *myfifo = "/tmp/myfifo";

    // Check if file exists
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Create the pipe (check for errors)
    if (mkfifo(myfifo, 0666) == -1) {
        perror("Error creating FIFO");
    }

    // Open FIFO for writing (keep it open)
    fd = open(myfifo, O_WRONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        fclose(file);
        return 1;
    }

    // Read file line by line and write to pipe
    while (fgets(line, sizeof(line), file)) {
        write(fd, line, strlen(line));
    }

    // Clean up resources
    close(fd);
    fclose(file);
    return 0;
}
