class YamsException(Exception):
    message = None
    code = -1

    def __init__(self, message, code):
        if type(message) is str:
            self.message = message
        else:
            raise TypeError("Message variable is not str")
        if type(code) is int:
            self.code = code
        else:
            raise TypeError("Code variable is not int")

    def what(self):
        print(self.message)
        exit(self.code)

class BadCombination(YamsException):
    def __init__(self, message, code):
        YamsException.__init__(message, code)

class BadType(YamsException):
    def __init__(self, message, code):
        YamsException.__init__(message, code)

class OutOfRange(YamsException):
    def __init__(self, message, code):
        YamsException.__init__(message, code)