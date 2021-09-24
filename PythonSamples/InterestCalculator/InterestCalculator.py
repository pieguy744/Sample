# function both compounds principal by interest at compound rate and adds consistent deposits
# in order to give an account forecast.
# returns forecasted account total and total amount deposited
def compound(principal, time, interest, deposit, deposit_rate, comp_rate):
    total = principal
    deps = 0
    for i in range(int(time * 365)):
        if i % deposit_rate == 0:
            total += deposit
            deps += deposit
        if i % comp_rate == 0:
            total += total * interest
    return total, deps


# Calculates how many days in the year between compound rates
def comp_time(comp_rate):
    comps = 0
    if comp_rate == 1:  # Daily compound rate
        comps = 1
    elif comp_rate == 2:  # Weekly rate
        comps = 52
    elif comp_rate == 3:  # Monthly rate
        comps = 30
    elif comp_rate == 4:  # Quarterly rate
        comps = int(91)
    elif comp_rate == 5:  # Quarterly rate
        comps = 365
    return comps


# main code
prince = float(input("PLease enter principal value: "))
inter = float(input("Please enter interest rate: "))
rate = int(input("Please select compound rate: 1) Daily 2) Weekly 3) Monthly, 4) Quarterly, 5) Yearly"))
dep_amount = float(input('please enter deposit amount: '))
dep_rate = int(input("Please select deposit rate: 1) Daily 2) Weekly 3) Monthly, 4) Quarterly, 5) Yearly"))
timer = float(input("Please enter hold time (in years):"))
int_comp = comp_time(rate)
dep_comp = comp_time(dep_rate)
result, added = compound(prince, timer, inter, dep_amount, dep_comp, int_comp)
print(f"Total amount: {result}\n Total interest earned: {result - (prince + added)}")
