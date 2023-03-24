from comparison_utils import *

#get the file names
file1 = sys.argv[1]
file2 = sys.argv[2]
inputFile = sys.argv[3] #a Third File!!!

#open the files
f1 = open(file1,"r");
f2 = open(file2,"r");
inFile = open(inputFile,"r") #it has a different naming convention to clarify that this is the .in file

#get the lines
f1Lines = f1.readlines(); #same as input file lines but without the END, so we need to use this instead of inputLines
f2Lines = f2.readlines();
inputLines = inFile.readlines();
#set up the score
score = 0;

#figure out the min lines
minLines = min(len(f1Lines),len(f2Lines));

#compare
for i in range(minLines):
    inputCommand = get_first_value(inputLines[i])
    
    #Upon encountering LOAD, the output must be "success" always. Check for spelling errors
    #Upon encountering "INSERT", the output isn't so simple but also is just a string with potential spelling errors
    #Upon encountering "DELETE", same as INSERT
    if inputCommand == "LOAD" or inputCommand == "INSERT" or inputCommand == "DELETE":
        if(string_match(f1Lines[i].strip(),f2Lines[i].strip(),compute_threshold(f1Lines[i].strip(),1))):
            score = score+1
    
    """
        Upon "PRINT", there are two possibilities: either the string is purely numeric, at which point we search
        ignoring order, or there are non-numeric characters in it, at which point we search for equality of strings
    """
    if inputCommand == "PRINT":
        if(is_numeric_string(f1Lines[i])):
            if(is_sorted_list_equal(f1Lines[i],f2Lines[i])):
                score = score+1 #the adjacency list is the same
        else:
            if(string_match(f1Lines[i].strip(),f2Lines[i].strip(),compute_threshold(f1Lines[i].strip(),1))):
                score = score+1 #it is either "failure" or "illegal argument"
        
    if inputCommand == "COST":
        #The strings have to match to a single character, but if that character is a number all numbers must match
        if(string_match(f1Lines[i].strip(),f2Lines[i].strip(),compute_threshold(f1Lines[i].strip(),1)) and check_numbers_match(f2Lines[i].strip(),f1Lines[i].strip())):
            score = score+1
            
    if inputCommand == "MST":
        #First, check for numeric strings - MAYBE TO DO: perhaps we also should check if f2Lines has a number
        #of fields divisible by 3?
        if(is_numeric_string(f1Lines[i]) and is_numeric_string(f2Lines[i])):
            #Both are numeric, so we shall sort them into triples
            tripSolution = parse_numeric_triples(f1Lines[i])
            tripStudent = parse_numeric_triples(f2Lines[i])
            sort_numeric_triples(tripSolution)
            sort_numeric_triples(tripStudent)
            if(same_triples(tripSolution,tripStudent)):
                score = score + 1
        else:
            if(string_match(f1Lines[i].strip(),f2Lines[i].strip(),compute_threshold(f1Lines[i].strip(),1))):
                score = score+1 #it is either "failure" or "illegal argument"
            
    
print(score,end=",");
