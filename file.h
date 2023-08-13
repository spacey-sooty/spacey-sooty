// #  # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// #  Program Name: McDermott's Fast Food Payroll System.py
// #  Author: Liam Spozetta
// #  Purpose: Task 7 - Computer Science ATAR - McDermott's Fast Food Payroll System
// #  Version: 3
// #  Last Revision: 01/08/2022
// #  # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// """   CLARKE NOTES    """
// # most of my code has been made to be easily built upon, with functions that are used here, but could be used effectively with additions
// # I tried to fit character limits, but there are some cases where I couldn't

// # USERID: 54398701
// # PASSWORD: MrClarke101



// """    PERSONAL NOTES    """

// # valid user ID rules:
// # 8 characters
// # Allowable Characters: "0123456789"
// # valid password rules:
// # at least 6 characters
// # Allowable Characters: "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+[]{};"'\./<>?"
// # Notable excluded characters: ":|,"
// # .format() is approved
// # .append() is approved
// # .strip() is approved
// # 2D arrays are approved

// import os

// """    PAY CONSTANTS    """

// STANDARD_HOURS = 9
// OVERTIME_BONUS_HOURS = 3

// OVERTIME_SMALL_RATE_PERCENT = 25
// OVERTIME_LARGE_RATE_PERCENT = 45
// WEEKEND_OT_BONUS_PERCENT = 50
// HOLIDAY_OT_BONUS_PERCENT = 50

// SATURDAY_STANDARD_BONUS = 3
// SUNDAY_STANDARD_BONUS = 4
// HOLIDAY_STANDARD_BONUS = 4

// # [ID, NAME, PAY, ACCESSLVL]
// ROLE_DATA = [
//     ["1", "Team Member", "23", "1"],
//     ["2", "Manager", "30", "2"],
//     ["3", "Administrator", "30", "3"]
// ]
// # [NAME, %AGE, ID]
// SUPERANNUATION = [
//     ["Low", "4", "1"],
//     ["Medium", "6", "2"],
//     ["High", "8", "3"]
// ]
// # [NAME, COST, ID]
// HEALTH_INSURANCE = [
//     ["Ancillary", "15", "1"],
//     ["Standard", "25", "2"],
//     ["Superior", "45", "3"]
// ]
// # [NAME, %AGE, ID]
// TAX_RATE = [
//     ["Standard", "30", "1"],
//     ["Higher", "40", "2"]
// ]

// """    DATE CONSTANTS    """

// MONTH_DAYS = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
// ALT_MONTH_DAYS = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
// CURRENT_YEAR = 2022

// """    CLOCK IN / CLOCK OUT CONSTANTS    """

// USER_ID_LENGTH = 8
// USER_ID_CHARACTERS = "0123456789"
// PASSWORD_MIN_LENGTH = 6
// PASSWORD_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+[]{};\"'\./<>?"

// """    FILE CONSTANTS    """

// ACTIVE_SHIFT_FILE = "activeShifts.txt"
// SHIFT_FILE = "completedShifts.txt"
// EMPLOYEE_DATA_FILE = "employeeData.csv"
// PAY_OUTPUT_FILE = "payroll.csv"
// DEDUCTION_FILE = "deductionData.csv"
// TEST_DATA_FILE = "McDermott'sPayRoll_TestData.csv"
// LOG_FILE = "logFile.csv"
// TEST_OUTPUT = "output.csv"
// ALL_SHIFTS = "allShifts.csv"
// DELETED_EMPLOYEES_FILE = "deletedEmployees.csv"

// """    OTHER CONSTANTS    """

// VALID_ROLES = ["Team Member", "Manager", "Administrator"]
// VALID_TAX_RATES = [30, 40]
// VALID_HLTH_RATES = [15, 25, 45]
// VALID_SUPER_RATES = [4, 6, 8]
// VALID_NAME_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
// CAPITALS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
// LOWERS = "abcdefghijklmnopqrstuvwxyz"

// """    PERSONAL FUNCTIONS    """


// # validation
// # I could use one combined function, but multiple are needed to use getValidItem
// def validate2OptionInput(userInput):
//     if userInput != "1" and userInput != "2":
//         return False
//     return True


// def validate3OptionInput(userInput):
//     for i in range(1, 4):
//         if userInput == str(i):
//             return True
//     return False


// def validate4OptionInput(userInput):
//     for i in range(1, 5):
//         if userInput == str(i):
//             return True
//     return False


// def validate7OptionInput(userInput):
//     for i in range(1, 8):
//         if userInput == str(i):
//             return True
//     return False


// # get
// def getLength(object):
//     # removes the first character/element in string/array and adds 1 to length
//     # if no characters remain, the loop ends
//     length = 0
//     is_object_empty = False
//     while is_object_empty == False:
//         if object == "" or object == []:
//             is_object_empty = True
//         else:
//             object = object[:-1]
//             length += 1
//     return length


// def getFirstPositionOfObject(object, inWhat):
//     in_what_length = getLength(inWhat)
//     # goes thru each character/element and sees if the "object" to get pos of is in the "inWhat"
//     # output is [index, isAtleast1PresentBoolean]
//     for object_num in range(in_what_length):
//         if inWhat[object_num] == object:
//             return [object_num, True]
//     return [0, False]


// def getCharacterCount(string, countChar):
//     # loops thru each character and adds 1 to a counter if a character is found
//     total_count = 0
//     string_length = getLength(string)
//     for character_num in range(string_length):
//         if string[character_num] == countChar:
//             total_count += 1
//     return total_count


// def getValidItem(headerText, inputFunction, validationFunction, maxAttempts):
//     # displays header text (resetting console as well)
//     # asks user for an input (thru a function parsed into this one) after printing a screen
//     # validates that user input with a function parsed into this one
//     # if invalid, then add 1 to failed attempts counter
//     # if failed attempts counter reaches the max number of attempts, then the loop ends, and
//     # the function returns the [the user's input, False]
//     # if the input was valid, it returns [the user's input, True]
//     is_valid = False
//     is_true_valid = True
//     failed_attempts_counter = 0
//     while is_valid == False:
//         header(headerText)
//         choice = inputFunction()
//         is_valid = validationFunction(choice)
//         if is_valid == False:
//             failed_attempts_counter += 1
//             attempts_remaining = maxAttempts - failed_attempts_counter
//             invalidScreen(headerText, choice, attempts_remaining)
//         if failed_attempts_counter == maxAttempts:
//             is_valid = True
//             is_true_valid = False
//             hitMaxScreen(headerText, failed_attempts_counter)
//     return [choice, is_true_valid]  # choice will always be defined


// def getDateValue(date):
//     # gets the number of days since a specific day 0, 1/1/1
//     # outputs that number
//     value = 0
//     day = int(date[0])
//     month = int(date[1])
//     year = int(date[2])
//     # leap year cycle is 4 years, hence why array is of length 4
//     year_days = [365, 365, 365, 366]
//     year_value = 0
//     for i in range(year - 1):
//         year_value += year_days[i % 4]

//     month_days_array = MONTH_DAYS
//     if year % 4 == 0:
//         month_days_array = ALT_MONTH_DAYS
//     month_value = 0
//     for i in range(month - 1):
//         month_value += month_days_array[i]
//     value = day + month_value + year_value
//     return value


// def getDateFromValue(value):
//     # the most annoying function to code out of this whole file
//     output = [0, 0, 0]
//     year_lengths = [366, 365, 365, 365]
//     val_year = 1
//     year_number = 1
//     store_var = 0
//     while 0 < value:
//         store_var = year_number % 4  # number of leap year cycles rounded down
//         value -= year_lengths[store_var]
//         year_number += 1
//     if value <= 0:
//         value += year_lengths[store_var]

//     year_number -= 1 if year_number != 1 else 0
//     val_month = 0
//     new_val = value
//     m = 0
//     month_lengths = ALT_MONTH_DAYS if store_var == 0 else MONTH_DAYS
//     store_var = 0
//     year_number += 1 if year_number == 0 else 0
//     while 0 < new_val:
//         store_var = month_lengths[m]
//         new_val -= store_var
//         val_month += store_var
//         m += 1
//     d = value - val_year - val_month + month_lengths[m - 1] + 1
//     output[0] = d
//     output[1] = m
//     output[2] = year_number
//     return output


// def getDayOfWeekIndexFromDate(day, month, year):
//     # got calculation from:
//     # https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html
//     # follows the steps there, and uses similar variable names
//     k = day
//     m = month - 2
//     c = year // 100
//     y = year - 100 * c
//     if month == 1 or month == 2:
//         m = 10 + month
//         y -= 1
//     else:
//         m = month - 2
//     x1 = (2.6 * m - 0.2) // 1
//     x2 = y // 4
//     x3 = c // 4
//     w = int((k + x1 - 2 * c + y + x2 + x3) % 7)
//     if w == 0:
//         return 6
//     else:
//         return w - 1


// def getDateNDaysAgoVariant(dateValue, daysAgo):
//     # gets a date value, subtracts a certain number of days and converts it to a new date
//     # this has been made to work across years and months, even numbers like 123781 days ago (hence why that function was annoying to code)
//     value = dateValue - daysAgo
//     new_date = getDateFromValue(value)
//     return new_date


// # convert
// def convertStringToNumeric(string):
//     # validation comes before this function will ever be called
//     # checks if a "." is present at all and then returns the appropriate data type
//     if isInVar(".", string, False) == False:
//         return int(string)
//     if string[-1] == ".":
//         if getLength(string) == 1:
//             return 0
//         string = string[:-1]
//     return float(string)


// def convertTimeToValue(timeString):
//     # gets the number of minutes since 00:00
//     time_string_array = splitString(timeString, ":", 1)
//     hours_value = convertStringToNumeric(time_string_array[0]) * 60
//     minutes_value = convertStringToNumeric(time_string_array[1])
//     time_value = hours_value + minutes_value
//     return time_value


// def convertDateToValue(dateArray):
//     # this (and the next function) differ from the ones above as it uses a different date format
//     # this one is used more than "getDateValue" due to efficiency as the other one isn't necessary for this application
//     # "getDateValue" and "getDateFromValue" work together for calculating how many days ago a date was or similar applications
//     # the output is an 8 digit integer in the format yyyymmdd
//     day_integer = int(dateArray[0])
//     month_integer = int(dateArray[1])
//     year_integer = int(dateArray[2])
//     value = year_integer * 10000 + month_integer * 100 + day_integer
//     return value


// def convertValueToDate(dateValue):
//     # does the complete opposite of "convertDateToValue"
//     # returns an integer array for the date
//     date_value_string = str(dateValue)
//     day_string = date_value_string[-2] + date_value_string[-1]
//     day_number = int(day_string)
//     month_string = date_value_string[-4] + date_value_string[-3]
//     month_number = int(month_string)
//     year_number = (int(dateValue) - month_number * 100 - day_number) // 10000
//     return [day_number, month_number, year_number]


// # testing
// def isInVar(objectName, variable, getIndex):
//     output = getFirstPositionOfObject(objectName, variable)
//     if getIndex == True:
//         return output  # Return the [index, boolean]
//     else:
//         return output[1]  # Return the Boolean


// def isStringNumeric(string, allowFloat):
//     # There will not be any negative numbers
//     # Will read [this, asThis] -> [".1", 0.1], ["9.", 9]
//     # checks every character in the string to see if it is an allowed character
//     # If decimals are allowed then it will check if there are more than 1 "." indirectly
//     string_length = getLength(string)
//     if string_length == 0:
//         return False
//     valid_chars = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
//     alt_char_valid_max = False
//     for i in range(string_length):
//         character = string[i]
//         if allowFloat == True:
//             if character == ".":
//                 if alt_char_valid_max == True:
//                     return False
//                 alt_char_valid_max = True
//             if isInVar(character, valid_chars, False) == False:
//                 return False
//         elif isInVar(character, valid_chars, False) == False:
//             return False
//     return True


// # other
// def splitString(string, splitChar, maxSplit):
//     # determines how many elements the output should have and creates an array with that many elements
//     # "index" increases every time the function looks at a "splitChar"
//     # the function adds non "splitChar" characters to elements in the array at "index" position
//     # This function also allows for a maximum number of splits
//     # lets say I want to split "abc,def,ghi" at "," maximum of 1 time
//     # the output would be ["abc", "def,ghi"]
//     string_length = getLength(string)
//     split_char_count = getCharacterCount(string, splitChar)
//     if split_char_count == 0:
//         return []
//     if maxSplit <= split_char_count:
//         element_count = maxSplit + 1
//     else:
//         element_count = split_char_count + 1
//     output = [""] * element_count
//     index = 0
//     splitted_count = 0
//     for character_num in range(string_length):
//         current_char = string[character_num]
//         if current_char == splitChar and splitted_count < maxSplit:
//             index += 1
//             splitted_count += 1
//         else:
//             output[index] += current_char
//     return output


// def read2DArrayItem(readArray, itemToGet, pos):
//     # finds the element with the specified datum in the array of arrays and returns the inside array
//     array_length = getLength(readArray)
//     for index in range(array_length):
//         if readArray[index][pos] == itemToGet:
//             return readArray[index]


// def mergeArray(array, mergeCharacter):
//     # does the opposite of splitString
//     output = ""
//     array_length = getLength(array)
//     for index in range(array_length):
//         output += array[index] + mergeCharacter
//     return output[:-1]


// def roundToDP(number, decimalPlace):
//     # 1.12345 (2DP) -> 1.12345 * 10^2 -> 112 -> 112/(10^2) -> 1.12
//     proportion = 10 ** decimalPlace
//     num = int(number * proportion) / proportion
//     return num


// def fillWithZeros(string, fillLength):
//     # adds "0"'s to the front of a string until the specified length has been reached
//     fill_with_count = fillLength - getLength(string)
//     output = string
//     for i in range(fill_with_count):
//         output = "0" + output
//     return output


// """    MISC FUNCTIONS    """


// def lowerCaseString(string):
//     # for any capital letters, get the index of it in the capital alphabet
//     # add the character at that index in the lowercase alphabet to an output
//     # for any other characters, just add it to the output
//     output = ""
//     string_length = getLength(string)
//     for char_index in range(string_length):
//         cur_char = string[char_index]
//         is_in_caps = isInVar(cur_char, CAPITALS, True)
//         if is_in_caps[1] == True:
//             output += LOWERS[is_in_caps[0]]
//         else:
//             output += cur_char
//     return output


// def getRoleInfo(roleIdentifier, identifierIndex):
//     number_of_roles = getLength(ROLE_DATA)  # allows for expansion
//     for role_index in range(number_of_roles):
//         if ROLE_DATA[role_index][identifierIndex] == roleIdentifier:
//             return ROLE_DATA[
//                 role_index]  # [role id, role name, pay rate, access level]


// def getEmployeeInformation(userID):
//     # reads the employee's data from a file (ID,PWRD,GNAME,SNAME,ROLEID,TRATE,HLTH,SUPER)
//     # finds the line with ID = user_ID, and reads it
//     # returns it as an array ["ID", "PWRD", "GNAME", "SNAME", "ROLEID", "TRATE", "HLTH", "SUPER"]
//     employee_file = open(EMPLOYEE_DATA_FILE, "r")
//     employee_file_lines = employee_file.readlines()
//     line_count = getLength(employee_file_lines)
//     user_line = ""
//     for i in range(line_count):
//         line = employee_file_lines[i]
//         if splitString(line, ",", 1)[0] == userID:
//             user_line = line.strip()  # removes "\n"
//     return splitString(user_line, ",", 999)


// def getEmployeeInformationFromName(gname, sname):
//     # does the same as "getEmployeeInformation" but uses the names instead of using userID
//     employee_file = open(EMPLOYEE_DATA_FILE, "r")
//     employee_file_lines = employee_file.readlines()
//     line_count = getLength(employee_file_lines)
//     user_line = ""
//     for i in range(line_count):
//         line = employee_file_lines[i]
//         cur_line = splitString(line, ",", 99)
//         line_gname = lowerCaseString(cur_line[2])
//         line_sname = lowerCaseString(cur_line[3])
//         g_name = lowerCaseString(gname)
//         s_name = lowerCaseString(sname)
//         if line_gname == g_name and line_sname == s_name:
//             user_line = line.strip()
//     return splitString(user_line, ",", 999)


// """    SCREEN / DISPLAY FUNCTIONS    """


// # console ui functions
// def clearConsole():
//     os.system('cls' if os.name == 'nt' else 'clear')


// def header(screenName):
//     clearConsole()
//     title = "McDermott's Fast Food Service - {}".format(screenName)
//     line = ""
//     title_length = getLength(title)
//     # this loop acts to create a divider with the same length as the title text
//     for character in range(title_length):  # monospaced font abuse
//         line += "-"
//     print(title)
//     print(line)


// def invalidScreen(headerText, userInput, attempts):
//     header(headerText)
//     invalidInputDisplay(userInput, attempts)


// def invalidInputDisplay(string, attempts):
//     print("Your input of \"{}\" is invalid.".format(string))
//     if attempts > -1:
//         # sometimes when calling "getValidItem", maxAttempts will be set to -1
//         # in this case, that means there's an unlimited number of attempts
//         print("You have {} attempts remaining".format(attempts))
//     input("Press [Enter] to try again.")


// def hitMaxDisplay(attempts):
//     print \
//         (
//             "You have hit the maximum number of attempts ({}) and will have to restart".format
//             (attempts))
//     input("Press [Enter] to continue")


// def hitMaxScreen(headerText, attempts):
//     header(headerText)
//     hitMaxDisplay(attempts)


// # sign in / sign out
// def authenticationScreen_Failed(userID, password):
//     header("Sign In")
//     print("User ID or password is incorrect")
//     print("You put:")
//     print("\tUser ID : {}".format(userID))
//     print("\tPassword: {}".format(password))
//     input("Press [Enter] to try again")


// def authenticationScreen_Success():
//     header("Sign In")
//     print("Authentication Success")
//     input("Press [Enter] to continue")


// def signOutConfirm():
//     header("Sign Out")
//     print("Would you like to:")
//     print("\t1} Go Back")
//     print("\t2} Sign Out")
//     option = input("Option Number: ")
//     return option


// def inputUserID_signIn():
//     return input("What is your User ID: ")


// def inputPassword_signIn():
//     return input("What is your password: ")


// # actions
// def inputActionScreen(gname, sname, roleAccessLevel):
//     header("Select Action")
//     print("Hello {} {}!".format(gname, sname))
//     print("What would you like to do?")
//     # looks at the roleAccessLevel, and displays the visible options for that access level
//     if roleAccessLevel == "3":
//         displayActionLevel3Options()
//         valid_num = 7
//     elif roleAccessLevel == "2":
//         displayActionLevel2Options()
//         valid_num = 5
//     else:
//         displayActionLevel1Options()
//         valid_num = 3
//     # gets the user's choice
//     user_option = input("Type the number of the action you wish to perform: ")
//     return [user_option, valid_num]


// def displayActionLevel1Options():
//     print("\t 1} Sign-out")
//     print("\t 2} Manage Shift")
//     print("\t 3} View Hours")


// def displayActionLevel2Options():
//     print("\t 1} Sign-out")
//     print("\t 2} Manage Shift")
//     print("\t 3} View Hours")
//     print("\t 4} Get User ID or Name")
//     print("\t 5} Pay Members")


// def displayActionLevel3Options():
//     print("\t 1} Sign-out")
//     print("\t 2} Manage Shift")
//     print("\t 3} View Hours")
//     print("\t 4} Get User ID or Name")
//     print("\t 5} Pay Members")
//     print("\t 6} Test Mode")
//     print("\t 7} Modify Employees")


// # manage shift
// def inputDate():
//     print("What is today's date? Ensure all inputs are numeric")
//     day = input("Day Number: ")
//     month = input("Month Number: ")
//     year = input("Year: ")
//     return [day, month, year]


// def inputStartTime():
//     print("What time is your shift starting?")
//     return input("Time in 24h format: ")


// def startShiftScreen_1():
//     header("Manage Shift")
//     print("Would you like to:")
//     print("\t1} Go Back")
//     print("\t2} Start Shift")
//     return input("Option Number: ")


// def startShiftScreen_2():
//     header("Start Shift")
//     print("Your shift has now begun")
//     input("Press [Enter] to return to options")  # pauses the code's execution


// def confirmStartDateTime(dateTimeArray):
//     date = dateTimeArray[0]
//     time = dateTimeArray[1]
//     print("Your shift starts at {} on {}".format(time, date))
//     print("\t1} Incorrect, I would like to redo it")
//     print("\t2} Correct")
//     return input("Choice: ")


// def inputEndTime():
//     print("What time did your shift end?")
//     return input("Time in 24h 'hh:mm' format: ")


// def endShiftScreen_1():
//     header("Manage Shift")
//     print("Would you like to:")
//     print("\t1} Go Back")
//     print("\t2} End Shift")
//     return input("Option Number: ")


// def endShiftScreen_2():
//     header("End Shift")
//     print("Your shift is now over. Thank you for your hard work today")
//     input("Press [Enter] to return to options")  # pauses code's execution


// def successfulLogHoursScreen(hours):
//     header("End Shift")
//     print("You have worked for {} hours today.".format(hours))
//     print("Your hours have now been logged.")
//     input("Press [Enter] to continue.")  # pauses code's execution


// # pay members
// def payMembers_S1():
//     header("Pay Members")
//     print("Would you like to:")
//     print("\t1} Go Back")
//     print("\t2} Continue to pay section")
//     return input("Option Number: ")


// def payMembers_S2():
//     header("Pay Members")
//     print("Would you like to:")
//     print \
//         (
//             "\t1} Simulate Paying an Individual (Doesn't record calculated values)")
//     print("\t2} Pay All (records all calculated values)")
//     return input("Option Number: ")


// def askIfDaysAreHoliday(dates, isTestMode):
//     if isTestMode == False:
//         header("Pay Employees")
//         for day_index in range(7):
//             date = dates[day_index]
//             print("\t{}] {}/{}/{}".format(day_index + 1, date[0], date[1],
//                                           date[2]))
//     else:  # if test mode, it displays days of week instead of the dates
//         header("Test Mode")
//         print("\t1} Monday")
//         print("\t2} Tuesday")
//         print("\t3} Wednesday")
//         print("\t4} Thursday")
//         print("\t5} Friday")
//         print("\t6} Saturday")
//         print("\t7} Sunday")
//     print("Are any of these days holidays?")
//     print("Input Instructions:")
//     print("\tInput week day number with a comma and no spaces (ie 1,6,7)")
//     print("\tLeave blank if no holidays")
//     return input("Holidays: ")


// def payIndividual_S1():
//     header("Pay Individual")
//     return input("What is the User ID to pay: ")


// def payIndividual_S2(userWeekSummary, rolePayRate, dates):
//     header("Pay Individual")
//     input \
//         (
//             "Calculation Finished! Press [Enter] To view user's weekly summary")  # pauses code's execution
//     header("User's Weekly Summary")
//     uws = userWeekSummary
//     role_name = getRoleInfo(uws[4], 0)
//     # 0,  1,  , 2   , 3  ,  4  , 5   , 6  , 7 , 8 , 9 , 10, 11, 12, 13, 14 , 15 , 16  , 17 , 18 , 19, 20
//     # ID,GNAME,SNAME,ROLE,TRATE,SUPER,HLTH,MON,TUE,WED,THU,FRI,SAT,SUN,NHRS,OHRS,GROSS,SDED,HDED,TAX,NETT
//     print("ID: {}      Name: {} {}".format(uws[0], uws[1], uws[2]))
//     print("Role: {}    Role Pay Rate: {}".format(uws[3], rolePayRate))
//     print()  # new line
//     print("Deductions:")
//     print("Tax Rate: {}%       Superannuation: {}%".format(role_name, uws[5]))
//     print("Health Insurance Cost: ${}".format(uws[6]))
//     print()  # new line
//     print("Hours Worked:")
//     print \
//         ("{}/{}/{}  Monday:    {} Hours Worked".format(dates[0][0],
//                                                        dates[0][1],
//                                                        dates[0][2], uws[7]))
//     print \
//         ("{}/{}/{}  Tuesday:   {} Hours Worked".format(dates[1][0],
//                                                        dates[1][1],
//                                                        dates[1][2], uws[8]))
//     print \
//         ("{}/{}/{}  Wednesday: {} Hours Worked".format(dates[2][0],
//                                                        dates[2][1],
//                                                        dates[2][2], uws[9]))
//     print \
//         ("{}/{}/{}  Thursday:  {} Hours Worked".format(dates[3][0],
//                                                        dates[3][1],
//                                                        dates[3][2], uws[10]))
//     print \
//         ("{}/{}/{}  Friday:    {} Hours Worked".format(dates[4][0],
//                                                        dates[4][1],
//                                                        dates[4][2], uws[11]))
//     print \
//         ("{}/{}/{}  Saturday:  {} Hours Worked".format(dates[5][0],
//                                                        dates[5][1],
//                                                        dates[5][2], uws[12]))
//     print \
//         ("{}/{}/{}  Sunday:    {} Hours Worked".format(dates[6][0],
//                                                        dates[6][1],
//                                                        dates[6][2], uws[13]))
//     print("Normal Hours Worked: {}".format(uws[14]))
//     print("Overtime Hours Worked: {}".format(uws[15]))
//     print()  # new line
//     print("Gross total: {}".format(uws[16]))
//     print("Deducted Amount: ${}".format(uws[21]))
//     print("Superannuation: ${}".format(uws[17]))
//     print("Tax: ${}".format(uws[19]))
//     print("Net Total: ${}".format(uws[20]))
//     input("\n[ENTER] to return to options")  # pauses code's execution


// def payAllScreen_1():
//     # if this does get shown, then there will be a large number of employees
//     # if there's any lag this will be shown
//     header("Pay All")
//     print("Calculating! Please wait momentarily . . .")


// def payAllScreen_2():
//     header("Pay All")
//     print("All values have finished being calculated and recorded")
//     print("Values were recorded in the \"{}\" file".format(PAY_OUTPUT_FILE))
//     input("Press [ENTER] to return to options")  # pauses the code's execution


// # test mode
// def testMode_finish(wasAnyInvalid):
//     header("Test Mode")
//     print("Test File Name: \"{}\"".format(TEST_DATA_FILE))
//     print("All values processed")
//     print("All calculations done")
//     print("Output File: \"{}\"".format(TEST_OUTPUT))
//     print("All valid lines stored in output file")
//     if wasAnyInvalid == True:
//         print("Some lines were invalid and were stored in file: \"{}\"".format
//               (LOG_FILE))
//     input \
//         (
//             "Press [Enter] to return to actions screen")  # pauses the code's execution


// # get userID or employee name
// def determineObtainAction():
//     header("Actions")
//     print("Would you like to:")
//     print("\t1} Go Back")
//     print("\t2} Get User ID from name")
//     print("\t3} Get Employee Name from User ID")
//     return input("Option Number: ")


// def getEmployeeFirstName():
//     header("Get User ID")
//     return input("What is the Employee's First Name: ")


// def getEmployeeLastName():
//     header("Get User ID")
//     return input("What is the Employee's Last Name: ")


// def obtainUserID_S1(fname, sname):
//     header("Get User ID")
//     print("Employee with")
//     print("First Name: {}".format(fname))
//     print("Last Name: {}".format(sname))
//     print("Was not found, check if there's an issue with spelling")
//     input("Press [Enter] to continue")  # pauses the code's execution


// def obtainUserID_S2(userID, fname, sname):
//     header("Get User ID")
//     print("{} {} has the user ID: {}".format(fname, sname, userID))
//     input("Press [Enter] to continue")  # pauses the code's execution


// def obtainEmployeeName_S1(userID):
//     header("Get Employee's Name")
//     print("Employee with user ID {} doesn't exist".format(userID))
//     print("Ensure the user ID is written correctly")
//     input("Press [Enter] to continue")  # pauses the code's execution


// def obtainEmployeeName_S2(userID, fname, sname):
//     header("Get Employee's Name")
//     print("User with ID {} has the name of: ".format(userID))
//     print("{} {}".format(fname, sname))
//     input("Press [Enter] to continue")  # pauses the code's execution


// def getEmployeeUserID():
//     header("Get Employee's Name")
//     return input("Enter the user ID of the employee: ")


// # view hours
// def viewHours_S1(averageHours):
//     header("View Hours - [WIP]")
//     print("For the days you work, your average hours per day are: ")
//     print("Monday: {} hours".format(averageHours[0]))
//     print("Tuesday: {} hours".format(averageHours[1]))
//     print("Wednesday: {} hours".format(averageHours[2]))
//     print("Thursday: {} hours".format(averageHours[3]))
//     print("Friday: {} hours".format(averageHours[4]))
//     print("Saturday: {} hours".format(averageHours[5]))
//     print("Sunday: {} hours".format(averageHours[6]))
//     input("Press [Enter] to continue")  # pauses the code's execution


// # manage employees
// def role_S1():
//     # this function is separate from createUser_role_S1 as this same text gets used else where
//     # so I decided to separate this into it's own function
//     print("What role should the employee have?")
//     print("\t1} Team Member")
//     print("\t2} Manager")
//     print("\t3} Administrator")
//     return input("Role Number: ")


// def trate_S1():
//     # this function is separate from createUser_trate_S1 as this same text gets used else where
//     # so I decided to separate this into it's own function
//     print("Which Tax Rate?")
//     print("\t1} Standard (30%)")
//     print("\t2} Higher (40%)")
//     return input("Option Number: ")


// def super_S1():
//     # this function is separate from createUser_super_S1 as this same text gets used else where
//     # so I decided to separate this into it's own function
//     print("Which supperanuatin rate?")
//     print("\t1} Low (4%)")
//     print("\t2} Medium (6%)")
//     print("\t3} High (8%)")
//     return input("Option Number: ")


// def health_S1():
//     # this function is separate from createUser_health_S1 as this same text gets used else where
//     # so I decided to separate this into it's own function
//     print("Which Health Insurance plan?")
//     print("\t1} Ancillary ($15/week)")
//     print("\t2} Standard ($25/week)")
//     print("\t3} Superior ($45/week)")
//     return input("Option Number: ")


// def createUser_gname_S1(paras):
//     # paras is here so I can use the same validation function for this function and the ones beneath it
//     return input("What is the First Name of the new Employee: ")


// def createUser_sname_S1(paras):
//     print("{}".format(paras[2]))
//     return input("What is the Surname of the new Employee: ")


// def createUser_role_S1(paras):
//     print("{} {}".format(paras[2], paras[3]))
//     return role_S1()


// def createUser_trate_S1(paras):
//     print("{} {}".format(paras[2], paras[3]))
//     print("{}".format(paras[4]))
//     return trate_S1()


// def createUser_health_S1(paras):
//     print("{} {}".format(paras[2], paras[3]))
//     print("{}".format(paras[4]))
//     print("Deductions:")
//     print(" Tax: {}%".format(paras[5]))
//     return health_S1()


// def createUser_super_S1(paras):
//     print("{} {}".format(paras[2], paras[3]))
//     print("{}".format(paras[4]))
//     print("Deductions:")
//     print(" Tax: {}%".format(paras[5]))
//     print(" Health Insurance: ${}/week".format(paras[6]))
//     return super_S1()


// def createUser_confirm_S1(paras):
//     print("{} {}".format(paras[2], paras[3]))
//     print("{}".format(paras[4]))
//     print("Deductions:")
//     print(" Tax: {}%".format(paras[5]))
//     print(" Superannuation: {}%".format(paras[7]))
//     print(" Health Insurance: ${}/week".format(paras[6]))
//     print("Is everything here correct?")
//     print("\t1} Yes")
//     print("\t2} No")
//     return input("Option Number: ")


// def createUser_password_S1():
//     return input("What should the password be? ")


// def createUser_finished_S1(paras):
//     header("Create User")
//     print("ID: {},   PASSWORD: {}".format(paras[0], paras[1]))
//     print("{} {}".format(paras[2], paras[3]))
//     print("{}".format(paras[4]))
//     print("Deductions:")
//     print(" Tax: {}%".format(paras[5]))
//     print(" Superannuation: {}%".format(paras[7]))
//     print(" Health Insurance: ${}/week".format(paras[6]))
//     print("\nUSER CREATED\n")
//     input("Press [Enter] to continue")  # pauses code's execution


// def getNewName():
//     print("What should the name be changed to?")
//     return input("Name: ")


// def getNewPassword(curPassword):
//     print("Current Password: {}".format(curPassword))
//     print("What should the new password be?")
//     return input("New Password: ")


// def modifyUser_getID():
//     print("What is the user ID of the employee to edit? ")
//     return input("ID: ")


// def modifyUser_S1(employeeInfo):
//     role = getRoleInfo(employeeInfo[4], 0)[1]
//     print("ID: {}".format(employeeInfo[0]))
//     print("{} - {} {}".format(role, employeeInfo[2], employeeInfo[3]))
//     print("What would you like to edit?")
//     print("\t1} First Name")
//     print("\t2} Last Name")
//     print("\t3} Role")
//     print("\t4} Tax Rate")
//     print("\t5} Health Insurance Plan")
//     print("\t6} Superannuation")
//     print("\t7} Password")
//     return input("Option Number: ")


// def modifyUser_S2():
//     print("User modification Success")
//     input("Press [Enter] to return to menu")  # pauses code's execution


// def deleteUser_S1():
//     print("What is the userID of the employee you wish to delete?")
//     return input("ID: ")


// def deleteUser_S2(employeeInfo):
//     role = getRoleInfo(employeeInfo[4], 0)[1]
//     print("ID: {}".format(employeeInfo[0]))
//     print("{} - {} {}".format(role, employeeInfo[2], employeeInfo[3]))
//     print("Delete user?")
//     print("\t1} Yes")
//     print("\t2} No")
//     return input("Option Number: ")


// def deleteUser_S3():
//     print("User has been deleted")
//     input("Press [Enter] to return to menu")  # pauses code's execution


// def modifyEmployee_S1():
//     header("Modify Employees")
//     print("Would you like to:")
//     print("\t1} Go Back")
//     print("\t2} New Employee")
//     print("\t3} Modify User")
//     print("\t4} Delete User")
//     return input("Option Number: ")


// """    SIGN IN FUNCTIONS    """


// # validation
// def validateUserID(userID):
//     # check if length is valid, then check if all characters are valid
//     id_length = getLength(userID)
//     if id_length != USER_ID_LENGTH:
//         return False
//     for character_index in range(id_length):
//         if isInVar(userID[character_index], USER_ID_CHARACTERS,
//                    False) == False:
//             return False
//     return True


// def validatePassword(password):
//     # check if length is valid, then check if all characters are valid
//     password_length = getLength(password)
//     if password_length < PASSWORD_MIN_LENGTH:
//         return False
//     for character_index in range(password_length):
//         if isInVar(password[character_index], PASSWORD_CHARS, False) == False:
//             return False
//     return True


// # calculation / unspecified
// def getSavedAuthenticationData():
//     # read file, add all user id's to 1 array, and passwords to another
//     # userID's at an index match the index of the password in password array
//     authentication_data_file = open(EMPLOYEE_DATA_FILE, "r")
//     authentication_data_read = authentication_data_file.readlines()
//     line_count = getLength(authentication_data_read)
//     user_ID_array = []
//     password_array = []
//     for line_num in range(line_count):
//         if line_num != 0:
//             line_info = splitString(authentication_data_read[line_num], ",", 2)
//             user_ID_array.append(line_info[0])
//             password_array.append(line_info[1])
//     authentication_data_file.close()
//     return [user_ID_array, password_array]


// # sign in
// def signIn():
//     valid_user_ID = \
//         getValidItem("Sign In", inputUserID_signIn, validateUserID, -1)[0]
//     # after 5 failed attempts of password, "sign out" the user
//     valid_password = \
//         getValidItem("Sign In", inputPassword_signIn, validatePassword, 5)[0]
//     user_ID_thing = isInVar(valid_user_ID, authentication_data[0], True)
//     if user_ID_thing[1] == True:
//         password_index = user_ID_thing[0]
//         if valid_password == authentication_data[1][password_index]:
//             # is match
//             authenticationScreen_Success()
//             actions(valid_user_ID)
//         else:
//             # no match
//             authenticationScreen_Failed(valid_user_ID, valid_password)
//     else:
//         # no match
//         authenticationScreen_Failed(valid_user_ID, valid_password)


// """    ACTION FUNCTIONS   """


// # validation
// def validateActionChoice(actionChoiceArray):
//     # checks if the input is numeric and between 1 and the maximum valid number for the role inclusively
//     user_option = actionChoiceArray[0]
//     max_valid = actionChoiceArray[1]
//     if isStringNumeric(user_option, False) == False:
//         return False
//     elif 0 < int(user_option) <= max_valid:
//         return True
//     return False


// def getValidAction(gname, sname, role):
//     # same structure as getValidItem
//     max_attempts = 5
//     is_valid = False
//     is_true_valid = True
//     failed_attempts_counter = 0
//     access_level = getRoleInfo(role, 3)[3]
//     while is_valid == False:
//         action_array = inputActionScreen(gname, sname, access_level)
//         is_valid = validateActionChoice(action_array)
//         if is_valid == False:
//             attempts_remaining = max_attempts - failed_attempts_counter
//             invalidScreen("Select Action", action_array[0], attempts_remaining)
//             failed_attempts_counter += 1
//         if failed_attempts_counter == max_attempts:
//             is_valid = True
//             is_true_valid = False
//             hitMaxScreen("Select Action", failed_attempts_counter)
//     return [action_array[0], is_true_valid]  # action_array will always be defined


// # actions
// def actions(userID):
//     continueAction = True
//     do_request = "CONTINUE"
//     employee_info = getEmployeeInformation(userID)
//     gname, sname, role = employee_info[2], employee_info[3], employee_info[4]
//     while continueAction == True:
//         valid_action = getValidAction(gname, sname, role)
//         action_string_number = ""
//         if valid_action[1] == False:  # max failed attemptes reached
//             do_request = "SIGN OUT"
//         else:
//             # executes the function to do what was asked by the user
//             action_string_number = valid_action[0]
//             if action_string_number == "1":  # sign out
//                 s = getValidItem("Sign Out", signOutConfirm,
//                                  validate2OptionInput, 5)
//                 if s[0] == "1" or s[1] == False:
//                     do_request = "CONTINUE"
//                 else:
//                     do_request = "SIGN OUT"
//             elif action_string_number == "2":  # manage shift
//                 manageShift(userID)
//             elif action_string_number == "3":  # view hours
//                 viewHours(userID)
//             elif action_string_number == "4":  # get user ID or name
//                 obtainUserIDOrName()
//             elif action_string_number == "5":  # pay mode
//                 payMembers()
//             elif action_string_number == "6":  # test mode
//                 testMode()
//             elif action_string_number == "7":  # modify employees
//                 modifyEmployees()
//         if do_request == "SIGN OUT":
//             # stops the loop, and "returns" back to main
//             continueAction = False


// """    MANAGE SHIFT FUNCTIONS    """


// # calculation / unspecified
// def checkActiveShifts(user_ID, activeShiftArray):
//     # the output has a boolean and the index to get the index while saying if there actually was an active shift
//     shift_counts = getLength(activeShiftArray)
//     for shift_index in range(shift_counts):
//         if activeShiftArray[shift_index][0] == user_ID:
//             return [True, shift_index]
//     return [False, 0]


// def processActiveShift(activeShiftArray):
//     # converts the array into it's .csv format
//     user_ID = activeShiftArray[0]
//     date = activeShiftArray[1]
//     time = activeShiftArray[2]
//     return "{},{},{}".format(user_ID, date, time)


// # validation
// def validateDate(dateArray):
//     day, month, year = dateArray[0], dateArray[1], dateArray[2]
//     is_day_numeric = isStringNumeric(day, False)
//     is_month_numeric = isStringNumeric(month, False)
//     is_year_numeric = isStringNumeric(year, False)
//     # checks if any of the numeric tests come back false
//     if isInVar(False, [is_day_numeric, is_month_numeric, is_year_numeric],
//                False):
//         return False
//     # converts the string into a numerical value
//     day = convertStringToNumeric(day)
//     month = convertStringToNumeric(month)
//     year = convertStringToNumeric(year)
//     if year != CURRENT_YEAR:
//         return False
//     elif (0 < month < 13) == False:
//         return False
//     # if it's a leap year then it will use the leap year month values
//     month_day_array = MONTH_DAYS
//     if year % 4 == 0:
//         month_day_array = ALT_MONTH_DAYS
//     max_day = month_day_array[month - 1]
//     if (0 < day < max_day + 1) == False:
//         return False
//     return True


// def validateStartTime(startTimeString):
//     # if no ":"s are in the string, return False
//     if isInVar(":", startTimeString, False) == False:
//         return False
//     start_time_array = splitString(startTimeString, ":", 1)
//     # if there is more than 1 ":" in the string, return False
//     if isInVar(":", start_time_array[1], False) == True:
//         return False
//     hours = start_time_array[0]
//     minutes = start_time_array[1]
//     # if either hours or minutes aren't numeric, return False
//     if isStringNumeric(hours, False) == False:
//         return False
//     if isStringNumeric(minutes, False) == False:
//         return False
//     hours = convertStringToNumeric(hours)
//     minutes = convertStringToNumeric(minutes)
//     # if either hours or minutes are in their valid ranges, return False
//     if (0 <= hours < 24) == False:
//         return False
//     if (0 <= minutes < 60) == False:
//         return False
//     return True


// def validateEndTime(startValue, endTime):
//     end_time_array = splitString(endTime, ":", 1)
//     # combines the string together, so it can be used for checking if it's numerical
//     end_time_value = end_time_array[0] + end_time_array[1]
//     if isInVar(end_time_array[1], ":", False) == True:
//         return False
//     elif isStringNumeric(end_time_value, False) == False:
//         return False
//     # converts it to it's value
//     hours_value = convertStringToNumeric(end_time_array[0]) * 60
//     minutes_value = convertStringToNumeric(end_time_array[1])
//     end_value = hours_value + minutes_value
//     # checks to see if the end time was earlier than start time, returns False in that case
//     if startValue > end_value:
//         return False
//     return True


// def getValidEndTime(start_value):
//     # same format as getValidItem
//     is_valid = False
//     is_true_valid = True
//     failed_attempts_counter = 0
//     max_attempts = 5
//     while is_valid == False:
//         header("End Shift")
//         end_time = inputEndTime()
//         is_valid = validateEndTime(start_value, end_time)
//         if is_valid == False:
//             attempts_remaining = max_attempts - failed_attempts_counter
//             invalidScreen("End Shift", end_time, attempts_remaining)
//         if failed_attempts_counter == max_attempts:
//             is_valid = True
//             is_true_valid = False
//             hitMaxScreen("End Shift", failed_attempts_counter)
//     return [end_time, is_true_valid]  # end_time will always be defined


// # file handler
// def getActiveShifts():
//     # "UserID,DATE,START_TIME\n"
//     shift_file = open(ACTIVE_SHIFT_FILE, "r+")
//     shift_file_read = shift_file.readlines()
//     array_of_shifts = []
//     line_count = getLength(shift_file_read)
//     for shift_data_index in range(line_count):
//         shift_line_data = shift_file_read[shift_data_index]
//         if shift_line_data[-1] == "\n":
//             shift_line_data = shift_line_data[:-1]
//         shift_line_data = splitString(shift_line_data, ",", 2)
//         if getLength(shift_line_data) != 0:
//             array_of_shifts.append(shift_line_data)
//     shift_file.close()
//     return array_of_shifts


// def logStartShift(user_ID, date, start_time):
//     # appends the active shift file with "USERID,DATE,STARTTIMEVALUE"
//     log_file = open(ACTIVE_SHIFT_FILE, "a+")
//     start_time_value = convertTimeToValue(start_time)
//     log_text = "{},{},{}".format(user_ID, date, start_time_value)
//     log_file.write(log_text + "\n")
//     log_file.close()


// def removeActiveShift(active_shift_array, active_shift_index):
//     to_get = active_shift_array[active_shift_index]
//     to_get_string = processActiveShift(to_get)
//     active_shifts_length = getLength(active_shift_array)
//     write_array = []
//     for i in range(active_shifts_length):
//         current_shift = active_shift_array[i]
//         if current_shift != to_get:
//             write_array.append(current_shift)
//     rewrite_length = getLength(write_array)
//     active_shift_file = open(ACTIVE_SHIFT_FILE, "w")
//     active_shift_file.close()
//     active_shift_file = open(ACTIVE_SHIFT_FILE, "a")
//     for j in range(rewrite_length):
//         active_shift_file.write(write_array[j] + "\n")


// def logHours(user_ID, date, hours_worked):
//     # appends the completed shift file with "USERID,DATE,TIMEWORKED"
//     log_file = open(SHIFT_FILE, "a+")
//     log_text = "{},{},{}".format(user_ID, date, hours_worked)
//     log_file.write(log_text + "\n")
//     log_file.close()


// # shifts
// def startShift(user_ID):
//     # controls all the functions required to start shift
//     # get start time and date
//     # log shift date and start time
//     # present start shift final screen
//     header("Start Shift")
//     shift_input_date = getValidItem("Start Shift", inputDate, validateDate, 5)
//     if shift_input_date[1] == True:
//         shift_input_time = getValidItem("Start Shift", inputStartTime,
//                                         validateStartTime, 5)
//         if shift_input_time[1] == True:
//             date = convertDateToValue(shift_input_date[0])
//             logStartShift(user_ID, date, shift_input_time[0])
//             startShiftScreen_2()


// def endShift(user_ID, active_shifts, has_active_shift):
//     # controls all the functions required to end shift
//     # get end time
//     # calculate hours worked
//     # log shift date and hours
//     # present end shift final screen
//     shift_index = has_active_shift[1]
//     start_time = active_shifts[shift_index][2]
//     start_value = convertStringToNumeric(start_time)
//     end_time = getValidEndTime(start_value)
//     if end_time[1] == True:
//         date = active_shifts[shift_index][1]
//         hours_worked = (convertTimeToValue(end_time[0]) - start_value) / 60
//         hours_worked = roundToDP(hours_worked, 2)
//         logHours(user_ID, date, hours_worked)
//         successfulLogHoursScreen(hours_worked)
//         endShiftScreen_2()


// def manageShift(user_ID):
//     # controls all functions to start and end shifts
//     # checks if user has an active shift
//     # presents endShift() if yes
//     # executes startShift() if no
//     active_shifts = getActiveShifts()
//     has_active_shift = checkActiveShifts(user_ID, active_shifts)
//     if has_active_shift[0] == True:
//         user_choice = getValidItem("Manage Shift", endShiftScreen_1,
//                                    validate2OptionInput, 5)
//         if user_choice[1] == True and user_choice[0] == "2":
//             endShift(user_ID, active_shifts, has_active_shift)
//             removeActiveShift(active_shifts, has_active_shift[1])
//     else:
//         user_choice = getValidItem("Manage Shift", startShiftScreen_1,
//                                    validate2OptionInput, 5)
//         if user_choice[1] == True and user_choice[0] == "2":
//             startShift(user_ID)


// """"    PAY MEMBER FUNCTIONS    """


// # validation
// def isUserIDReal(user_ID):
//     # searches authentication_data's user ID's to see if a user has that user ID
//     return isInVar(user_ID, authentication_data[0], False)


// def isNumericAndInWeekRange(testingFor):
//     # Literally just does what the function is called
//     if isStringNumeric(testingFor, False) == False:
//         return False
//     num = convertStringToNumeric(testingFor)
//     if (0 <= num <= 6) == False:
//         return False
//     return True


// def validateHolidayInput(holidayInput):
//     # checks if
//     input_length = getLength(holidayInput)
//     if input_length == 0: return True
//     if input_length > 13: return False  # length of "1,2,3,4,5,6,7" = 13, hence why greater than 13
//     if isInVar(",", holidayInput, False) == False:
//         return isNumericAndInWeekRange(holidayInput)
//     else:
//         # checks if all values between commas are valid
//         holidays = splitString(holidayInput, ",", 6)
//         hol_len = getLength(holidays)
//         is_valid = True
//         for i in range(hol_len):
//             is_cur_valid = isNumericAndInWeekRange(holidays[i])
//             if is_cur_valid == False:
//                 is_valid = False
//         return is_valid


// def getValidHolidayArray(dates, isTestMode):
//     # has the same structure as getValidItem()
//     header_text = "Pay Employees"
//     if isTestMode == True:
//         header_text = "Test Mode"
//     is_valid = False
//     is_true_valid = True
//     failed_attempts_counter = 0
//     max_attempts = 5
//     output = [False, False, False, False, False, False, False]
//     while is_valid == False:
//         header(header_text)
//         choice = askIfDaysAreHoliday(dates, isTestMode)
//         is_valid = validateHolidayInput(choice)
//         if is_valid == False:
//             failed_attempts_counter += 1
//             attempts_remaining = max_attempts - failed_attempts_counter
//             invalidScreen(header_text, choice, attempts_remaining)
//         if failed_attempts_counter == max_attempts:
//             is_valid = True
//             is_true_valid = False
//             hitMaxScreen(header_text, failed_attempts_counter)
//     choice_length = getLength(choice)  # choice will always be defined
//     if is_true_valid == True and choice_length != 0:
//         choice_split = splitString(choice, ",", 6)
//         choice_split_length = getLength(choice_split)
//         for i in range(choice_split_length):
//             index = convertStringToNumeric(choice_split[i])
//             output[index] = True
//     return [output, is_true_valid]


// # calculations / unspecified
// def getOvertimeSmLaHours(overtimeHours):
//     # large and small for the overtime bonus
//     # with what we have, +45% is large overtime rate, +25% is small overtime rate
//     # looking at what large and small is referring to now, you could c wot this is doing
//     large_hours = overtimeHours - OVERTIME_BONUS_HOURS
//     # if negative, set to 0, else don't change it
//     large_hours = 0 if large_hours < 0 else large_hours
//     small_hours = overtimeHours - large_hours
//     return [small_hours, large_hours]


// def calculateOvertimeHours(week_hrs_array):
//     # iterates over each weekday and gets the number of hours working overtime, 0 -> 24-standarddayhours
//     overtime_array = [0, 0, 0, 0, 0, 0, 0]
//     for hours_index in range(7):
//         overtime_hours = week_hrs_array[hours_index] - STANDARD_HOURS
//         if overtime_hours > 0:
//             overtime_array[hours_index] = overtime_hours
//     return overtime_array


// def limitHours(hours):
//     # I am unsure of the correct word, so I used "limit"
//     # This will return the hours worked set down to standard_hours
//     # example:
//     # if hours = 13, return 9  BUT  if hours = 5, return 5
//     return STANDARD_HOURS if hours > STANDARD_HOURS else hours


// def getOvertimeRates(dayIndex, isHoliday):
//     # gets the overtime rates for the day of the week or holiday
//     if dayIndex != 5 and dayIndex != 6 and isHoliday == False:
//         output = [OVERTIME_SMALL_RATE_PERCENT, OVERTIME_LARGE_RATE_PERCENT]
//     elif isHoliday == False:
//         output = [WEEKEND_OT_BONUS_PERCENT, WEEKEND_OT_BONUS_PERCENT]
//     else:
//         output = [HOLIDAY_OT_BONUS_PERCENT, HOLIDAY_OT_BONUS_PERCENT]
//     return [output[0] / 100, output[1] / 100]


// def getPayBonus(dayIndex, isHoliday):
//     pay_rate_bonus = 0
//     if dayIndex == 5:  # Saturday
//         pay_rate_bonus = SATURDAY_STANDARD_BONUS
//     elif dayIndex == 6:  # Sunday
//         pay_rate_bonus = SUNDAY_STANDARD_BONUS
//     if isHoliday == True:  # Holiday
//         pay_rate_bonus = HOLIDAY_STANDARD_BONUS
//     return pay_rate_bonus


// def getSuperValue(pay, superRate):
//     return (convertStringToNumeric(superRate) / 100) * pay


// def applyDeductions(pay, allDeductions, userID):
//     # incomplete function set, sadly
//     if allDeductions > pay:
//         # catch_up_deduction = allDeductions - pay
//         # updateCatchUpDeductionAmount(userID, catch_up_deduction)
//         return 0
//     return pay - allDeductions


// def getTaxedValue(deducted_pay, taxRate):
//     return (convertStringToNumeric(taxRate) / 100) * deducted_pay


// def calculateTimeAndWorth(workedHours, rolePayRate, holidayArray):
//     # gets how much base money a user's time was worth
//     total_pay = 0
//     total_standard_hours = 0
//     total_overtime_hours = 0
//     overtime_hrs_array = calculateOvertimeHours(workedHours)
//     role_pay_rate = convertStringToNumeric(rolePayRate)
//     for day_index in range(7):
//         hours = workedHours[day_index]
//         standard_hours = limitHours(
//             hours)  # Gets the amount of non-overtime hours worked per day
//         overtime_hours = overtime_hrs_array[day_index]
//         is_holiday = holidayArray[day_index]
//         pay_rate_bonus = getPayBonus(day_index, is_holiday)
//         standard_pay_rate = role_pay_rate + pay_rate_bonus

//         overtime_SmLa_hours = getOvertimeSmLaHours(overtime_hours)
//         overtime_rate = getOvertimeRates(day_index, is_holiday)
//         overtime_pay = 0
//         for i in range(2):
//             ot_pay_rate = (overtime_rate[i] + 1) * standard_pay_rate
//             overtime_pay += overtime_SmLa_hours[i] * ot_pay_rate

//         standard_pay = standard_hours * standard_pay_rate
//         total_pay += standard_pay + overtime_pay
//         total_standard_hours += standard_hours
//         total_overtime_hours += (
//                 overtime_SmLa_hours[0] + overtime_SmLa_hours[1])
//     return [total_pay, total_standard_hours, total_overtime_hours]


// def getHoursFromShift(userID, allShiftHours, allIndex):
//     # gets an array of dates and hours worked for each user
//     employee_count = getLength(allIndex)
//     date_count = getLength(allShiftHours)
//     obtained_hours = [[]] * date_count
//     for i in range(date_count):
//         obtained_hours[i] = ["", "0"]
//     index = 0
//     is_there = False
//     for i in range(employee_count):
//         if allIndex[i] == userID:
//             index = i
//             is_there = True
//     for date_index in range(date_count):
//         obtained_hours[date_index][0] = allShiftHours[date_index][0]
//         if is_there == True:
//             obtained_hours[date_index][1] = allShiftHours[date_index][1][index]
//     return obtained_hours


// def getHoursFromDateArray(dateArray, shiftHours):
//     # goes thru the date array (containing dates of the previous week)
//     # gets the shifts for those dates, searches for the user in those shifts
//     # and sets hours array to the hours worked in the shift
//     shift_count = getLength(shiftHours)
//     hours = [0, 0, 0, 0, 0, 0, 0]
//     for i in range(shift_count):
//         cur_shift = shiftHours[i]
//         cur_date = convertValueToDate(cur_shift[0])
//         matches_date = isInVar(cur_date, dateArray, True)
//         if matches_date[1] == True:
//             hours[matches_date[0]] = convertStringToNumeric(cur_shift[1])
//     return hours


// def getPrevWeekHoursForUser(userID, dateArray, hoursAndIDsArray):
//     # does as function name suggests
//     all_shift_hours = hoursAndIDsArray[1]
//     if all_shift_hours[0][0] == None:
//         return [0, 0, 0, 0, 0, 0, 0]
//     all_id_index = hoursAndIDsArray[0]
//     user_shift_hours = getHoursFromShift(userID, all_shift_hours, all_id_index)
//     user_prev_week_hours = getHoursFromDateArray(dateArray, user_shift_hours)
//     return user_prev_week_hours


// def getPrevWeekDates(date):
//     # uses current date, uses it to determine the day of the week
//     # it then uses the day of the week to find out how many days ago last week Monday was
//     # then gets the dates from that point until the Sunday of that week
//     day = convertStringToNumeric(date[0])
//     month = convertStringToNumeric(date[1])
//     year = convertStringToNumeric(date[2])
//     day_index = getDayOfWeekIndexFromDate(day, month, year)
//     date_value = getDateValue(date)
//     go_back_num = 7 + day_index
//     output = [[], [], [], [], [], [], []]
//     for day_index in range(7):
//         output[day_index] = getDateNDaysAgoVariant(date_value,
//                                                    go_back_num - day_index)
//     # mon = getDateNDaysAgoVariant(date_value, go_back_num)
//     # tue = getDateNDaysAgoVariant(date_value, go_back_num - 1)
//     # wed = getDateNDaysAgoVariant(date_value, go_back_num - 2)
//     # thu = getDateNDaysAgoVariant(date_value, go_back_num - 3)
//     # fri = getDateNDaysAgoVariant(date_value, go_back_num - 4)
//     # sat = getDateNDaysAgoVariant(date_value, go_back_num - 5)
//     # sun = getDateNDaysAgoVariant(date_value, go_back_num - 6)
//     # return [mon, tue, wed, thu, fri, sat, sun]
//     return output


// # file handler
// def resetPayrollFile():
//     payroll_file = open(PAY_OUTPUT_FILE, "w")
//     payroll_file.write("ID,GNAME,SNAME,ROLE,TRATE,SUPER,HLTH,MON,TUE,WED,THU,FRI,SAT,SUN,NHRS,OHRS,GROSS,SDED,HDED,TAX,NETT\n")
//     payroll_file.close()


// def resetShiftFile():
//     # opening in write mode clears the file
//     shifts_file = open(SHIFT_FILE, "w")
//     shifts_file.close()


// def logAllShifts(readlines):  # "red"lines
//     shifts_file = open(ALL_SHIFTS, "w")
//     line_count = getLength(readlines)
//     write_string = "USERID,DATEVALUE,HOURS\n"
//     for line_index in range(line_count):
//         write_string += readlines[line_index]
//     shifts_file.write(write_string)
//     shifts_file.close()


// def logEmployeePayment(userWeekSummary):
//     payroll_file = open(PAY_OUTPUT_FILE, "a")
//     week_summary_string = ""
//     for i in range(21):
//         week_summary_string += str(userWeekSummary[i]) + ","
//     week_summary_string = week_summary_string[:-1] + "\n"
//     payroll_file.write(week_summary_string)
//     payroll_file.close()


// def processShiftsHours():
//     shifts_file = open(SHIFT_FILE, "r")
//     file_data = shifts_file.readlines()

//     if getLength(file_data) == 0:
//         return [[], [[None, []]]]  # mimics the same structure as the valid output
//     if file_data[-1] == "\n" or file_data[-1] == "":
//         file_data = file_data[:-1]
//     # ["UserID,Day/Month/Year,hoursWorked", UserID,Day/Month/Year,hoursWorked"]

//     """
//     literally just getting this output:
//     [
//         [user1ID, user2ID, user3ID, ...],
//         [
//             [
//                 date1, [user1hours, user2hours, user3hours, ...]
//             ],
//             [
//                 date2, [user1hours, user2hours, user3hours, ...]
//             ],
//             ...
//         ]
//     ]
//     """

//     user_IDs = []
//     dates = []

//     user_id_count = 0
//     date_count = 0

//     line_count = getLength(file_data)
//     for line_index in range(line_count):
//         cur_line = (file_data[line_index]).strip()
//         cur_line_split = splitString(cur_line, ",", 2)
//         cur_id = cur_line_split[0]
//         cur_date = cur_line_split[1]
//         if isInVar(cur_id, user_IDs, False) == False:
//             user_IDs.append(cur_id)
//             user_id_count += 1
//         is_in_dates = isInVar(cur_date, dates, True)
//         if is_in_dates[1] == False:
//             dates.append(cur_date)
//             date_count += 1

//     date_hours = [[]] * date_count
//     for i in range(date_count):
//         date_hours[i] = [[], ["0"] * user_id_count]
//     for line_index in range(line_count):
//         cur_line = (file_data[line_index]).strip()
//         cur_line_split = splitString(cur_line, ",", 2)
//         cur_id = cur_line_split[0]
//         cur_date = cur_line_split[1]
//         cur_hours = cur_line_split[2]
//         date_index = getFirstPositionOfObject(cur_date, dates)[0]
//         user_index = getFirstPositionOfObject(cur_id, user_IDs)[0]
//         date_hours[date_index][1][user_index] = cur_hours
//         date_hours[date_index][0] = cur_date
//     shifts_file.close()
//     return [user_IDs, date_hours]


// def getCatchUpDeductionAmount(userID):
//     # incomplete function set
//     deduction_file = open(DEDUCTION_FILE, "r")
//     deduction_file_data = deduction_file.readlines()

//     file_length = getLength(deduction_file_data)
//     deduction_amount = 0
//     for i in range(file_length):
//         current_line = deduction_file_data[i].strip()
//         split_line = splitString(current_line, ",", 1)
//         cur_user_ID = split_line[0]
//         if cur_user_ID == userID:
//             deduction_amount = convertStringToNumeric(split_line[1])
//     deduction_file.close()
//     return deduction_amount


// def updateCatchUpDeductionAmount(userID, catchUpAmount):
//     # incomplete function group
//     deduction_file = open(DEDUCTION_FILE, "r")
//     deduction_file_data = deduction_file.readlines()

//     file_length = getLength(deduction_file_data)
//     rewrite = ""
//     is_user_present = False
//     for i in range(file_length):
//         current_line = deduction_file_data[i].strip()
//         split_line = splitString(current_line, ",", 1)
//         cur_user_ID = split_line[0]
//         if cur_user_ID == userID:
//             rewrite += "{},{}\n".format(userID, catchUpAmount)
//             is_user_present = True
//         else:
//             rewrite += "{}\n".format(current_line)
//     if is_user_present == False:
//         rewrite += "{},{}\n".format(userID, catchUpAmount)
//     deduction_file.close()
//     deduction_file = open(DEDUCTION_FILE, "w")
//     deduction_file.write(rewrite)
//     deduction_file.close()


// # paying
// def getUserWeekSummary(user_ID, prevWeekHours, holidayArray):
//     # gets a FULL user's week summary
//     # Every value required for the output file
//     employee_info = getEmployeeInformation(user_ID)
//     role_info = getRoleInfo(employee_info[4], 0)
//     role_pay_rate = role_info[2]
//     time_info = calculateTimeAndWorth(prevWeekHours, role_pay_rate, holidayArray)
//     gross_pay = time_info[0]

//     super_plan = employee_info[7]
//     super_rate = read2DArrayItem(SUPERANNUATION, super_plan, 0)[1]
//     tax_rate_ID = employee_info[5]
//     tax_rate = read2DArrayItem(TAX_RATE, tax_rate_ID, 0)[1]

//     super_deduction = getSuperValue(gross_pay, super_rate)
//     health_info = read2DArrayItem(HEALTH_INSURANCE, employee_info[6], 0)
//     health_value = convertStringToNumeric(health_info[1])
//     health_deduction = health_value
//     # catch_up_deduction = getCatchUpDeductionAmount(user_ID)
//     total_deduction = super_deduction + health_value  # + catch_up_deduction

//     pay = applyDeductions(gross_pay, total_deduction, user_ID)
//     total_deducted_amount = gross_pay - pay

//     tax_value = getTaxedValue(pay, tax_rate)

//     final_pay = pay - tax_value

//     if pay == 0:
//         health_deduction = 0

//     # ID,GNAME,SNAME,ROLE,TRATE,SUPER,HLTH,MON,TUE,WED,THU,FRI,SAT,SUN,NHRS,OHRS,GROSS,SDED,HDED,TAX,NETT
//     user_week_summary = [
//         user_ID,
//         employee_info[2],
//         employee_info[3],
//         role_info[0],
//         tax_rate,
//         super_rate,
//         health_value,
//         prevWeekHours[0],
//         prevWeekHours[1],
//         prevWeekHours[2],
//         prevWeekHours[3],
//         prevWeekHours[4],
//         prevWeekHours[5],
//         prevWeekHours[6],
//         roundToDP(time_info[1], 2),
//         roundToDP(time_info[2], 2),
//         roundToDP(gross_pay, 2),
//         roundToDP(super_deduction, 2),
//         roundToDP(health_deduction, 2),
//         roundToDP(tax_value, 2),
//         roundToDP(final_pay, 2),
//         total_deducted_amount
//     ]
//     return user_week_summary


// def payIndividual(prev_week_dates, holidayArray):
//     # does all the functions required to pay an individual
//     user = getValidItem("Pay Individual", payIndividual_S1, isUserIDReal, 5)
//     if user[1] == False:
//         return "BACK"  # just a null statement to escape the function
//     else:
//         hours_and_ids_array = processShiftsHours()
//         user_ID = user[0]
//         hours = getPrevWeekHoursForUser(user_ID, prev_week_dates,
//                                         hours_and_ids_array)
//         week_summary = getUserWeekSummary(user_ID, hours, holidayArray)
//         employee_info = getEmployeeInformation(user_ID)
//         role_pay_rate = getRoleInfo(employee_info[4], 0)[2]
//         payIndividual_S2(week_summary, role_pay_rate, prev_week_dates)


// def payAll(prev_week_dates, holidayArray):
//     # does all the functions required to pay all members
//     payAllScreen_1()
//     resetPayrollFile()
//     user_ID_array = authentication_data[0]
//     user_ID_count = getLength(user_ID_array)
//     hours_and_ids_array = processShiftsHours()
//     for i in range(user_ID_count):
//         user_ID = user_ID_array[i]
//         hours = getPrevWeekHoursForUser(user_ID, prev_week_dates,
//                                         hours_and_ids_array)
//         week_summary = getUserWeekSummary(user_ID, hours, holidayArray)
//         logEmployeePayment(week_summary)
//     file_data = open(SHIFT_FILE, "r")
//     read_file_data = file_data.readlines()
//     resetShiftFile()
//     logAllShifts(read_file_data)
//     file_data.close()
//     payAllScreen_2()


// def payMembers():
//     # do all functions required to pay members; all or individual
//     user_choice = getValidItem("Pay Members", payMembers_S1,
//                                validate2OptionInput, 5)
//     if user_choice[1] == False or user_choice[0] == "1":
//         return "BACK"  # just a null statement to escape the function
//     user_choice2 = getValidItem("Pay Members", payMembers_S2,
//                                 validate2OptionInput, 5)
//     if user_choice2[1] == False:
//         return "BACK"  # just a null statement to escape the function
//     date = getValidItem("Pay Members", inputDate, validateDate, 5)
//     if date[1] == True:
//         prev_week_dates = getPrevWeekDates(
//             date[0])  # array in [dd, mm, yyyy] format
//         holidays = getValidHolidayArray(prev_week_dates, False)
//         if holidays[1] == True:
//             if user_choice2[0] == "1":
//                 payIndividual(prev_week_dates, holidays[0])
//             else:
//                 payAll(prev_week_dates, holidays[0])


// """    TEST MODE    """


// # validation
// def isRoleValid(userRole):
//     if isInVar(userRole, VALID_ROLES, False) == True:
//         return True
//     return False


// def isTaxRateValid(taxRate):
//     if isStringNumeric(taxRate, False) == True:
//         tax_num = convertStringToNumeric(taxRate)
//         if isInVar(tax_num, VALID_TAX_RATES, False):
//             return True
//     return False


// def isSuperValid(superRate):
//     if isStringNumeric(superRate, False) == True:
//         super_num = convertStringToNumeric(superRate)
//         if isInVar(super_num, VALID_SUPER_RATES, False):
//             return True
//     return False


// def isHealthValid(healthCost):
//     if isStringNumeric(healthCost, False) == True:
//         health_num = convertStringToNumeric(healthCost)
//         if isInVar(health_num, VALID_HLTH_RATES, False):
//             return True
//     return False


// def isHoursValid(dayHours):
//     if isStringNumeric(dayHours, True) == True:
//         day_hours = convertStringToNumeric(dayHours)
//         if (0 <= day_hours < 24) == True:
//             return True
//     return False


// def isNameValid(name):
//     name_len = getLength(name)
//     if name_len == 0:
//         return False
//     if isStringNumeric(name, True) == True:
//         return False
//     for i in range(name_len):
//         if isInVar(name[i], VALID_NAME_CHARS, False) == False:
//             return False
//     return True


// # file handler
// def logFailedLines(invalidLines):
//     start_text = "GNAME,SNAME,ROLE,TRATE,SUPER,HLTH,MON,TUE,WED,THU,FRI,SAT,SUN,\n"
//     log_file = open(LOG_FILE, "w")
//     log_file.write(start_text + invalidLines)
//     log_file.close()


// def logTestPayment(userWeekSummary):
//     output_file = open(TEST_OUTPUT, "a")
//     week_summary_string = ""
//     for i in range(22):
//         week_summary_string += str(userWeekSummary[i]) + ","
//     week_summary_string = week_summary_string[:-1] + "\n"
//     output_file.write(week_summary_string)
//     output_file.close()


// def readTestFile():
//     test_file_data = open(TEST_DATA_FILE, "r")
//     test_data = test_file_data.readlines()
//     lines = getLength(test_data)
//     for i in range(lines):
//         test_data[i] = test_data[i].strip()
//     return test_data


// def processValidTestLines(validTestLines):
//     lines = getLength(validTestLines)
//     header_txt = "ID,GNAME,SNAME,ROLE,TRATE,SUPER,HLTH,MON,TUE,WED,THU,FRI,SAT,SUN,NHRS,OHRS,GROSS,SDED,HDED,TAX,NETT,CATCHUPDEDUCTION\n"
//     output_file = open(TEST_OUTPUT, "w")
//     output_file.write(header_txt)
//     output_file.close()

//     isHoliday_array = getValidHolidayArray([], True)[0]

//     for line_index in range(lines):
//         cur_line = validTestLines[line_index]
//         hours = [0, 0, 0, 0, 0, 0, 0]
//         for weekDayNum in range(7):
//             hours[weekDayNum] = convertStringToNumeric(
//                 cur_line[6 + weekDayNum])
//         user_id = fillWithZeros(str(line_index), 8)
//         user_summary = getUserWeekSummaryTestMode(cur_line, user_id,
//                                                   isHoliday_array)
//         logTestPayment(user_summary)


// # calculations / unspecified
// def getValidTestLines(testData):
//     testData = testData[1:]
//     lines = getLength(testData)
//     lines_to_log = ""
//     valid_lines = []
//     was_any_invalid = False
//     for line_index in range(lines):
//         cur_line1 = testData[line_index].strip()
//         if cur_line1[-1] == ",":
//             cur_line1 = cur_line1[:-1]
//         cur_line2 = splitString(cur_line1, ",", 13)
//         valid_array = [False, False, False, False, False, False, False, False,
//                        False, False, False, False, False]
//         valid_array[0] = isNameValid(cur_line2[0])
//         valid_array[1] = isNameValid(cur_line2[1])
//         valid_array[2] = isRoleValid(cur_line2[2])
//         valid_array[3] = isTaxRateValid(cur_line2[3])
//         valid_array[4] = isSuperValid(cur_line2[4])
//         valid_array[5] = isHealthValid(cur_line2[5])
//         for day_index in range(
//                 7):  # I could do range(6, 13), but it wouldn't fit variable's name
//             valid_array[6 + day_index] = isHoursValid(cur_line2[6 + day_index])
//         if isInVar(False, valid_array, False) == True:
//             lines_to_log += cur_line1 + "\n"
//             was_any_invalid = True
//         else:
//             valid_lines.append(cur_line2)
//     if was_any_invalid == True:
//         logFailedLines(lines_to_log)
//     return [valid_lines, lines_to_log]


// def getUserWeekSummaryTestMode(userTestLine, userID, isHolidayArray):
//     role_info = getRoleInfo(userTestLine[2], 1)
//     role_pay_rate = role_info[2]
//     hours = [0] * 7
//     for dayIndex in range(7):
//         hours[dayIndex] = convertStringToNumeric(userTestLine[6 + dayIndex])
//     time_info = calculateTimeAndWorth(hours, role_pay_rate, isHolidayArray)
//     gross_pay = time_info[0]
//     tax_rate = convertStringToNumeric(userTestLine[3])
//     super_rate = convertStringToNumeric(userTestLine[4])
//     health_value = convertStringToNumeric(userTestLine[5])
//     health_deduction = health_value
//     super_deduction = (super_rate / 100) * gross_pay
//     total_deduction = super_deduction + health_value

//     pay = gross_pay - total_deduction
//     future_deduction_amount = 0
//     if total_deduction > gross_pay:
//         pay = 0
//         future_deduction_amount = total_deduction
//         total_deduction = 0
//         health_deduction = 0

//     tax_value = (tax_rate / 100) * pay
//     final_pay = pay - tax_value

//     # ID,GNAME,SNAME,ROLE,TRATE,SUPER,HLTH,MON,TUE,WED,THU,FRI,SAT,SUN,NHRS,OHRS,GROSS,SDED,HDED,TAX,NETT
//     user_week_summary = [
//         userID,
//         userTestLine[0],
//         userTestLine[1],
//         role_info[0],
//         tax_rate,
//         super_rate,
//         health_value,
//         hours[0],
//         hours[1],
//         hours[2],
//         hours[3],
//         hours[4],
//         hours[5],
//         hours[6],
//         time_info[1],
//         time_info[2],
//         gross_pay,
//         super_deduction,
//         health_deduction,
//         roundToDP(tax_value, 2),
//         roundToDP(final_pay, 2),
//         future_deduction_amount
//     ]
//     return user_week_summary


// # testing
// def testMode():
//     test_data = readTestFile()
//     valid_test_data = getValidTestLines(test_data)
//     processValidTestLines(valid_test_data[0])
//     is_any_invalid = getLength(valid_test_data[1]) > 0
//     testMode_finish(is_any_invalid)
//     return "CONTINUE"


// """    GET USERID OR NAME FUNCTIONS    """


// # obtaining
// def obtainUserID():
//     first_name = getValidItem("Get User ID", getEmployeeFirstName, isNameValid,
//                               5)
//     if first_name[1] == False:
//         return "BACK"  # just a null statement to escape the function
//     last_name = getValidItem("Get User ID", getEmployeeLastName, isNameValid,
//                              5)
//     if last_name[1] == False:
//         return "BACK"  # just a null statement to escape the function
//     employee_info = getEmployeeInformationFromName(first_name[0], last_name[0])
//     if getLength(employee_info) == 0:
//         obtainUserID_S1(first_name[0], last_name[0])
//     else:
//         obtainUserID_S2(employee_info[0], first_name[0], last_name[0])


// def obtainEmployeeName():
//     userID = getValidItem("Get Employee's Name", getEmployeeUserID,
//                           validateUserID, 5)
//     if userID[1] == False:
//         return "BACK"  # just a null statement to escape the function
//     employee_info = getEmployeeInformation(userID[0])
//     if getLength(employee_info) == 0:
//         obtainEmployeeName_S1(userID[0])
//     else:
//         obtainEmployeeName_S2(userID[0], employee_info[2], employee_info[3])


// def obtainUserIDOrName():
//     user_choice = getValidItem("Actions", determineObtainAction,
//                                validate3OptionInput, 5)
//     if user_choice[1] == True:
//         actual_choice = user_choice[0]
//         if actual_choice == "1":  # I could just remove this as it's not too necessary
//             return "GOBACK"  # just a null statement to escape the function
//         elif actual_choice == "2":
//             obtainUserID()
//         else:
//             obtainEmployeeName()


// """    VIEW HOURS FUNCTIONS    """


// # file handler
// def getLogFileData():
//     # does what the function name suggests
//     all_shifts = open(ALL_SHIFTS, "r")
//     file_data = (all_shifts.readlines())[1:]
//     line_count = getLength(file_data)
//     for line_index in range(line_count):
//         file_data[line_index] = file_data[line_index].strip()
//     return file_data


// # calculations / unspecified
// def filterFileData(fileData, userID):
//     # filters all the hours data to get only the hours associated with userID
//     line_count = getLength(fileData)
//     filtered_array = []
//     for line_index in range(line_count):
//         cur_line = fileData[line_index]
//         cur_line_split = splitString(cur_line, ",", 2)
//         if cur_line_split[0] == userID:
//             date_value = cur_line_split[1]
//             hours = convertStringToNumeric(cur_line_split[2])
//             filtered_array.append([date_value, hours])
//     return filtered_array


// def processFilteredData(filteredData):
//     # week_hours is the sum of all shifts an employee has made for each day of the week
//     # worked_days_count is the number of total shifts for each day of the week
//     # this function fills in those 2 arrays and outputs the average of it
//     date_count = getLength(filteredData)
//     week_hours = [0, 0, 0, 0, 0, 0, 0]
//     worked_days_count = [0, 0, 0, 0, 0, 0, 0]
//     for date_index in range(date_count):
//         shift_line = filteredData[date_index]
//         date = convertValueToDate(shift_line[0])
//         hours = shift_line[1]
//         weekday_index = getDayOfWeekIndexFromDate(date[0], date[1], date[2])
//         week_hours[weekday_index] += hours
//         worked_days_count[weekday_index] += 1
//     average_hours = [0, 0, 0, 0, 0, 0, 0]
//     for i in range(7):
//         average_hours[i] = roundToDP(week_hours[i] / worked_days_count[i], 2)
//     return average_hours


// # view hours
// def viewHours(userID):
//     # does all the functions to view hours
//     log_file_data = getLogFileData()
//     filtered_data = filterFileData(log_file_data, userID)
//     average_hours = processFilteredData(filtered_data)
//     viewHours_S1(average_hours)


// """    MODIFY EMPLOYEES    """


// # validation
// def getValidCreateUser(inputFunction, validationFunction, parameterArray):
//     # same structure as getValidInput
//     is_valid = False
//     is_true_valid = True
//     failed_attempts_counter = 0
//     max_attempts = 5
//     while is_valid == False:
//         header("Create User")
//         choice = inputFunction(parameterArray)
//         is_valid = validationFunction(choice)
//         if is_valid == False:
//             failed_attempts_counter += 1
//             attempts_remaining = max_attempts - failed_attempts_counter
//             invalidScreen("Create User", choice, attempts_remaining)
//         if failed_attempts_counter == max_attempts:
//             is_valid = True
//             is_true_valid = False
//             hitMaxScreen("Create User", failed_attempts_counter)
//     return [choice, is_true_valid]  # choice will always be defined


// def getValidModifyValue(employeeInfo):
//     # same structure as getValidInput
//     is_valid = False
//     is_true_valid = True
//     failed_attempts_counter = 0
//     max_attempts = 5
//     while is_valid == False:
//         header("Modify User")
//         choice = modifyUser_S1(employeeInfo)
//         is_valid = validate7OptionInput(choice)
//         if is_valid == False:
//             failed_attempts_counter += 1
//             attempts_remaining = max_attempts - failed_attempts_counter
//             invalidScreen("Modify User", choice, attempts_remaining)
//         if failed_attempts_counter == max_attempts:
//             is_valid = True
//             is_true_valid = False
//             hitMaxScreen("Modify User", failed_attempts_counter)
//     return [choice, is_true_valid]  # choice will always be defined


// def getValidDeleteUser(parameterArray):
//     # same structure as getValidInput
//     is_valid = False
//     is_true_valid = True
//     failed_attempts_counter = 0
//     max_attempts = 3
//     while is_valid == False:
//         header("Delete User")
//         choice = deleteUser_S2(parameterArray)
//         is_valid = validate2OptionInput(choice)
//         if is_valid == False:
//             failed_attempts_counter += 1
//             attempts_remaining = max_attempts - failed_attempts_counter
//             invalidScreen("Delete User", choice, attempts_remaining)
//         if failed_attempts_counter == max_attempts:
//             is_valid = True
//             is_true_valid = False
//             hitMaxScreen("Delete User", failed_attempts_counter)
//     return [choice, is_true_valid]  # choice will always be defined


// # file handler
// def addNewUser(userDetails):
//     # appends the employee data file
//     write_string = "\n"
//     for user_dets_index in range(8):
//         write_string += userDetails[user_dets_index] + ","
//     write_string = write_string[:-1]
//     employee_file = open(EMPLOYEE_DATA_FILE, "a")
//     employee_file.write(write_string)
//     employee_file.close()


// def getNewUserID():
//     # auto creates a new user ID
//     # I don't have access to random library
//     # Most pseudo-random numbers I don't feel are too applicable to this application
//     # Due to needing uniqueness and no repetition (in the long run)
//     employee_file = open(EMPLOYEE_DATA_FILE, "r")
//     lines = employee_file.readlines()
//     line_count = getLength(lines)
//     employee_file.close()
//     return fillWithZeros(str(line_count), 8)


// def updateModifiedUser(modifiedArray):
//     employee_data = open(EMPLOYEE_DATA_FILE, "r")
//     file_data = employee_data.readlines()[1:]
//     employee_count = getLength(file_data)
//     rewrite_string = "ID,PWRD,GNAME,SNAME,ROLEID,TRATE,HLTH,SUPER\n"
//     for employee_index in range(employee_count):
//         cur_line = file_data[employee_index].strip()
//         split_cur_line = splitString(cur_line, ",", 1)
//         if split_cur_line[0] == modifiedArray[0]:
//             rewrite_string += mergeArray(modifiedArray, ",") + "\n"
//         else:
//             rewrite_string += cur_line + "\n"
//     employee_data.close()
//     employee_data = open(EMPLOYEE_DATA_FILE, "w")
//     employee_data.write(rewrite_string)
//     employee_data.close()


// # calculations / unspecified
// def fixUserValues(userArray):
//     # when I was creating a new user, TRATE, ROLEID, SUPER, HLTH were all the wrong identifier type
//     # eg "Team Member" instead of "1" (1 being the ROLEID)
//     # eg "30" instead of "Standard" for tax
//     # eg "45" instead of "Superior" for hlth
//     # eg "4" instead of "Low" for super
//     # This function acts to counteract this
//     roleID = getRoleInfo(userArray[4], 1)[0]
//     output = [""] * 8
//     for i in range(4):
//         output[i] = userArray[i]
//     tax_name = read2DArrayItem(TAX_RATE, userArray[5], 1)[0]
//     health_name = read2DArrayItem(HEALTH_INSURANCE, userArray[6], 1)[0]
//     super_name = read2DArrayItem(SUPERANNUATION, userArray[7], 1)[0]
//     output[4] = roleID
//     output[5] = tax_name
//     output[6] = health_name
//     output[7] = super_name
//     return output


// def alterUser(userInfo, alteringIndex):
//     # uses the valid user input of what they want to modify
//     # it then executes the function that will do the modification
//     # returns the new user data
//     h_text = "Modify User"
//     if alteringIndex == "1":
//         gname = getValidItem(h_text, getNewName, isNameValid, 5)
//         if gname[1] == True:
//             userInfo[2] = gname[0]
//     elif alteringIndex == "2":
//         sname = getValidItem(h_text, getNewName, isNameValid, 5)
//         if sname[1] == True:
//             userInfo[3] = sname[0]
//     elif alteringIndex == "3":
//         role = getValidItem(h_text, role_S1, validate3OptionInput, 5)
//         if role[1] == True:
//             userInfo[4] = role[0]
//     elif alteringIndex == "4":
//         trte = getValidItem(h_text, trate_S1, validate2OptionInput, 5)
//         if trte[1] == True:
//             userInfo[5] = read2DArrayItem(TAX_RATE, trte[0], 2)[1]
//     elif alteringIndex == "5":
//         hlth = getValidItem(h_text, health_S1, validate3OptionInput, 5)
//         if hlth[1] == True:
//             userInfo[6] = read2DArrayItem(HEALTH_INSURANCE, hlth[0], 2)[1]
//     elif alteringIndex == "6":
//         sper = getValidItem(h_text, super_S1, validate3OptionInput, 5)
//         if sper[1] == True:
//             userInfo[7] = read2DArrayItem(SUPERANNUATION, sper[0], 2)[1]
//     elif alteringIndex == "7":
//         pswrd = getValidItem(h_text, getNewPassword, validatePassword, 5)
//         if pswrd[1] == True:
//             userInfo[1] = pswrd[0]
//     return userInfo


// def finaliseUserDeletion(userInfo):
//     # reads every user from employee data file
//     # rewrites all data excluding the user to delete
//     # then appends the user data to a deleted_employees_file
//     employee_data = open(EMPLOYEE_DATA_FILE, "r")
//     file_data = employee_data.readlines()[1:]
//     employee_count = getLength(file_data)
//     rewrite_string = "ID,PWRD,GNAME,SNAME,ROLEID,TRATE,HLTH,SUPER\n"
//     for employee_index in range(employee_count):
//         cur_line = file_data[employee_index].strip()
//         split_cur_line = splitString(cur_line, ",", 1)
//         if split_cur_line[0] != userInfo[0]:
//             rewrite_string += cur_line + "\n"
//     employee_data.close()
//     employee_data = open(EMPLOYEE_DATA_FILE, "w")
//     employee_data.write(rewrite_string)
//     employee_data.close()
//     deleteFile = open(DELETED_EMPLOYEES_FILE, "a")
//     deleteFile.write(mergeArray(userInfo, ",") + "\n")
//     deleteFile.close()


// # modify employees
// def createUser():
//     # this function gets valid input for EVERY single thing stored in employee data
//     # "ID,PWRD,GNAME,SNAME,ROLEID,TRATE,HLTH,SUPER"
//     # then it appends the employee info to the employeeData file
//     # it just does what ever is needed to create a new user and store it
//     parameter_array = ["", "", "", "", "", "", "", ""]
//     parameter_array[0] = getNewUserID()
//     gname = getValidCreateUser(createUser_gname_S1, isNameValid,
//                                parameter_array)
//     if gname[1] == False:
//         return "BACK"  # not a null statement
//     parameter_array[2] = gname[0]
//     sname = getValidCreateUser(createUser_sname_S1, isNameValid,
//                                parameter_array)
//     if sname[1] == False:
//         return "BACK"  # not a null statement
//     parameter_array[3] = sname[0]
//     role_id = getValidCreateUser(createUser_role_S1, validate3OptionInput,
//                                  parameter_array)
//     if role_id[1] == False:
//         return "BACK"  # not a null statement
//     parameter_array[4] = getRoleInfo(role_id[0], 0)[1]
//     tax_num = getValidCreateUser(createUser_trate_S1, validate2OptionInput,
//                                  parameter_array)
//     if tax_num[1] == False:
//         return "BACK"  # not a null statement
//     parameter_array[5] = read2DArrayItem(TAX_RATE, tax_num[0], 2)[1]
//     health_insurance = getValidCreateUser(createUser_health_S1,
//                                           validate3OptionInput,
//                                           parameter_array)
//     if health_insurance[1] == False:
//         return "BACK"  # not a null statement
//     parameter_array[6] = \
//         read2DArrayItem(HEALTH_INSURANCE, health_insurance[0], 2)[1]
//     superannuation = getValidCreateUser(createUser_super_S1,
//                                         validate3OptionInput, parameter_array)
//     if superannuation[1] == False:
//         return "BACK"  # not a null statement
//     parameter_array[7] = read2DArrayItem(SUPERANNUATION, superannuation[0], 2)[
//         1]
//     confirmation = getValidCreateUser(createUser_confirm_S1,
//                                       validate2OptionInput, parameter_array)
//     if confirmation[1] == False or confirmation[0] == "2":
//         return "RELOOP"  # reloops the this function
//     password = getValidItem("Create User", createUser_password_S1,
//                             validatePassword, 5)
//     if password[1] == False:
//         return "BACK"  # not a null statement
//     parameter_array[1] = password[0]
//     fixed_parameter_array = fixUserValues(parameter_array)
//     addNewUser(fixed_parameter_array)
//     createUser_finished_S1(parameter_array)
//     global authentication_data
//     authentication_data = getSavedAuthenticationData()
//     return "CONTINUE"


// def modifyUser():
//     # does everything required to modify user data
//     # gets a valid user id to modify
//     # then asks what to modify
//     # gets a valid input for what to change it to
//     # then writes it to the employee data file
//     h_text = "Modify User"
//     userID = getValidItem(h_text, modifyUser_getID, validateUserID, 5)
//     if userID[1] == False:
//         return "BACK"  # just a null statement to escape the function
//     if isUserIDReal(userID[0]) == False:
//         print("User Doesn't Exist. Please check if your input is correct and try again")
//         input("Press [Enter] to go to menu")  # goes to menu in case they need to get user ID
//     employee_info = getEmployeeInformation(userID[0])
//     modify_option = getValidModifyValue(employee_info)
//     if modify_option[1] == False:
//         return "BACK"  # just a null statement to escape the function
//     updated_user = alterUser(employee_info, modify_option[0])
//     updateModifiedUser(updated_user)
//     modifyUser_S2()
//     return "CONTINUE"


// def deleteUser():
//     # does what is needed to delete a user
//     # It gets what user to delete, gets confirmation and deletes the user
//     userID = getValidItem("Delete User", deleteUser_S1, isUserIDReal, 5)
//     if userID[1] == False:
//         return "BACK"
//     employee_info = getEmployeeInformation(userID[0])
//     delete_user = getValidDeleteUser(employee_info)
//     if delete_user[1] == False:
//         return "BACK"
//     if delete_user[0] == "1":
//         finaliseUserDeletion(employee_info)
//         deleteUser_S3()
//     return "CONTINUE"


// def modifyEmployees():
//     # controls modifying user, deleting user and creating a user
//     # gets what action is requested and executes the function required to do it
//     choice = getValidItem("Modify Employees", modifyEmployee_S1,
//                           validate4OptionInput, 5)
//     if choice[1] == False or choice[0] == "1":
//         return "BACK"
//     elif choice[0] == "2":
//         stop_looping = False
//         while stop_looping == False:
//             do_request = createUser()
//             if do_request != "RELOOP" or do_request == "BACK":  # could also be "CONTINUE"
//                 stop_looping = True
//         return "CONTINUE"
//     elif choice[0] == "3":
//         return modifyUser()
//     elif choice[0] == "4":
//         return deleteUser()


// """    MAIN FUNCTION    """


// def main():
//     while True:
//         global authentication_data  # userID and password arrays
//         authentication_data = getSavedAuthenticationData()
//         signIn()


// main()

// # This is the structure I was using as a guideline

// # Sign in
// #   # Input user ID
// #   # Validate for user ID
// #       ## VALID
// #           # Input password
// #           # Validate for password
// #               ## VALID
// #                   # Search for match in file
// #                       ## MATCH
// #                           # Present successful sign in screen
// #                           # Ask for action (of the following)
// #                               ## SIGN OUT
// #                                   # Return to screen prior to sign-in, or just to the sign in screen
// #                               ## MANAGE SHIFT
// #                                   # Check if user has an active shift
// #                                       ## TRUE
// #                                           # Ask for action (go back, end shift)
// #                                               ## GO BACK
// #                                                   # Return to action screen {BACK}
// #                                               ## END SHIFT
// #                                                   # Input shift end time
// #                                                   # Validate for time
// #                                                       ## VALID
// #                                                           # Get shift start time
// #                                                           # Check if end time is after start time (could calculate time difference here and do time_dif > 0)
// #                                                               ## TRUE
// #                                                                   # Log hours worked
// #                                                                   # Present Log Hours Success Screen
// #                                                                   # Return to action screen {BACK}
// #                                                               ## FALSE
// #                                                                   # Present Invalid Input Screen
// #                                                                   # Return to end shift screen {LOOP}
// #                                                       ## INVALID
// #                                                           # Present Invalid Input Screen
// #                                                           # Return to end shift screen {LOOP}
// #                                       ## FALSE
// #                                           # Ask for action (go back, start shift)
// #                                               ## GO BACK
// #                                                   # Return to action screen {BACK}
// #                                               ## START SHIFT
// #                                                   # Input Shift Date
// #                                                   # Check if date is valid
// #                                                       ## TRUE
// #                                                           # Input start time
// #                                                           # Validate for time
// #                                                               ## VALID
// #                                                                   # Log start time
// #                                                                   # Log shift date
// #                                                                   # Present welcome employee screen
// #                                                                   # Return to action screen {BACK}
// #                                                               ## INVALID
// #                                                                   # Present Invalid Input Screen
// #                                                                   # Return to get start time screen {BACK}
// #                                                       ## FALSE
// #                                                           # Present Invalid Input Screen
// #                                                           # Return to start shift screen {BACK}
// #                               ## VIEW HOURS
// #                                   # Get hours worked for user from full log file
// #                                   # Calculate average hours spent per weekday only for days worked
// #                                   # Present average hours screen
// #                                   # Return to action screen {BACK}
// #                               ## GET USER ID OR NAME
// #                                   # Ask for action (go back, get user ID, get employee name)
// #                                       ## GO BACK
// #                                           # Return to action screen {BACK}
// #                                       ## USER ID
// #                                           # Input user ID
// #                                           # Validate for User ID
// #                                               ## VALID
// #                                                   # Search for match in file
// #                                                   # Get Name
// #                                                   # Present Name Screen
// #                                                   # Return to action screen {BACK}
// #                                               ## INVALID
// #                                                   # Present Invalid Input Screen
// #                                                   # Return to get user ID screen {BACK}
// #                                       ## EMPLOYEE NAME
// #                                           # Input Employee's First Name / G Name
// #                                           # Input Employee's Last Name / S Name
// #                                           # Validate for name
// #                                               ## VALID
// #                                                   # Search for match in file
// #                                                   # Get User ID
// #                                                   # Present User ID screen
// #                                                   # Return to action screen {BACK}
// #                                               ## INVALID
// #                                                   # Present Invalid Input Screen
// #                                                   # Return to get employee name screen {BACK}
// #                               ## PAY MEMBERS
// #                                   # Ask for action (go back, individual, everyone)
// #                                       ## GO BACK
// #                                           # Return to action screen {BACK}
// #                                       ## INDIVIDUAL
// #                                           # Input User ID
// #                                           # Validate for User ID
// #                                               ## VALID
// #                                                   # Get previous week hours and dates (could ask for today's date)
// #                                                   # Get relevant holiday dates (could loop thru each week date and check if it's a holiday)
// #                                                   # Get employee details; role, superannuation, tax rate, health insurance plan
// #                                                   # Get values from employee details; role pay, superannuation, tax rate, health insurance
// #                                                   # Calculate day pay for each day of the week; utilise the above {FUNCTION SET}
// #                                                   # Calculate net pay {FUNCTION SET}
// #                                                   # Present user pay screen
// #                                                   # Return to action screen {BACK}
// #                                               ## INVALID
// #                                                   # Present Invalid Input Screen
// #                                                   # Return to individual pay screen {BACK}
// #                                       ## EVERYONE
// #                                           # Get previous week hour for all employees (could ask for today's date)
// #                                           # do above actions for ## INDIVIDUAL / ## VALID /
// #                               ## TEST MODE
// #                                   # stuff
// #                               ## MODIFY EMPLOYEES
// #                                   # Ask for action (go back, create user, modify user, delete user)
// #                                       ## GO BACK
// #                                           # Return to action screen {BACK}
// #                                       ## CREATE USER
// #                                           # Get Valid GNAME [max attempts: 5]
// #                                           # Get Valid SNAME [max attempts: 5]
// #                                           # Get Valid ROLE / ROLEID [max attempts: 5]
// #                                           # Get Valid TRATE [max attempts: 5]
// #                                           # Get Valid HLTH [max attempts: 5]
// #                                           # Get Valid SUPER [max attempts: 5]
// #                                           # Get Valid User ID
// #                                           # Record User in file
// #                                           # Return to action screen {BACK}
// #                                       ## MODIFY USER
// #                                           # Ask for User ID of who to modify
// #                                               # Ask for what to modify (out of the following)
// #                                                   ## PWRD
// #                                                       # Get Valid Password
// #                                                       # Confirm Password
// #                                                       # Check if confirmed password matches
// #                                                           ## TRUE
// #                                                               # Modify in a "replace" array
// #                                                               # Return to MODIFY USER screen {BACK}            !!
// #                                                           ## False
// #                                                               # Return to modify password screen [max attempts: 5] {LOOP}
// #                                                   ## GNAME
// #                                                       # Get Valid GNAME
// #                                                       # Modify in a "replace" array
// #                                                       # Return to MODIFY USER screen {BACK}            !!
// #                                                   ## SNAME
// #                                                       # Get Valid SNAME
// #                                                       # Modify in a "replace" array
// #                                                       # Return to MODIFY USER screen {BACK}            !!
// #                                                   ## ROLEID/TRATE/HLTH/SUPER
// #                                                       # Get Valid ROLEID/TRATE/HLTH/SUPER
// #                                                       # Confirm ROLEID/TRATE/HLTH/SUPER
// #                                                       # Modify in a "replace" array
// #                                                       # Return to MODIFY USER screen {BACK}            !!
// #                                       ## Delete User
// #                                           # Ask for User ID of who to delete
// #                                           # Confirm user
// #                                           # add user to "deleted users" file
// #                                           # remove from employeeData
// #                       ## NO MATCH
// #                           # Present failed sign in screen
// #                           # Return to sign in screen {BACK}
// #               ## INVALID
// #                   # Present invalid password screen
// #                   # Return to input password screen {BACK}
// #       ## INVALID
// #           # Present invalid user ID screen
// #           # Return to input user ID screen {BACK}