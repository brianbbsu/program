#!/usr/bin/env python2
import os
import subprocess

def clr(s):
    s = s.replace("\n","")
    s = s.replace("\r","")
    s = s.replace(" ","")
    return s

with open("Template.cpp",'r') as f:
    temp = clr(f.read())

lis = os.listdir(".")

for root, subdirs, files in os.walk("/home/bb/program/code archive", topdown=True):
    if root == "/home/bb/program/code archive":
        subdirs.remove("random stuff")
    for rel_nm in files:
        nm = os.path.join(root,rel_nm)
        if rel_nm == "Template.cpp" or not os.path.isfile(nm):
            continue
        process = subprocess.Popen(["file",nm], stdout=subprocess.PIPE)

        fle = process.stdout.read()
        if fle.find("ELF") != -1:
            print nm
            os.remove(nm)
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
