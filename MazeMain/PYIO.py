import pandas as pd

class PYIO(object):

    def __init__(self, _file_addr):

        self.itr = 0

        with open(_file_addr, 'r') as fp:
            data = fp.read()
            data = data.split(' ')
            self.database = pd.Series(data)


    def readInt(self):

        if (not(self.__isAvailable(self.itr))):
            print("END OF FILE!")
            return -1
        else:
            ret = self.__getInt()
            return ret



    def readPair(self):

        if (not(self.__isAvailable(self.itr + 1))):
            print("END OF FILE!")
            return -1, -1
        else:
            ret1 = self.__getInt()
            ret2 = self.__getInt()
            return ret1, ret2


    def readTriple(self):

        if (not(self.__isAvailable(self.itr + 2))):
            print("END OF FILE!")
            return -1, -1, -1
        else:
            ret1 = self.__getInt()
            ret2 = self.__getInt()
            ret3 = self.__getInt()
            return ret1, ret2, ret3


    def __isAvailable(self, axis):

        if (axis < self.database.size):
            return True
        else:
            return False


    def __getInt(self):

        ret = int(self.database[self.itr])
        self.__moveNext()
        return ret


    def __moveNext(self):

        self.itr = self.itr + 1