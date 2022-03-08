from gomoku import Gomoku

def main():
    gomoku = Gomoku()
    while True:
        ret = gomoku.catch_input()
        if (ret != 0):
            del gomoku
            return (0)
        
if __name__ == "__main__":
	main()