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
        self.tboard.start()

        self.resize(GL._CANVAS_WIDTH, GL._CANVAS_HEIGHT)
        self.center()
        self.setWindowTitle('Tetris')        
        self.show()

        self.setFixedSize(self.tboard.width(),self.tboard.height())


    def center(self):

        screen = QDesktopWidget().screenGeometry()
        size = self.geometry()
        self.move((screen.width() - size.width()) / 2,
         (screen.height() - size.height()) / 2)



if __name__ == '__main__':

    os.system('MazeCreator.exe' + ' ' + str(GL._WIDTH)
              + ' ' + str(GL._HEIGHT) + ' ' + str(GL._TRIES))
    GL.initGL()

    app = QApplication([])
    maze = mazeMain()
    sys.exit(app.exec_())

