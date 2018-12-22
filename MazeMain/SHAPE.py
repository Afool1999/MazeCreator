class SHAPE(object):

    def __init__(self, R, G, B):

        self.color = (R, G, B)


    def setColor(self, R, G, B):

        self.color = (R, G, B)


EMPTY = SHAPE(0, 0, 0)