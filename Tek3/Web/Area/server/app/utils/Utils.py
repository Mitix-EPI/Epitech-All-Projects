import random
import string

class Utils():
    @staticmethod
    def get_random_string(length):
        return ''.join(random.choice(string.ascii_letters) for i in range(length))