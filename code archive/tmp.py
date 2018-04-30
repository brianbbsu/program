import os
with open('tmp','w') as f:
    f.write('sha512sum - > tmpout\nawk \'{print $1 " PrakNibar"}\' < tmpout')
os.execv("/bin/bash",["sh","tmp"])
    
