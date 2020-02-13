#include <seccomp.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdlib>
#include <errno.h>

#include <sys/types.h>
#include <fcntl.h>

int main() {
        printf("Here you can do whatever you want!!!\n");

        scmp_filter_ctx ctx;
        ctx = seccomp_init(SCMP_ACT_KILL);

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


        std::cout << "WRITE TO FILE" << std::endl;
        std::fstream ourFile;
        ourFile.open("our_file.txt", std::ios::out);
        ourFile << "Random stuff to fill the file with.\nIs this really random? Can we really produce anything random?";
        ourFile.close();
        std::cout << "DONE" << std::endl;


        std::cout << "File is not only for reading" << std::endl;
        //Add execute permissions to a file
        chmod("our_file.txt", S_IRUSR|S_IRGRP|S_IROTH);


        std::cout << "File contents:" << std::endl;
        ourFile.open("our_file.txt", std::ios::in);
        std::string line;
        while(getline(ourFile, line)) {
                std::cout << line << "\n";
        }
        ourFile.close();
        std::cout << std::endl;

        //Delete file
        //int ret = remove("test_file.txt");

        return 0;
}
