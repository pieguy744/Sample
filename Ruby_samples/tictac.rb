#!/usr/bin/ruby
def print_board (bored)

    print "Welcome to Intergalactic Tic Tac Toe! \n    |   | \n ----------- \n    |   | \n -----------  \n    |   | \n\n"
    s0 = " "
    s1 = " "
    s2 = " "
    s3 = " "
    s4 = " "
    s5 = " "
    s6 = " "
    s7 = " "
    s8 = " "
    while 1 == 1
        print "Player 1, it's your turn to set an x on the board. Will you choose a square?\n  0 | 1 | 2 \n ----------- \n  3 | 4 | 5 \n----------- \n  6 | 7 | 8 \n\n"
        play1 = gets.chomp
        if play1 == "0"
            if s0 == bored[1] || s0 == bored[2]
                print "error, already placed here. your turn is skipped\n"
                else
                s0 = bored[2]
                print "Interesting choice, Player 1. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif  play1 == "1"
            if s1 == bored[1] || s1 == bored[2]
                print "error, already placed here. your turn is skipped\n"
                else
                s1 = bored[2]
                print "Interesting choice, Player 1. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif play1 == "2"
            if s2 == bored[1] || s2 == bored[2]
                print "error, already placed here. your turn is skipped\n"
                else
                s2 = bored[2]
                print "Interesting choice, Player 1. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif play1 == "3"
            if s3 == bored[1] || s3 == bored[2]
                print "error, already placed here. your turn is skipped\n"
            else
                s3 = bored[2]
                print "Interesting choice, Player 1. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif play1 == "4"
            if s4 == bored[1] || s4 == bored[2]
                print "error, already placed here. your turn is skipped\n"
                else
                s4 = bored[2]
                print "Interesting choice, Player 1. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif play1 == "5"
            if s5 == bored[1] || s5 == bored[2]
                print "error, already placed here. your turn is skipped\n"
                else
                s5 = bored[2]
                print "Interesting choice, Player 1. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif play1 == "6"
            if s6 == bored[1] || s6 == bored[2]
                print "error, already placed here. your turn is skipped\n"
                else
                s6 = bored[2]
             print "Interesting choice, Player 1. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif play1 == "7"
             if s7 == bored[1] || s7 == bored[2]
                print "error, already placed here. your turn is skipped\n"
                else
                s7 = bored[2]
                print "Interesting choice, Player 1. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif play1 == "8"
            if s8 == bored[1] || s8 == bored[2]
                print "error, already placed here. your turn is skipped\n"
                else
                s8 = bored[2]
                print "Interesting choice, Player 1. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
                end
        else
            print "Error, not a number. your turn is skipped\n"
        end
      

 break if s0 == bored[1] && s1 == bored[1] && s2 == bored[1]
        break if s5 == bored[1] && s4 == bored[1] && s3 == bored[1]
        break if s8 == bored[1] && s7 == bored[1] && s6 == bored[1]
        break if s6 == bored[1] && s3 == bored[1] && s0 == bored[1]
        break if s7 == bored[1] && s4 == bored[1] && s1 == bored[1]
        break if s8 == bored[1] && s5 == bored[1] && s2 == bored[1]
        break if s8 == bored[1] && s4 == bored[1] && s0 == bored[1]
        break if s6 == bored[1] && s4 == bored[1] && s2 == bored[1]
        
        break if s0 == bored[2] && s1 == bored[2] && s2 == bored[2]
        break if s5 == bored[2] && s4 == bored[2] && s3 == bored[2]
        break if s8 == bored[2] && s7 == bored[2] && s6 == bored[2]
        break if s6 == bored[2] && s3 == bored[2] && s0 == bored[2]
        break if s7 == bored[2] && s4 == bored[2] && s1 == bored[2]
        break if s8 == bored[2] && s5 == bored[2] && s2 == bored[2]
        break if s8 == bored[2] && s4 == bored[2] && s0 == bored[2]
        break if s6 == bored[2] && s4 == bored[2] && s2 == bored[2]
        break if s0 != " " && s1 != " " && s2 != " " && s3 != " " && s4 != " " && s5 != " " && s6 != " " && s7 != " " && s8 != " "

        print "Player 2, it's your turn to set an o on the board. Will you choose a square?\n  0 | 1 | 2 \n ----------- \n  3 | 4 | 5 \n----------- \n  6 | 7 | 8 \n\n"
         play2 = gets.chomp
        if  play2 == "0"
            if s0 == bored[1] || s0 == bored[2]
                print "error, already placed here. your turn is skipped\n"
            else
                s0 = bored[1]
                print "Interesting choice, Player 2. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif   play2 == "1"
            if s1 == bored[1] || s1 == bored[2]
                print "error, already placed here. your turn is skipped\n"
            else
                s1 = bored[1]
                print "Interesting choice, Player 2. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif  play2 == "2"
            if s2 == bored[1] || s2 == bored[2]
                print "error, already placed here. your turn is skipped\n"
            else
                s2 = bored[1]
                print "Interesting choice, Player 2. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif  play2 == "3"
            if s3 == bored[1] || s3 == bored[2]
                print "error, already placed here. your turn is skipped\n"
            else
                s3 = bored[1]
                print "Interesting choice, Player 2. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif  play2 == "4"
            if s4 == bored[1] || s4 == bored[2]
                print "error, already placed here. your turn is skipped\n"
            else
                s4 = bored[1]
                print "Interesting choice, Player 2. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif  play2 == "5"
            if s5 == bored[1] || s5 == bored[2]
                print "error, already placed here. your turn is skipped\n"
            else
                s5 = bored[1]
                print "Interesting choice, Player 2. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif  play2 == "6"
            if s6 == bored[1] || s6 == bored[2]
                print "error, already placed here. your turn is skipped\n"
            else
                s6 = bored[1]
                print "Interesting choice, Player 2. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif  play2 == "7"
            if s7 == bored[1] || s7 == bored[2]
                print "error, already placed here. your turn is skipped\n"
            else
                s7 = bored[1]
                print "Interesting choice, Player 2. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        elsif  play2 == "8"
            if s8 == bored[1] || s8 == bored[2]
                print "error, already placed here. your turn is skipped\n"
            else
                s8 = bored[1]
                print "Interesting choice, Player 2. \n   #{s0}| #{s1} |#{s2}\n ----------- \n   #{s3}| #{s4} |#{s5}\n -----------  \n   #{s6}| #{s7} |#{s8}\n\n"
            end
        else
            print "Error, not a number. your turn is skipped\n"
        end



        break if s0 == bored[1] && s1 == bored[1] && s2 == bored[1]
        break if s5 == bored[1] && s4 == bored[1] && s3 == bored[1]
        break if s8 == bored[1] && s7 == bored[1] && s6 == bored[1]
        break if s6 == bored[1] && s3 == bored[1] && s0 == bored[1]
        break if s7 == bored[1] && s4 == bored[1] && s1 == bored[1]
        break if s8 == bored[1] && s5 == bored[1] && s2 == bored[1]
        break if s8 == bored[1] && s4 == bored[1] && s0 == bored[1]
        break if s6 == bored[1] && s4 == bored[1] && s2 == bored[1]
        
        break if s0 == bored[2] && s1 == bored[2] && s2 == bored[2]
        break if s5 == bored[2] && s4 == bored[2] && s3 == bored[2]
        break if s8 == bored[2] && s7 == bored[2] && s6 == bored[2]
        break if s6 == bored[2] && s3 == bored[2] && s0 == bored[2]
        break if s7 == bored[2] && s4 == bored[2] && s1 == bored[2]
        break if s8 == bored[2] && s5 == bored[2] && s2 == bored[2]
        break if s8 == bored[2] && s4 == bored[2] && s0 == bored[2]
        break if s6 == bored[2] && s4 == bored[2] && s2 == bored[2]
        break if s0 != " " && s1 != " " && s2 != " " && s3 != " " && s4 != " " && s5 != " " && s6 != " " && s7 != " " && s8 != " "
    end
      if s0 == bored[1] && s1 == bored[1] && s2 == bored[1]
        print "Three in a row! Congratulations player 2\n"
    elsif s5 == bored[1] && s4 == bored[1] && s3 == bored[1]
        print "Three in a row! Congratulations player 2\n"
    elsif s8 == bored[1] && s7 == bored[1] && s6 == bored[1]
        print "Three in a row! Congratulations player 2\n"
    elsif s6 == bored[1] && s3 == bored[1] && s0 == bored[1]
        print "Three in a row! Congratulations player 2\n"
    elsif s7 == bored[1] && s4 == bored[1] && s1 == bored[1]
        print "Three in a row! Congratulations player 2\n"
    elsif s8 == bored[1] && s5 == bored[1] && s2 == bored[1]
        print "Three in a row! Congratulations player 2\n"
    elsif s8 == bored[1] && s4 == bored[1] && s0 == bored[1]
        print "Three in a row! Congratulations player 2\n"
    elsif s6 == bored[1] && s4 == bored[1] && s2 == bored[1]
        print "Three in a row! Congratulations player 2\n"
        
    elsif s0 == bored[2] && s1 == bored[2] && s2 == bored[2]
        print "Three in a row! Congratulations player 1\n"
    elsif s5 == bored[2] && s4 == bored[2] && s3 == bored[2]
        print "Three in a row! Congratulations player 1\n"
    elsif s8 == bored[2] && s7 == bored[2] && s6 == bored[2]
        print "Three in a row! Congratulations player 1\n"
    elsif s6 == bored[2] && s3 == bored[2] && s0 == bored[2]
        print "Three in a row! Congratulations player 1\n"
    elsif s7 == bored[2] && s4 == bored[2] && s1 == bored[2]
        print "Three in a row! Congratulations player 1\n"
    elsif s8 == bored[2] && s5 == bored[2] && s2 == bored[2]
        print "Three in a row! Congratulations player 1\n"
    elsif s8 == bored[2] && s4 == bored[2] && s0 == bored[2]
        print "Three in a row! Congratulations player 1\n"
    elsif s6 == bored[2] && s4 == bored[2] && s2 == bored[2]
        print "Three in a row! Congratulations player 1\n"
    else
        print "Cats game! Everyone loses!"
    end
        
end
board = Array.new
#after one move

board[2] ='x'
board [1] = "o"
board [0] = " "
print_board (board)