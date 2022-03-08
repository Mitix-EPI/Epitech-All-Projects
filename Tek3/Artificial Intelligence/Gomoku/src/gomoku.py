import random
import sys
from board import *
from engine import *

class Gomoku:

    @staticmethod
    def __flushed_print(to_print):
        print(to_print)
        sys.stdout.flush()
    
    @staticmethod
    def __read_stdin():
        return sys.stdin.readline().strip().split(" ")

    def __init__(self):
        self.__board = Board(20)
        self.__input_handler = [
            {'input': 'START', 'handler': self.__start},
            {'input': 'BEGIN', 'handler': self.__begin},
            {'input': 'END', 'handler': self.__end},
            {'input': 'INFO', 'handler': self.__info},
            {'input': 'ABOUT', 'handler': self.__about},
            {'input': 'RESTART', 'handler': self.__restart},
            {'input': 'TURN', 'handler': self.__turn},
            {'input': 'BOARD', 'handler': self.__special}
        ]
        self.__command: str = ""
        self.__current_move = None
        self.__engine = Engine(4.8, self.__board)
        self.__is_first = False
    
    def __del__(self):
        del self.__input_handler
        del self.__board
    
    def __start(self):
        if (self.__command and len(self.__command) > 1):
            size = int(self.__command[1])

            if (size >= 5 and size <= 20):
                self.__board.start(size)
                self.__engine.update_secret()
                self.__flushed_print("OK")
            else:
                self.__flushed_print("ERROR message unsupported size or other error")
            return (0)
        self.__flushed_print("ERROR message unsupported size or other error")
        return (0)

    def __begin(self):
        self.__is_first = True
        size = self.__board.size()
        self.__current_move = (int(size / 2), int(size / 2))
        self.__engine.update(self.__board.first_state(self.__current_move, 1))
        self.__flushed_print(str(self.__current_move[0]) + "," + str(self.__current_move[1]))
        return (0)
    
    def __end(self):
        return (-1)
    
    def __info(self):
        return (0)
    
    def __about(self):
        self.__flushed_print('name="I.A.R.", version="1.0", author="Juan&Rafik&Max", country="FR"')
        return (0)
    
    def __restart(self):
        self.__is_first = False
        self.__board.reset()
        self.__current_move = None
        self.__engine.reset()
        self.__flushed_print('OK')
        return (0)
    
    def __turn(self):
        if (self.__command and len(self.__command) > 1):
            coords = self.__command[1].split(",")
            self.__current_move = (int(coords[0]), int(coords[1]))
            history = self.__engine.get_states()
            if (history != [] and len(history) > 0):
                self.__engine.update(self.__board.next_state(history[-1], self.__current_move))
            else:
                self.__engine.update(self.__board.first_state(self.__current_move, 2))
            #last_state = json.loads(self.__engine.get_states()[-1])
            #panel = last_state["panel"]
            #print('\n'.join([''.join(['{:4}'.format(item) for item in row]) for row in panel]))
            #sys.stdout.flush()
            self.__ia_part()
            #last_state = json.loads(self.__engine.get_states()[-1])
            #panel = last_state["panel"]
            #print('\n'.join([''.join(['{:4}'.format(item) for item in row]) for row in panel]))
            #sys.stdout.flush()
        else:
            self.__flushed_print("ERROR message unsupported size or other error")
        return (0)
    
    def __special(self):
        history = self.__engine.get_states()
        panel = self.__board.from_special_state(history)
        marvin_move = (0, 0, 0)
        temp_move = (0, 0, 0)
        line = self.__read_stdin()[0]
        while line != "DONE":
            coords = line.split(",")
            temp_move = (int(coords[0]), int(coords[1]), int(coords[2]))
            panel[temp_move[1]][temp_move[0]] = temp_move[2]
            if temp_move[2] == 2:
                marvin_move = temp_move
            line = self.__read_stdin()[0]

        if marvin_move[2] == 2:
            self.__engine.reset()
            panel[temp_move[1]][temp_move[0]] = 0
            self.__engine.spe_update(self.__board.first_state((temp_move[0], temp_move[1]), 2, panel))
        self.__ia_part()
        return (0)
    
    def __ia_part(self):
        self.__current_move = self.__engine.find_best_move(self.__board)
        self.__engine.update(self.__board.next_state(self.__engine.get_states()[-1], self.__current_move))
        self.__flushed_print(str(self.__current_move[0]) + "," + str(self.__current_move[1]))
        self.__engine.update_possible_moves(self.__current_move)
    
    def catch_input(self):
        try:
            self.__command = self.__read_stdin()
        except EOFError:
            self.__flushed_print("End of file")
            return (-1)
        if (self.__command[0] == ''):
            return (-1)
        wish = str(self.__command[0])
        for i in range (len(self.__input_handler)):
            if (wish == self.__input_handler[i]['input']):
                return self.__input_handler[i]['handler']()
        self.__flushed_print("ERROR - Command not existing - " + wish)
        return (0)
