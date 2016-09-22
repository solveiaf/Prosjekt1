from numpy import *
from matplotlib.pyplot import *


f = open('n10c.txt','r')

lines = f.readlines()[1:]
f.close()
Types = [line.split() for line in lines[:-1]]
x10 = [float(Type[0]) for Type in Types]
y10 = [float(Type[1]) for Type in Types]
x10 = asarray(x10)
y10 = asarray(y10)
f = open('n100c.txt','r')

lines = f.readlines()[1:]
f.close()
Types = [line.split() for line in lines[:-1]]
x100 = [float(Type[0]) for Type in Types]
y100 = [float(Type[1]) for Type in Types]
x100 = asarray(x100)
y100 = asarray(y100)
f = open('n1000c.txt','r')

lines = f.readlines()[1:]
f.close()
Types = [line.split() for line in lines[:-1]]
x1000 = [float(Type[0]) for Type in Types]
y1000 = [float(Type[1]) for Type in Types]
x1000 = asarray(x1000)
y1000 = asarray(y1000)
f = open('n100000c.txt','r')

lines = f.readlines()[1:]
f.close()
Types = [line.split() for line in lines[:-1]]
x100000 = [float(Type[0]) for Type in Types]
y100000 = [float(Type[1]) for Type in Types]
x100000 = asarray(x100000)
y100000 = asarray(y100000)


u10 = 1-(1-exp(-10))*x10-exp(-10*x10)

u100 = 1-(1-exp(-10))*x100-exp(-10*x100)

u1000 = 1-(1-exp(-10))*x1000-exp(-10*x1000)

u100000 = 1-(1-exp(-10))*x100000-exp(-10*x100000)

error10 = log10(absolute((y10 - u10)/u10))

error100 = log10(absolute((y100 - u100)/u100))

error1000 = log10(absolute((y1000 - u1000)/u1000))

error100000 = log10(absolute((y100000 - u100000)/u100000))
print u10
plot(x100000,error100000,'o')
ylabel('Relative error in log10')
xlabel('x_i')
title('n100000')

show()

         






