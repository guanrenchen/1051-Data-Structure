hw1_1:
    
	recursiveStair(num): use recursion to acquire stair of (num)
	iterativeStair(num): use for loop to acquire stair of (num)


	note:
		uses division to check for overflow

hw1_2:

	acquireElements():
		stores the input in a string
	        replace all punctuation in the string with spaces
	        use istringstream to append each element into vector
	printAllSubspace(elements):

	        use for loop to call printSubspace(elements,targetSize,pos,subspace)

    	printSubspace(elements,targetSize,pos,subspace):
	        uses recursion to print all subspaces the size of (targetSize)

	note:
	        printAllSubspace(elements) uses for loop to ensure that the subspace of the same size will be printed in a row