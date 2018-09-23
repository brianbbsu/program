import os


def clr(s):
    s = s.replace("\n","")
    s = s.replace("\r","")
    s = s.replace(" ","")
    return s

with open("Template.cpp",'r') as f:
    temp = clr(f.read())

lis = os.listdir(".")

for nm in lis:
    if nm == "Template.cpp" or not os.path.isfile(nm):
        continue
    if nm.endswith(".exe"):
        print nm
        os.remove(nm)
        continue
    with open(nm,"r") as f:
        s = clr(f.read())
    if s == temp:
        print nm
        os.remove(nm)
