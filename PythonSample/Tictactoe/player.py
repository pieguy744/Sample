# author: Michael Coe
# date: 12/5
# file: PLayer Class and AI Classes that interact with the board
# input: user responses (strings)
# output: interactive messages
from random import randint


class Player:
    def __init__(self, name, sign):
        self.name = name  # player's name
        self.sign = sign  # player's sign # or X

    def get_sign(self):
        return self.sign

    # return an instance sign
    def get_name(self):
        return self.name

    # return an instance name
    def choose(self, board):
        cell = input(f'{self.name}, {self.sign}: Enter a cell [A-C][1-3]: ').upper()
        valid = False
        while not valid:
            if cell[0] in "ABC" and cell[1] in '123' and len(cell) == 2:
                index = ('A1', 'B1', 'C1', 'A2', 'B2', 'C2', 'A3', 'B3', 'C3')
                cell = index.index(cell)
                if board.isempty(cell):
                    board.set(cell, self.sign)
                    valid = True
                    continue
            cell = input(f'You did not choose correctly.\n{self.name}, {self.sign}: Enter a cell [A-C][1-3]: ').upper()


# prompt the user to choose a cell
# if the user enters a valid string and the cell on the board is empty, update the board
# otherwise print a message that the input is wrong and rewrite the prompt
# use the methods board.isempty(cell), and board.set(cell, sign)
# you need to convert A1, B1, …, C3 cells into index values from 1 to 9
# you can use a tuple ("A1", "B1",...) to obtain indexes
# you can do the conversion here in the player.py or in the board.py
# this implementation is up to you

class AI(Player):
    def __init__(self, name, sign, board):
        super().__init__(name, sign)
        self.board = board
        self.index = ('A1', 'B1', 'C1', 'A2', 'B2', 'C2', 'A3', 'B3', 'C3')

    def valid(self):
        valid = []
        for i in range(len(self.index)):
            if self.board.isempty(i):
                valid.append(i)
        return valid

    def choose(self, board):
        valid = self.valid()
        board.set(valid[randint(0, len(valid) - 1)], self.sign)


class SmartAI(AI):
    # chooses a cell to place their sign on the board
    def choose(self, board):
        move = self.goodwins()
        if (not move == False) or move == 0:
            board.set(move, self.sign)
        else:
            super().choose(board)

    # returns a list of all possible win conditions (wincons) still availible to players
    def get_wincons(self):
        bore = self.index
        wincons = [bore[:3], bore[3:6], bore[6:9], [bore[0], bore[3], bore[6]], [bore[1], bore[4], bore[7]],
                   [bore[2], bore[5], bore[8]], [bore[0], bore[4], bore[8]], [bore[2], bore[4], bore[6]]]
        for i in wincons:
            x = 0
            o = 0

            for j in range(len(i)):
                if self.board.board[j] == 'X':
                    x += 1
                elif self.board.board[j] == 'O':
                    o += 1
            if x > 0 and o > 0:
                wincons.pop(wincons.index(i))
        return wincons

    # looks for win conditions with overlaping cells and returns a nested list with paired wincons
    def winoverlaps(self):
        wincons = self.get_wincons()
        laps = []
        for i in wincons:
            for j in i:
                for k in range(1, len(wincons)):
                    if j in wincons[k]:
                        laps.append([i, wincons[k]])
        return laps

    # checks if the opponent is about to win.
    def enemywin(self):
        wincons = self.get_wincons()
        for i in wincons:
            count = 0
            empty = False
            for j in i:
                if self.sign in self.board.board[self.index.index(j)]:
                    count = 0
                    break
                if self.board.board[self.index.index(j)] != ' ':
                    count += 1
                else:
                    empty = self.index.index(j)
            if count == 2:
                return empty
        return False
    #looks for the cells that will complete a win condition the fastest
    def goodwins(self):
        wincons = self.get_wincons()
        if self.sign == 'X':
            enemy = '0'
        else:
            enemy = 'X'
        doFirst = -1
        doNext = []
        doLast = []
        nogo = []
        laps = self.winoverlaps()
        for i in wincons:
            count = 0
            empty = False
            for j in i:
                if enemy in self.board.board[self.index.index(j)]:
                    count = 0
                    nogo.append(i)
                    break
                if self.board.board[self.index.index(j)] != ' ':
                    count += 1
                else:
                    empty = self.index.index(j)
            if count == 2:
                # will return cell location if it will give the win
                return empty
            elif count == 1:
                doNext.append(i)
            elif i not in nogo:
                doLast.append(i)
        # will prioritize a defensive move over another to prolong the game
        if self.enemywin():
            return self.enemywin()
        # will prioritize a move towards a wincon that is already partialy fulfilled
        for i in doNext:
            for j in i:
                if self.board.board[self.index.index(j)] == ' ':
                    return self.index.index(j)
        # will work towards a wincon
        for i in doLast:
            for j in i:
                return self.index.index(j)
        return False