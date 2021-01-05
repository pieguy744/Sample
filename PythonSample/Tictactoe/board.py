# author: Michael Coe
# date: 12/5
# file: Board Class that displays a tic tac toe board
# input: strings and cell spaces (lists)
# output: tic-tac-toe board
class Board:
    def __init__(self):
        # board is a list of cells that are represented
        # by strings (" ", "O", and "X")
        # initially it is made of empty cells represented
        # by " " strings
        self.sign = " "
        self.size = 3
        self.board = list(self.sign * self.size ** 2)
        # the winner's sign O or X
        self.winner = ""

    def get_size(self):
        return self.size

    # optional, return the board size (an instance size)
    def get_winner(self):
        return self.winner

    # return the winner's sign O or X (an instance winner)
    def set(self, cell, sign):
        self.board[cell] = sign

    # mark the cell on the board with the sign X or O
    def isempty(self, cell):
        if self.board[cell] == " ":
            return True
        else:
            return False

    # return True if the cell is empty (not marked with X or O)
    def isdone(self):
        done = False
        bore = self.board
        if bore[:3] == ['X', 'X', 'X'] or bore[3:6] == ['X', 'X', 'X'] or bore[6:9] == ['X', 'X', 'X'] or (
                bore[0] == 'X' and bore[3] == 'X' and bore[6] == 'X') or (
                bore[1] == 'X' and bore[4] == 'X' and bore[7] == 'X') \
                or (bore[2] == 'X' and bore[5] == 'X' and bore[8] == 'X') or (
                bore[0] == 'X' and bore[4] == 'X' and bore[8] == 'X') or (
                bore[6] == 'X' and bore[4] == 'X' and bore[2] == 'X'):
            self.winner = 'X'
            done = True
        elif bore[:3] == ['O', 'O', 'O'] or bore[3:6] == ['O', 'O', 'O'] or bore[6:9] == ['O', 'O', 'O'] or (
                bore[0] == 'O' and bore[3] == 'O' and bore[6] == 'O') or (
                bore[1] == 'O' and bore[4] == 'O' and bore[7] == 'O') \
                or (bore[2] == 'O' and bore[5] == 'O' and bore[8] == 'O') or (
                bore[0] == 'O' and bore[4] == 'O' and bore[8] == 'O') or (
                bore[6] == 'O' and bore[4] == 'O' and bore[2] == 'O'):
            self.winner = 'O'
            done = True
        elif not ' ' in self.board:
            done = True
        # check all game terminating conditions, if one of them is present, assign the var done to True
        # depending on conditions assign the instance var winner to O or X
        return done

    def show(self):
        bored = self.board
        print(f'''
   A   B   C 
 +---+---+---+
1| {bored[0]} | {bored[1]} | {bored[2]} |
 +---+---+---+
2| {bored[3]} | {bored[4]} | {bored[5]} |
 +---+---+---+
3| {bored[6]} | {bored[7]} | {bored[8]} |
 +---+---+---+
''')
# draw the board
