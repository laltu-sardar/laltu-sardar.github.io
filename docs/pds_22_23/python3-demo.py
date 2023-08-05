import os

os.system("mkdir tempDir2")

print("Hello world\n")
#a =123.0
#a = input
'''
a = 5
b = 2


start = 2
end = 6
print(c[start:end],' ' ,type(a), type(b), type(c))

for x in c:
    print(x)


c=[]


for i in range(1, 10):
    print (i)

c = range(1, 10)
print(c[1], c[2])

c=[] #blank list
for i in range(5):
    inst = "give ", i, "th element: "
    a = input(inst)
    c.append(a)
    
print (c.pop())   


c = ( 112, 562, 73, 3434 , 335, 126, 740, 380)
#c.sort()
print (c)

d = (34, 45)

e = c+d
print (e)
a= []

for i in range(2):
    row = range(3)
    a.append(row)
    
print (a)

i=11
while 1:
    print (i)
    i= i+1
    if (i>25):
        break

'''

a=0

input_file = open("input_file.txt","r")

x = input_file.readlines()
#print (x)
for line in x:
    if "demo" in line:
        print (line)
    '''
    print (type(line))
    
    line = line.replace('\n', '')
    line = line.split(" ")
    print (type(line))
    print (line[2])
    '''
input_file.close()

def addition(a, b):
    if type(a) !=type([]):
        print("Errr")
        exit()
    for i in range(len(a)):
        y = a.pop()
        print (a, y)
        b.append(y  )
    
    return b    

def main():
    x = [1, 2, 3]
    y = [6, 3]

    print (addition(x,y))


if __name__=="__main__":
    main()



