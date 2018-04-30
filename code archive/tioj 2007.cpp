#import<unistd.h>
main(){char*a="PrakNibar",*b="sha512sum",*c[]={b,a};symlink("input",a);execvp(b,c);}
