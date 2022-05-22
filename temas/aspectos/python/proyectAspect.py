
import aspectlib

class Point:
    _x = 0
    _y = 0

    def getX(self):
        return self._x
    
    def getY(self):
        return self._y

    def setX(self,x):
        self._x = x

    def setY(self,y):
        self._y = y

@aspectlib.Aspect
def PointValidation(self,n):
    if(n > 0):
        yield
        print("Coordenada X recogida con exito")
    else:
        yield
        print("Coordenada X negativa")

aspectlib.weave(Point.setX or Point.setY,PointValidation)

P = Point()
P.setX(-8)
x = P.getX()
print(x)


# EJECUCIÓN #
#P = Point()
#P.setX(4)
#P.setY(2)