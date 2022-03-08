from itertools import count
import sys
from copy import deepcopy
import json

class Board:

    def __init__(self, board_size):
        self.__size = board_size
        self.__panel = [ [0] * self.__size for i in range (self.__size) ]
        self.__is_started = False
    
    def __del__(self):
        del self.__panel
    
    def show(self):
        print('\n'.join([''.join(['{:4}'.format(item) for item in row]) for row in self.__panel]))
        sys.stdout.flush()
    
    def start(self, size):
        self.__size = size
        self.__panel = [ [0] * self.__size for i in range (self.__size) ]
        self.__is_started = True
    
    def is_started(self):
        return self.__is_started
    
    def size(self):
        return self.__size
    
    def is_empty(self):
        for i in range(self.__size):
            for j in range(self.__size):
                if self.__panel[i][j] != 0:
                    return (1)
        return (0)
    
    def reset(self):
        self.__panel = [ [0] * self.__size for i in range (self.__size) ]
    
    def copy(self):
        return Board.from_custom_board(self.__panel, self.__size)
    
    @classmethod
    def from_custom_board(cls, board, size):
        instance = cls(size)
        instance.__panel = deepcopy(board)
        instance.__is_started = True
        return instance
    
    def is_playable_move(self, move):
        if (move[0] >= self.__size or move[1] >= self.__size):
            #print("Move indexes out of range")
            #sys.stdout.flush()
            return (1)
        elif (self.__panel[move[1]][move[0]] != 0):
            #print("A player already played this")
            #sys.stdout.flush()
            return (1)
        return (0)
    
    def from_special_state(self, history):
        if history != []:
            return json.loads(history[-1])['panel']
        else:
            return [ [0] * self.__size for i in range(self.__size) ]
    
    def first_state(self, move, player, panel = None):
        if panel != None:
            self.__panel = panel
        self.__panel[move[1]][move[0]] = player
        return json.dumps({
            "previous_player": player,
            "previous_move": move,
            "panel": self.__panel
        })
    
    def next_state(self, state, move):
        obj = json.loads(state)
        if obj["previous_player"] == 1:
            player = 2
        else:
            player = 1
        if (move[0] < self.__size and move[1] < self.__size and move[0] >= 0 and move[1] >= 0):
            obj["panel"][move[1]][move[0]] = player
            return json.dumps({
                "previous_player": player,
                "previous_move": move,
                "panel": obj["panel"]
            })
        print('ERROR: Move out of range')
        sys.stdout.flush()
        return state
    
    def update_board_score(self, secret, move, player, search):
        x = move[0]
        y = move[1]
        secret[y][x] = -player
        dirs = [(-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)]

        for dir in dirs:
            for n in range(1, 6):
                x = move[0] + dir[0] * n
                y = move[1] + dir[1] * n
                if x < 0 or y < 0 or x >= self.__size or y >= self.__size or secret[y][x] < 0:
                    continue
                scores = []
                for i in range(0, 4):
                    score = 0
                    nx = x + dirs[i][0]
                    ny = y + dirs[i][1]
                    while nx >= 0 and ny >= 0 and nx < self.__size and ny < self.__size and secret[ny][nx] == -search:
                        nx += dirs[i][0]
                        ny += dirs[i][1]
                        score += 1
                    nx = x + dirs[i + 4][0]
                    ny = y + dirs[i + 4][1]
                    while nx >= 0 and ny >= 0 and nx < self.__size and ny < self.__size and secret[ny][nx] == -search:
                        nx += dirs[i + 4][0]
                        ny += dirs[i + 4][1]
                        score += 1
                    scores.append(score)
                secret[y][x] = max(scores)
    
    def spe_update_board_score(self, secret, panel, search):
        dirs = [(-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)]
        for y in range(self.__size):
            for x in range(self.__size):
                if panel[y][x] != 0:
                    secret[y][x] = -panel[y][x]
        for y in range(self.__size):
            for x in range(self.__size):
                if secret[y][x] >= 0:
                    scores = []
                    for i in range(0, 4):
                        score = 0
                        nx = x + dirs[i][0]
                        ny = y + dirs[i][1]
                        while nx >= 0 and ny >= 0 and nx < self.__size and ny < self.__size and secret[ny][nx] == -search:
                            nx += dirs[i][0]
                            ny += dirs[i][1]
                            score += 1
                        nx = x + dirs[i + 4][0]
                        ny = y + dirs[i + 4][1]
                        while nx >= 0 and ny >= 0 and nx < self.__size and ny < self.__size and secret[ny][nx] == -search:
                            nx += dirs[i + 4][0]
                            ny += dirs[i + 4][1]
                            score += 1
                        scores.append(score)
                    secret[y][x] = max(scores)
    
    def current_player(self, state):
        state_obj = json.loads(state)
        if (state_obj["previous_player"] == 1):
            return 2
        else:
            return 1
    
    def all_moves(self, state_history):
        legal_moves = []
        panel = json.loads(state_history[-1])["panel"]
        for i in range(self.__size):
            for j in range(self.__size):
                if (panel[i][j] != 0):
                    continue
                legal_moves.append((j, i))
        return legal_moves
    
    def possible_moves(self, state_history, previous_possible_moves):
        legal_moves = []
        obj = json.loads(state_history[-1])
        panel = obj["panel"]
        last_move = obj["previous_move"]
        for i in range(1, 2, 1):
            if (last_move[0] + i < self.__size and panel[last_move[1]][last_move[0] + i] == 0 and not (last_move[0] + i, last_move[1]) in previous_possible_moves):
                legal_moves.append((last_move[0] + i, last_move[1]))
            if (last_move[1] + i < self.__size and last_move[0] + i < self.__size and panel[last_move[1] + i][last_move[0] + i] == 0 and not (last_move[0] + i, last_move[1] + i) in previous_possible_moves):
                legal_moves.append((last_move[0] + i, last_move[1] + i))
            if (last_move[1] + i < self.__size and panel[last_move[1] + i][last_move[0]] == 0 and not (last_move[0], last_move[1] + i) in previous_possible_moves):
                legal_moves.append((last_move[0], last_move[1] + i))
            if (last_move[1] + i < self.__size and last_move[0] - i >= 0 and panel[last_move[1] + i][last_move[0] - i] == 0 and not (last_move[0] - i, last_move[1] + i) in previous_possible_moves):
                legal_moves.append((last_move[0] - i, last_move[1] + i))
            if (last_move[0] - i >= 0 and panel[last_move[1]][last_move[0] - i] == 0 and not (last_move[0] - i, last_move[1]) in previous_possible_moves):
                legal_moves.append((last_move[0] - i, last_move[1]))
            if (last_move[1] - i >= 0 and last_move[0] - i >= 0 and panel[last_move[1] - i][last_move[0] - i] == 0 and not (last_move[0] - i, last_move[1] - i) in previous_possible_moves):
                legal_moves.append((last_move[0] - i, last_move[1] - i))
            if (last_move[1] - i >= 0 and panel[last_move[1] - i][last_move[0]] == 0 and not (last_move[0], last_move[1] - i) in previous_possible_moves):
                legal_moves.append((last_move[0], last_move[1] - i))
            if (last_move[1] - i >= 0 and last_move[0] + i < self.__size and panel[last_move[1] - i][last_move[0] + i] == 0 and not (last_move[0] + i, last_move[1] - i) in previous_possible_moves):
                legal_moves.append((last_move[0] + i, last_move[1] - i))
        if (len(legal_moves) == 0):
            return previous_possible_moves
        return legal_moves + previous_possible_moves
    
    def spe_possible_moves(self, state_history):
        legal_moves = []
        obj = json.loads(state_history[-1])
        panel = obj["panel"]

        for y in range(self.__size):
            for x in range(self.__size):
                if (panel[y][x] != 0):
                    for i in range(1, 2, 1):
                        if (x + i < self.__size and panel[y][x + i] == 0 and not (x + i, y) in legal_moves):
                            legal_moves.append((x + i, y))
                        if (y + i < self.__size and x + i < self.__size and panel[y + i][x + i] == 0 and not (x + i, y + i) in legal_moves):
                            legal_moves.append((x + i, y + i))
                        if (y + i < self.__size and panel[y + i][x] == 0 and not (x, y + i) in legal_moves):
                            legal_moves.append((x, y + i))
                        if (y + i < self.__size and x - i >= 0 and panel[y + i][x - i] == 0 and not (x - i, y + i) in legal_moves):
                            legal_moves.append((x - i, y + i))
                        if (x - i >= 0 and panel[y][x - i] == 0 and not (x - i, y) in legal_moves):
                            legal_moves.append((x - i, y))
                        if (y - i >= 0 and x - i >= 0 and panel[y - i][x - i] == 0 and not (x - i, y - i) in legal_moves):
                            legal_moves.append((x - i, y - i))
                        if (y - i >= 0 and panel[y - i][x] == 0 and not (x, y - i) in legal_moves):
                            legal_moves.append((x, y - i))
                        if (y - i >= 0 and x + i < self.__size and panel[y - i][x + i] == 0 and not (x + i, y - i) in legal_moves):
                            legal_moves.append((x + i, y - i))
        return legal_moves

    def is_there_winning_moves(self, last_state, posible_moves):
        for i in range(len(posible_moves)):
            history = [last_state]
            history.append(self.next_state(last_state, posible_moves[i]))
            win = self.winner(history)
            if win != 0:
                return posible_moves[i]
        return None
    
    def what_does_this_move_do(self, panel, move):
        result = []

        x = move[0]
        y = move[1] + 4
        for i in range(5):
            counters = []
            #checking horizontal
            start_x = x - 4 + i
            start_y = move[1]
            hor_values = []
            for j in range(5):
                if (start_x + j >= 0 and start_x + j < self.__size):
                    hor_values.append(panel[start_y][start_x + j])
            counters.append(hor_values)
            if (y - i < self.__size):
                #checking diagonals
                diag1_x = x - 4 + i
                diag2_x = x + 4 - i
                start_y = y - i
                diag1_values = []
                diag2_values = []
                for j in range(5):
                    if (diag1_x + j >= 0 and diag1_x + j < self.__size and start_y - j >= 0):
                        diag1_values.append(panel[start_y - j][diag1_x + j])
                    if (diag2_x - j < self.__size and diag2_x - j >= 0 and start_y - j >= 0):
                        diag2_values.append(panel[start_y - j][diag2_x - j])
                counters.append(diag1_values)
                counters.append(diag2_values)
                #checking vertical
                start_x = move[0]
                start_y = y - i
                ver_values = []
                for j in range(5):
                    if (start_y - j >= 0):
                        ver_values.append(panel[start_y - j][start_x])
                counters.append(ver_values)
            for n in counters:
                if n.count(0) < 3 and len(n) == 5:
                    result.append(n)
        return result
    
    def winner(self, state_history):
        last_state = json.loads(state_history[-1])
        last_move = last_state["previous_move"]
        last_player = last_state["previous_player"]
        panel = last_state["panel"]

        x = last_move[0]
        y = last_move[1] + 4
        for i in range(5):
            counters = [0, 0, 0, 0]
            #checking horizontal
            start_x = x - 4 + i
            start_y = last_move[1]
            for j in range(5):
                if (start_x + j >= 0 and start_x + j < self.__size and panel[start_y][start_x + j] == last_player):
                    counters[2] += 1
            if (y < self.__size):
                #checking diagonals
                diag1_x = x - 4 + i
                diag2_x = x + 4 - i
                start_y = y - i
                for j in range(5):
                    if (diag1_x + j >= 0 and diag1_x + j < self.__size and start_y - j >= 0 and panel[start_y - j][diag1_x + j] == last_player):
                        counters[0] += 1
                    if (diag2_x - j < self.__size and diag2_x - j >= 0 and start_y - j >= 0 and panel[start_y - j][diag2_x - j] == last_player):
                        counters[1] += 1
                #checking vertical
                start_x = last_move[0]
                start_y = y - 4 + i
                for j in range(5):
                    if (start_y - j >= 0 and panel[start_y - j][start_x] == last_player):
                        counters[3] += 1
            if counters.count(5) > 0:
                return last_player
        return (0)