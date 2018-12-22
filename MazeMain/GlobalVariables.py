from PYIO import PYIO as io

class GlobalVariables:

    def __init__(self):

        self.initGL()


    def initGL(self):

        self._FILE_ADDR = 'data.in'
        self.file = io(self._FILE_ADDR)

        self._PIX_HEIGHT = 11

        self._CLOCK_TIME = 60

        self._WIDTH = 31 * 2 + 1
        self._HEIGHT = 21 * 2 + 1
        self._TRIES = 100

        self._BG_COLOR = (45, 45, 42)

        self._CANVAS_WIDTH = self._WIDTH * self._PIX_HEIGHT
        self._CANVAS_HEIGHT= self._HEIGHT * self._PIX_HEIGHT

GL = GlobalVariables()