#include <seccomp.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdlib>
#include <errno.h>
#include <cstdlib>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void writeToLog(std::string msg) {
        std::fstream ourFile;
        ourFile.open("Log.log", std::ios::out | std::ios::app);
        ourFile << msg;
        ourFile.close();
}

int main(int argc, char *argv[]) {

        //scmp_filter_ctx ctx;

        std::string mode = argv[1];
        /*if(mode.compare("ALLOW")) {
                ctx = seccomp_init(SCMP_ACT_ALLOW);
        } else if(mode.compare("KILL")) {
                ctx = seccomp_init(SCMP_ACT_KILL);
        } else {
                return -1;
        }

        if(ctx == NULL) {
                std::cout << "CTX Fail!!!" << std::endl;
                return -1;
        }

        seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigreturn), 0);
        seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0);
        seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0);
        seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);
        seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0);
        seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 0);
        seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(close), 0);
        seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(chmod), 0);

        seccomp_load(ctx);
        */

        unsigned int microseconds = 2000000;
        while(true) {
                srand (time(NULL));
                switch(rand() % 9){
                        case 1:
                                chmod("our_file.txt", S_IRUSR|S_IRGRP|S_IROTH);
                                writeToLog("Case 1 - File Permissions: S_IRUSR|S_IRGRP|S_IROTH\n");
                                break;
                        case 2:
                                chmod("our_file.txt", S_IWUSR|S_IWGRP|S_IWOTH);
                                writeToLog("Case 2 - File Permissions: S_IWUSR|S_IWGRP|S_IWOTH\n");
                                break;
                        case 3:
                                chmod("our_file.txt", S_IXUSR|S_IXGRP|S_IXOTH);
                                writeToLog("Case 3 - File Permissions: S_IXUSR|S_IXGRP|S_IXOTH\n");
                                break;
                        case 4:
                                chmod("our_file.txt", S_IRWXU|S_IRGRP|S_IROTH);
                                writeToLog("Case 4 - File Permissions: S_IRWXU|S_IRGRP|S_IROTH\n");
                                break;
                        case 5:
                                chmod("our_file.txt", S_IRUSR|S_IRWXG|S_IROTH);
                                writeToLog("Case 5 - File Permissions: S_IRUSR|S_IRWXG|S_IROTH\n");
                                break;
                        case 6:
                                chmod("our_file.txt", S_IRUSR|S_IRGRP|S_IRWXO);
                                writeToLog("Case 6 - File Permissions: S_IRUSR|S_IRGRP|S_IRWXO\n");
                                break;
                        case 7:
                                chmod("our_file.txt", S_IRUSR|S_IWGRP|S_IXOTH);
                                writeToLog("Case 7 - File Permissions: S_IRUSR|S_IWGRP|S_IXOTH\n");
                                break;
                        case 8:
                                chmod("our_file.txt", S_IXUSR|S_IWGRP|S_IROTH);
                                writeToLog("Case 8 - File Permissions: S_IXUSR|S_IWGRP|S_IROTH\n");
                                break;
                        case 9:
                                chmod("our_file.txt", S_IRUSR|S_IRGRP|S_IWOTH);
                                writeToLog("Case 9 - File Permissions: S_IRUSR|S_IRGRP|S_IWOTH\n");
                                break;
                }
                usleep(microseconds);
        }

        return 0;
}
