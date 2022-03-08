from __future__ import division
from unittest import result
from board import *
from random import choice
from math import sqrt, log
import sys
import datetime
from copy import deepcopy

class Engine:

    def __init__(self, seconds: float, board: Board):
        self.__timeout = seconds = datetime.timedelta(seconds=seconds)
        self.__states = []
        self.__max_moves = 20
        self.__plays = {}
        self.__wins = {}
        self.__max_depth = 0
        self.__C = 1.4
        self.__saved_possible_moves = []
        self.__board = board
        self.secret_enemy_board = [ [0] * self.__board.size() for i in range (self.__board.size()) ]
        self.secret_board = [ [0] * self.__board.size() for i in range (self.__board.size()) ]
    
    def update_secret(self):
        self.secret_enemy_board = [ [0] * self.__board.size() for i in range (self.__board.size()) ]
        self.secret_board = [ [0] * self.__board.size() for i in range (self.__board.size()) ]

    def print_secrets_board(self):
        print('ENEMY BOARD:')
        print('\n'.join([''.join(['{:4}'.format(item) for item in row]) for row in self.secret_enemy_board]))
        print('IA BOARD:')
        print('\n'.join([''.join(['{:4}'.format(item) for item in row]) for row in self.secret_board]))
        sys.stdout.flush()

    def update(self, state):
        obj = json.loads(state)
        player = obj['previous_player']
        move = obj['previous_move']
        self.__board.update_board_score(self.secret_board, move, player, 1)
        self.__board.update_board_score(self.secret_enemy_board, move, player, 2)
        self.__states.append(state)
        self.update_possible_moves(move)
        self.__saved_possible_moves = self.__board.possible_moves(self.__states, self.__saved_possible_moves)
    
    def spe_update(self, state):
        obj = json.loads(state)
        self.__board.spe_update_board_score(self.secret_board, obj['panel'], 1)
        self.__board.spe_update_board_score(self.secret_enemy_board, obj['panel'], 2)
        self.__states.append(state)
        move = obj['previous_move']
        self.update_possible_moves(move)
        self.__saved_possible_moves = self.__board.spe_possible_moves(self.__states)
    
    def update_possible_moves(self, move):
        if (self.__saved_possible_moves != [] and move in self.__saved_possible_moves):
            self.__saved_possible_moves.remove(move)
    
    def get_states(self):
        return self.__states
    
    def reset(self):
        self.states = []
        self.__plays = {}
        self.__wins = {}
        self.__max_depth = 0
        self.__saved_possible_moves = []
        self.secret_enemy_board = [ [0] * self.__board.size() for i in range (self.__board.size()) ]
        self.secret_board = [ [0] * self.__board.size() for i in range (self.__board.size()) ]
    
    def find_best_move(self, board:Board):
        enemy_values = [0, 0, 0]
        self_values = [0, 0, 0]
        for y in range(board.size()):
            for x in range(board.size()):
                if enemy_values[2] < self.secret_enemy_board[y][x]:
                    enemy_values[0] = x
                    enemy_values[1] = y
                    enemy_values[2] = self.secret_enemy_board[y][x]
                if self_values[2] < self.secret_board[y][x]:
                    self_values[0] = x
                    self_values[1] = y
                    self_values[2] = self.secret_board[y][x]
        if self_values[2] >= enemy_values[2]:
            return (self_values[0], self_values[1])
        return (enemy_values[0], enemy_values[1])

    def find_best_move_v1(self, board: Board):
        begin = datetime.datetime.utcnow()
        panel = json.loads(self.__states[-1])['panel']
        possibles_moves = board.all_moves(self.__states)
        avoid_loosing_moves = []
        avoid_free_setup = []
        free_setup = []
        results = []

        if len(possibles_moves) == 1:
            return possibles_moves[0]

        for move in possibles_moves:
            results.append((move, self.__board.what_does_this_move_do(deepcopy(panel), move)))
        for move, result in sorted(results, key=lambda x: len(x[1]), reverse=True):
            for check in result:
                if check.count(1) == 4:
                    return move
                if check.count(2) == 4:
                    avoid_loosing_moves.append(move)
                if check.count(1) == 3 and check.count(0) == 2 and not move in free_setup:
                    free_setup.append(move)
                if check.count(2) == 3 and check.count(0) == 2 and not move in avoid_free_setup:
                    avoid_free_setup.append(move)
            #print(move, result)
        if len(avoid_loosing_moves) > 0:
            return avoid_loosing_moves[0]
        if len(free_setup) > 0:
            return free_setup[0]
        if len(avoid_free_setup) > 0:
            return avoid_free_setup[0]

        best_move = choice(possibles_moves)

        #self.__max_depth = 0
        #last_state = self.__states[-1]

        #games = 0
        #while datetime.datetime.utcnow() - begin < self.__timeout:
        #    self.__run_simulation(board)
        #    games += 1

        #print(datetime.datetime.utcnow() - begin)

        #moves_state = [(m, board.next_state(last_state, m)) for m in self.__saved_possible_moves]

        #winrate, best_move = max((self.__wins.get((1, state), 0) / self.__plays.get((1, state), 1), m) for m, state in moves_state)

        #player = board.current_player(last_state)

        #for x in sorted(
        #    ((100 * self.__wins.get((player, S), 0) /
        #      self.__plays.get((player, S), 1),
        #      self.__wins.get((player, S), 0),
        #      self.__plays.get((player, S), 0), p)
        #     for p, S in moves_state),
        #    reverse=True
        #):
        #    print("{3}: {0:.2f}% ({1} / {2})".format(*x))

        #print(winrate, best_move)

        #print("Maximum depth reached: ", self.__max_depth)

        if (best_move in self.__saved_possible_moves):
            self.__saved_possible_moves.remove(best_move)
        return best_move
    
    def __run_simulation(self, board: Board):
        expand = True
        visited = set()
        plays, wins = self.__plays, self.__wins
        last_state = self.__states[-1]
        player = board.current_player(last_state)
        copy_states = self.__states[:]
        possible_moves = self.__saved_possible_moves[:]
        
        for i in range(1, self.__max_moves + 1):
            possible_moves = board.possible_moves(copy_states, possible_moves)
            if len(possible_moves) == 0:
                break
            possible_winning_move = board.is_there_winning_moves(last_state, possible_moves)
            if (possible_winning_move != None):
                move = possible_winning_move
                last_state = board.next_state(last_state, move)
            else:
                moves_state = [(m, board.next_state(last_state, m)) for m in possible_moves]

                if len(moves_state) > 0 and all(plays.get((p, state)) for (p, state) in moves_state):
                    log_total = log(
                        sum(plays[(player, S)] for p, S in moves_state))
                    value, move, last_state = max(
                        ((wins[(player, S)] / plays[(player, S)]) +
                         self.__C * sqrt(log_total / plays[(player, S)]), p, S)
                        for p, S in moves_state
                    )
                elif (len(moves_state) > 0):
                    move, last_state = choice(moves_state)
                else:
                    move = choice(possible_moves)
                    last_state = board.next_state(last_state, move)
            if (move in possible_moves):
                possible_moves.remove(move)
            copy_states.append(last_state)

            if expand and (player, last_state) not in plays:
                expand = False
                plays[(player, last_state)] = 0
                wins[(player, last_state)] = 0
                
                if i > self.__max_depth:
                    self.__max_depth = i
                
            visited.add((player, last_state))

            winner = board.winner(copy_states)
            player = board.current_player(last_state)
            if winner != 0:
                break

        for p, state in visited:
            if (p, state) not in plays:
                continue
            plays[(p, state)] += 1
            if winner == p:
                wins[(p, state)] += 1
