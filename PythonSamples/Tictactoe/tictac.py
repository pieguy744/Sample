# author: Larissa Munishkina
# date: May 21, 2020
# file: tictac.py a Python program that implements a tic-tac-toe game
# input: user responses (strings)
# output: interactive text messages and a tic-tac-toe board

from board import Board
from player import Player, AI, SmartAI

# main program
print("Welcome to TIC-TAC-TOE Game!")
while True:
    board = Board()
    # Player class is interchangeable with AI and smart AI with the condition that board is added as a third parameter
    player1 = Player("Bob", "X")
    player2 = Player("Alice", "O")
    turn = True
    while True:
        board.show()
        if turn:
            player1.choose(board)
            turn = False
        else:
            player2.choose(board)
            turn = True
        if board.isdone():
            break
    board.show()
    if board.get_winner() == player1.get_sign():
        print(f"{player1.get_name()} is a winner!")
    elif board.get_winner() == player2.get_sign():
        print(f"{player2.get_name()} is a winner!")
    else:
        print("It is a tie!")
    ans = input("Would you like to play again? [Y/N] ").upper()
    if ans != "Y":
        break
print("Goodbye!")
