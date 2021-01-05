cost = (float)(input("Please enter cost of the Item (USD).\n"))
cash = (float)(input("Please enter the amount of Cash tenderd\n"))
print(cost)
print(cash)
dollar = (int)(cash-cost)
change =(cash*100-cost*100-dollar*100)
quart = (int)(change/25)
dime = (int)(change%25/10);
nick = (int)(change%25%10/5);
penns = (int)(change%25%10%5);
print("Your change is: " + str(dollar) + " dollars and " + str(change) + " cents\n" + str(change) + " cents is reterned as:")
print (str(quart) + " Quarters\n" + str(dime) +" Dimes\n" + str(nick) + " Nickels\n" + str(penns)  + " Pennies\n Have a nice day!")