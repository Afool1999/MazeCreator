from PyQt5.QtWidgets import QMainWindow, QDesktopWidget, QApplication
import sys
import os

from BOARD import BOARD as Board
from GlobalVariables import GL


class mazeMain(QMainWindow):


    def __init__(self):

        super().__init__()
        self.initUI()


    def initUI(self):

        self.tboard = Board(self)
        self.setCentralWidget(self.tboard)

        self.resize(GL._CANVAS_WIDTH, GL._CANVAS_HEIGHT)
        self.center()
        self.setWindowTitle('MazeCreator')        
        self.show()

        self.setFixedSize(self.tboard.width(),self.tboard.height())


    def center(self):

        screen = QDesktopWidget().screenGeometry()
        size = self.geometry()
        self.move((screen.width() - size.width()) / 2,
         (screen.height() - size.height()) / 2)



if __name__ == '__main__':

    GL.initGL()

    app = QApplication([])
    maze = mazeMain()
    sys.exit(app.exec_())

