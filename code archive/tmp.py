from os import system

while 1==1:
   system('./tmp.exe > in && ./TIOJ\ 1910.exe < in > out1 && ./tmp2.exe < in > out2')
   if system('diff out1 out2'):
       break
