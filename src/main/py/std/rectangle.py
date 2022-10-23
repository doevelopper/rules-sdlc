
from polygon import Polygon

class Rectangle(Polygon):
  """
  A class to manufacture rectangle objects
  """
    # def __init__(self):
    #     Polygon.__init__(self,4)

  def __init__(self, l, w):
        self.length = l
        self.width  = w

  def __str__(self):
        return  "({0}, {1})".format(self.width, self.height)

  def perimeter(self):
        return (self.length + self.width) * 2

  def area(self):
        return self.length*self.width

class Parallelepipede(Rectangle):
    def __init__(self,length,width, hight):
        Rectangle.__init__(self,length,width)
        self.hight = hight
