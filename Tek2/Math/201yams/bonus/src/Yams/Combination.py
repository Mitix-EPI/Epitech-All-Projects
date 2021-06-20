class Combination():
    def __init__(self):
        pass

    def checkThree(self, dies):
        value = 0

        for i in dies:
            if dies.count(i) >= 3:
                value = i
        return value * 3

    def checkFour(self, dies):
        value = 0

        for i in dies:
            if dies.count(i) >= 4:
                value = i
        return value * 4

    def checkYams(self, dies):
        if dies.count(dies[0]) == 5:
            return 50
        return 0

    def checkFull(self, dies):
        hasThree = False
        hasTwo = False

        for i in dies:
            if dies.count(i) == 3:
                hasThree = True
            if dies.count(i) == 2:
                hasTwo = True
        if hasThree and hasTwo:
            return 25
        return 0

    def checkSmallStraight(self, dies):
        diesCopy = dies.copy()
        numberStraight = 0
        beforeSmallest = 0

        while len(diesCopy) > 0:
            smallest = diesCopy[0]
            index = 0
            ind = 0
            for i in diesCopy:
                if ind == index:
                    ind += 1
                    continue
                if i < smallest:
                    index = ind
                    smallest = i
                ind += 1
            if beforeSmallest == 0:
                numberStraight = 1
            elif beforeSmallest + 1 == smallest:
                numberStraight += 1
            else:
                numberStraight = 1
            if numberStraight >= 4:
                break
            del diesCopy[index]
            beforeSmallest = smallest
        if numberStraight >= 4:
            return 30
        return 0

    def checkStraight(self, dies):
        diesCopy = dies.copy()
        numberStraight = 0
        beforeSmallest = 0

        while len(diesCopy) > 0:
            smallest = diesCopy[0]
            index = 0
            ind = 0
            for i in diesCopy:
                if ind == index:
                    ind += 1
                    continue
                if i < smallest:
                    index = ind
                    smallest = i
                ind += 1
            if beforeSmallest == 0:
                numberStraight = 1
            elif beforeSmallest + 1 == smallest:
                numberStraight += 1
            else:
                numberStraight = 1
            if numberStraight >= 5:
                break
            del diesCopy[index]
            beforeSmallest = smallest
        if numberStraight >= 5:
            return 40
        return 0

    @staticmethod
    def getInstance():
        return Combination()

    @staticmethod
    def checkCombination(dies, combination):
        instance = Combination.getInstance()

        if combination == "scoreboard_1":
            return dies.count(1) * 1
        elif combination == "scoreboard_2":
            return dies.count(2) * 2
        elif combination == "scoreboard_3":
            return dies.count(3) * 3
        elif combination == "scoreboard_4":
            return dies.count(4) * 4
        elif combination == "scoreboard_5":
            return dies.count(5) * 5
        elif combination == "scoreboard_6":
            return dies.count(6) * 6
        elif combination == "scoreboard_three":
            return instance.checkThree(dies)
        elif combination == "scoreboard_four":
            return instance.checkFour(dies)
        elif combination == "scoreboard_full":
            return instance.checkFull(dies)
        elif combination == "scoreboard_smallstraight":
            return instance.checkSmallStraight(dies)
        elif combination == "scoreboard_straight":
            return instance.checkStraight(dies)
        elif combination == "scoreboard_yams":
            return instance.checkYams(dies)
        elif combination == "scoreboard_luck":
            number = 0
            for i in dies:
                number += i
            return number