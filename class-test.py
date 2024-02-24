class A:
    def __init__(self, index):
        self.index = index

    def __add__(self, v):
        return A(self.index + v.index)

    def __repr__(self):
        return "object A: A.index = " + str(self.index)


