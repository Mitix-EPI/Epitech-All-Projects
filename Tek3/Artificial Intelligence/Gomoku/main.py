import random
import sys

COMMANDS = ["START", "TURN", "BEGIN", "BOARD", "END", "INFO", "ABOUT", "RESTART"]
# board 20x20
# 1 = Our AI / 2 = Marvin
board = [
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
]
board_size = 20

def is_place_available(X, Y):
    global board

    if board[Y][X]:
        return 0
    else:
        return 1

def choose_random_point():
    X_rand = random.randint(0, 19)
    Y_rand = random.randint(0, 19)

    while (is_place_available(X_rand, Y_rand) == 0):
        X_rand = random.randint(0, 19)
        Y_rand = random.randint(0, 19)
    return X_rand, Y_rand

def print_command(command):
    print(command)
    sys.stdout.flush()

def get_command():
    return sys.stdin.readline().strip().split(" ")

def info(command):
    # print_command("DEBUG INFO - " + str(command[1]))
    pass

def end(command):
    sys.exit(0)

def restart():
    global board, board_size

    board = [[0 for j in range(board_size)] for i in range(board_size)]
    print_command("OK")

def about(command):
    print_command('name="I.A.R.", version="1.0", author="Juan&Rafik", country="FR"')

def board_cmd(command): # Needed to be named differently than board to avoid conflict with board global variable
    global board

    line = get_command()[0]
    while line != "DONE":
        coords = line.split(",")
        board[int(coords[1])][int(coords[0])] = int(coords[2])
        line = get_command()[0]

    X, Y = choose_random_point() # CHANGE
    update_board(X, Y, 1)
    print_command(str(X) + "," + str(Y))

def begin(command):
    X = 9
    Y = 9
    print_command(str(X) + "," + str(Y))
    update_board(X, Y, 1)

def start(command):
    global board_size
    size = int(command[1])
    
    if (size == 20):
        board_size = size
        print_command("OK")
    else:
        print_command("ERROR message unsupported size or other error")

def update_board(X, Y, author):
    global board

    if author != 1 and author != 2:
        print_command("ERROR internal error")
        end()
    else:
        board[Y][X] = author

def turn(command):
    
    coords = command[1].split(",")
    machine_X = int(coords[0])
    machine_Y = int(coords[1])
    update_board(machine_X, machine_Y, 2)

    X, Y = choose_random_point() # CHANGE
    print_command(str(X) + "," + str(Y))
    update_board(X, Y, 1)

def run_command(command):
    if (command[0] in COMMANDS):
        if (command[0] == "START"):
            start(command)
        elif (command[0] == "BEGIN"):
            print_command("DEBUG BEGIN - " + str(command[0]))
            begin(command)
        elif (command[0] == "TURN"):
            turn(command)
        elif (command[0] == "BOARD"):
            board_cmd(command)
        elif (command[0] == "END"):
            end(command)
        elif (command[0] == "INFO"):
            info(command)
        elif (command[0] == "ABOUT"):
            about(command)
        elif (command[0] == "RESTART"):
            restart()
        else:
            print_command("ERROR - Command not existing - " + str(command[0]))
    else:
        print_command("ERROR - Command not existing - " + str(command[0]))

def main():
    while True:
        command = get_command()
        run_command(command)

if __name__ == "__main__":
	main()