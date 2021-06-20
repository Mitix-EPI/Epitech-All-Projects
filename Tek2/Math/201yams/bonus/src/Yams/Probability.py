import math
import Exceptions.Exceptions as Crash

class YamsProbability():
    def __init__(self):
        self.functions = {
            "yams": self.calculate_yams,
            "four": self.calculate_four,
            "three": self.calculate_three,
            "pair": self.calculate_pair,
            "straight": self.calculate_straight,
        }

    def __binom(self, k, n, p):
        """binom(k,n,p): probabilité d'avoir k réussite(s) dans n évènements indépendants, chaque évènement ayant une probabilité p% de réussite"""

        if k == n:
            return p ** n
        if p == 0:
            return 0.0
        if p == 1.0:
            return 0.0
        q = 1 - p
        if k == 0:
            return q ** n
        j1 = k
        j2 = n - k
        xmin = 1.0e-200
        x = 1.0
        for i in range(0, k):
            x *= n / k
            while (x > xmin) and (j1 > 0):
                x *= p
                j1 -= 1
            while (x > xmin) and (j2 > 0):
                x *= q
                j2 -= 1
            n -= 1
            k -= 1
        return x * (p ** j1) * (q ** j2)

    def get_number_dies(self, dies, number):
        nb = 0

        for i in dies:
            if i == number:
                nb += 1
        return nb

    def calculate_yams(self, dies, number):
        nb = self.get_number_dies(dies, number)
        percent = 0.0

        if (nb == 5):
            return (100.0)
        else:
            percent = self.__binom(5 - nb, 5 - nb, 1/6)
        return round(percent * 100, 2)

    def calculate_four(self, dies, number):
        nb = self.get_number_dies(dies, number)
        percent = 0.0

        if (nb >= 4):
            return (100.0)
        else:
            for i in range(4 - nb, 5 - nb + 1):
                percent += self.__binom(i, 5 - nb, 1/6)
            return round(percent * 100, 2)

    def calculate_three(self, dies, number):
        nb = self.get_number_dies(dies, number)
        percent = 0.0

        if (nb >= 3):
            return (100.0)
        else:
            for i in range(3 - nb, 5 - nb + 1):
                percent += self.__binom(i, 5 - nb, 1/6)
            return round(percent * 100, 2)

    def calculate_pair(self, dies, number):
        nb = self.get_number_dies(dies, number)
        percent = 0.0

        if (nb >= 2):
            return (100.0)
        else:
            for i in range(2 - nb, 5 - nb + 1):
                percent += self.__binom(i, 5 - nb, 1/6)
            return round(percent * 100, 2)

    def calculate_full(self, dies, numbers):
        percent = 0.0
        if type(numbers[0]) is not int or type(numbers[1]) is not int:
            raise Crash.BadType("Values of full are not int", 5)
        nb_1 = self.get_number_dies(dies, numbers[0])
        nb_2 = self.get_number_dies(dies, numbers[1])

        if (nb_1 > 3):
            nb_1 = 3
        if (nb_2 > 2):
            nb_2 = 2

        if (nb_1 + nb_2 == 5):
            return (100.0)
        resultPair = math.factorial(5 - nb_1 - nb_2) / (math.factorial(3 - nb_2) * math.factorial((5 - nb_2 - nb_1) - (3 - nb_1)))
        resultThree = math.factorial(2 - nb_2) / (math.factorial(2 - nb_2) * math.factorial((2 - nb_2) - (2 - nb_2)))
        percent = (resultPair * resultThree) / 6 ** (5 - nb_1 - nb_2)
        return round(percent * 100, 2)

    def __finder(self, dies, num, i=0, ret=0):
        for i in range(0, 5): ret = ret + 1 if dies[i] == num else ret
        return (1 if ret > 1 else ret)

    def calculate_straight(self, dies, number):
        nb = sum([self.__finder(dies, i) for i in range(2, 7)]) if number == 6 else sum([self.__finder(dies, i) for i in range(1, 6)])
        return (100.0 if nb == 5 else round((math.factorial(5 - nb) / 6**(5 - nb)) * 100, 2))

    @staticmethod
    def getInstance():
        return YamsProbability()

    @staticmethod
    def probability(dies, name, value):
        """
        Parameters: dies, name, value
        :param dies: is all numbers of dies (list of int)
        :param name: is the combination (str)
        :param value: is the value required (int or list of int for full combination)
        """
        instance = YamsProbability.getInstance()

        if type(value) is list:
            if name != "full":
                raise Crash.BadCombination("Cannot use list of int values for others combinations than full", 1)
            return instance.calculate_full(dies, value)
        elif type(value) is int:
            if name == "full":
                raise Crash.BadCombination("Cannot use only one int value for full combination", 2)
            if name not in instance.functions.keys():
                raise Crash.BadCombination(name + " is not a good combination.", 4)
            return instance.functions.get(name)(dies, value)
        else:
            raise Crash.BadType("Bad type for value variable", 3)
        return 0.0