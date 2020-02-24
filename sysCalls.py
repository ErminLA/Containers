#!/bin/python3.6

import os, sys, stat
import time

while True:
    os.chmod("/home/cloud_user/test_file.txt", stat.S_IXUSR)
    f = open("/home/cloud_user/test_file.txt", "w")
    f.write("BLABLABLABLABLABLABLA")
    f.close()
    time.sleep(1)
