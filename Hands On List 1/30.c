/*
============================================================================
Name : 30.c
Author : Aashish Vaswani
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

void initialize_daemon() {
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    for (int fd = sysconf(_SC_OPEN_MAX); fd >= 0; fd--) {
        close(fd);
    }
}

void execute_script_at_schedule(const char *script_file, int scheduled_hour, int scheduled_minute) {
    time_t current_time;
    struct tm *time_info;

    while (1) {
        current_time = time(NULL);
        time_info = localtime(&current_time);

        if (time_info->tm_hour == scheduled_hour && time_info->tm_min == scheduled_minute) {
            if (system(script_file) == -1) {
                perror("Script execution error");
            }
            break;
        }

        sleep(60);
    }
}

int main() {
    const char *script_file = "./test_script.sh";
    int scheduled_hour = 10;
    int scheduled_minute = 25;

    initialize_daemon();

    execute_script_at_schedule(script_file, scheduled_hour, scheduled_minute);

    return 0;
}

