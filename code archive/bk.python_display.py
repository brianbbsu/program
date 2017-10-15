from visual import *

def RGB(r, g, b): return (r / 255.0, g / 255.0, b / 255.0)

cor1 = vector(0, 0, -1.5)
cor2 = vector(50, 100, 1.5)

scene = display(x = 0, y = 0, width = 540, height = 720, center = (cor1 + cor2) * 0.5, background = RGB(232, 255, 232))

colors = [RGB(0, 0, 0), RGB(128, 128, 128), RGB(0, 0, 128), RGB(128, 128, 192), RGB(128, 0, 0), RGB(255, 255, 255), 
          RGB(0, 255, 0), RGB(255, 255, 0), RGB(0, 0, 255), RGB(255, 0, 0), RGB(255, 128, 0), RGB(0, 255, 255), 
          RGB(160, 160, 0), RGB(255, 192, 0), RGB(255, 128, 128), RGB(0, 64, 192), RGB(0, 0, 192)]

File = open('charles_output.txt', 'r')

def getfloat(): return float(File.readline())
def getint(): return int(File.readline())

curve(pos = [(0, 0), (0, 100), (50, 100), (50, 0), (0, 0)], color = RGB(255, 0, 0))

boxes = []
balls = []

def clear(t):
    while len(t) > 0:
        t[-1].visible = False
        del t[-1]
def tin(x, y): 
    #return True
    return not((x > cor2.y + 1 or x < -1) or (y > cor2.x + 1 or y < -1))

ct = 0
start = 0

while True:
    t = File.readline()
    if t == '': break
    clear(boxes)
    clear(balls)
        
    t = int(t)
    for i in range(t):
        x, y, a, b = getfloat(), getfloat(), getfloat(), getfloat()
        if tin(x, y) and ct >= start: boxes.append(box(pos = vector(y, cor2.y - x, 0), length = b, height = a, width = .01, color = colors[4]))
    t = getint()
    for i in range(t):
        x, y, r, k = getfloat(), getfloat(), getfloat(), getint()
        if tin(x, y) and ct >= start: balls.append(cylinder(pos = vector(y, cor2.y - x, 0), axis = vector(0, 0, .01), radius = r, color = colors[k]))
    if ct >= start: rate(50)
    ct += 1
    if ct % 50 == 0: print ct / 50

print 'end'
while True: sleep(10)