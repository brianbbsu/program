import os

for i in range(1,10000000):
    os.system("echo '{}' | ./tmp3.exe > out1".format(i))
    os.system("echo '{}' | ./tmp2.exe > out2".format(i))
    if os.system("diff -q out1 out2"):
        print "ERROR!!!!"
        exit(1)
    print i

print "OK!!"
