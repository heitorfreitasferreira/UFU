from abc import ABC, abstractmethod

        
class IVisitorShape(ABC):
    @abstractmethod
    def visitCircle(self, element)->str:
        raise(NotImplementedError)
    @abstractmethod
    def visitSquare(self, element)->str:
        raise(NotImplementedError)
    

class Shape(ABC):
    @abstractmethod
    def area(self):
        raise NotImplementedError

    @abstractmethod
    def visit(self, visitor: IVisitorShape)->str:
        raise NotImplementedError


class Circle(Shape):
    x: int
    y: int
    radius: int
    def __init__(self, radius, x, y):
        self.radius = radius
        self.x = x
        self.y = y

    def area(self):
        return 3.14 * self.radius * self.radius
    def visit(self, visitor: IVisitorShape)->str:
        return visitor.visitCircle(self)

class Square(Shape):
    x: int
    y: int
    side: int
    def __init__(self, side, x, y):
        self.side = side
        self.x = x
        self.y = y
    def area(self):
        return self.side * self.side
    def visit(self, visitor: IVisitorShape)->str:
        return visitor.visitSquare(self)

class JSONVisitor(IVisitorShape):
    def visitCircle(self, element: Circle)->str:
        return f"{{\"type\": \"{type(element).__name__}\", \"radius\": {element.radius}, \"x\": {element.x}, \"y\": {element.y}}}"

    def visitSquare(self, element: Square)->str:
        return f"{{\"type\": \"{type(element).__name__}\", \"side\": {element.side}, \"x\": {element.x}, \"y\": {element.y}}}"


class XMLVisitor(IVisitorShape):
    def visitCircle(self, element: Circle)->str:
        return f"<{type(element).__name__} radius=\"{str(element.radius)}\" x=\"{str(element.x)}\" y=\"{str(element.y)}\"/>"
    def visitSquare(self, element: Square)->str:
        return f"<{type(element).__name__} side=\"{str(element.side)}\" x=\"{str(element.x)}\" y=\"{str(element.y)}\"/>"

json = JSONVisitor()
xml = XMLVisitor()
shapes = [Circle(1, 2, 3), Square(4, 5, 6)]

for shape in shapes:
    print(shape.visit(json))
    print(shape.visit(xml))