from PyQt5.QtWidgets import QFrame
from PyQt5.QtCore import Qt, QBasicTimer
from PyQt5.QtGui import QPainter, QColor 
import sys, random, os

from GlobalVariables import GL
from GlobalVariables import GlobalVariables as GLOB
from SHAPE import SHAPE as Shape
import SHAPE


class BOARD(QFrame):

    def __init__(self, parent):

        super().__init__(parent)
        self.initBoard()


    def initBoard(self):

        self.boardWidth = GL._WIDTH
        self.boardHeight = GL._HEIGHT

        self.timer = QBasicTimer()
        self.board = []

        self.setFocusPolicy(Qt.StrongFocus)

        for i in range(self.boardWidth * self.boardHeight):
            self.board.append(Shape(0, 0, 0))


    def clearBoard(self):

        for i in range(self.boardHeight):
            for j in range(self.boardWidth):
                self.setShapeAt(i, j, (0, 0, 0))

        self.update()


    def readBoard(self):
        
        for i in range(self.boardHeight):
            for j in range(self.boardWidth):

                color = GL.file.readTriple()

                if (color == (-1, -1, -1)):
                    self.timer.stop()
                    return
                else:
                    self.setShapeAt(i, j, color)
                    

    def start(self):

        self.timer.start(GL._CLOCK_TIME, self)


    def paintEvent(self, event):

        painter = QPainter(self)
        rect = self.contentsRect()

        painter.setBrush(QColor(*GL._BG_COLOR))
        painter.drawRect(self.rect())

        boardTop = rect.bottom() - self.boardHeight * self.squareHeight()


        for i in range(self.boardHeight):
            for j in range(self.boardWidth):

                shape = self.shapeAt(i, j)
                
                if (shape.color != (0, 0, 0)):
                    self.drawSquare(painter,
                        rect.left() + j * self.squareWidth(),
                        boardTop + i * self.squareHeight(), shape)


    def timerEvent(self, event):

        if event.timerId() == self.timer.timerId():

            self.readBoard()

        else:
            super(Board, self).timerEvent(event)

        self.update()


    def mousePressEvent(self, event):

        os.system('MazeCreator.exe' + ' ' + str(GL._WIDTH)
              + ' ' + str(GL._HEIGHT) + ' ' + str(GL._TRIES))
        GL.initGL()
        self.clearBoard()
        self.timer.start(GL._CLOCK_TIME, self)


    def squareWidth(self):

        return self.contentsRect().width() // self.boardWidth


    def squareHeight(self):

        return self.contentsRect().height() // self.boardHeight


    def shapeAt(self, x, y):

        return self.board[(x * self.boardWidth) + y]


    def setShapeAt(self, x, y, color):

        self.board[(x * self.boardWidth) + y].setColor(*color)


    def drawSquare(self, painter, x, y, shape):      

        print("block ({%d},{%d}) formed.\n" % (x, y))

        color = QColor(*shape.color)
        painter.fillRect(x + 1, y + 1, self.squareWidth() - 2, 
            self.squareHeight() - 2, color)

        painter.setPen(color.lighter())
        painter.drawLine(x, y + self.squareHeight() - 1, x, y)
        painter.drawLine(x, y, x + self.squareWidth() - 1, y)

        painter.setPen(color.darker())
        painter.drawLine(x + 1, y + self.squareHeight() - 1,
            x + self.squareWidth() - 1, y + self.squareHeight() - 1)
        painter.drawLine(x + self.squareWidth() - 1, 
            y + self.squareHeight() - 1, x + self.squareWidth() - 1, y + 1)
