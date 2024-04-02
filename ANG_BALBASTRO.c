/*
	CCPROG2 MP3 SOURCE CODE

    Do not forget to encode your name, section and date of submission.
    
    LASTNAME1, FIRSTNAME1: ANG, JEREMIAH MAXWELL                                 SECTION1: S14
    LASTNAME2, FIRSTNAME2: BALBASTRO, LIANNE MAXENE                              SECTION2: S14
    
    DATE SUBMITTED     :	November 23, 2023
		
	Rename this file using your last names in alphabetical order, for example CRUZ_TAN.c
		
	Make sure to compile your C source code with a -Wall directive.  
	   Example: CCPROG2> gcc -Wall LASTNAME1_LASTNAME2.c
	   
	Fix all warnings.  Do NOT run the program if you still have a warning.  You must have
	0 error, 0 warning before running the program.
	   
	DO NOT run your a.exe with input/output redirection anymore because MP3 is
   already supposed to be on text file processing.

*/

#include <stdio.h>
#include <string.h>

// include your own header file
#include "ANG_BALBASTRO.h"   

/* Do NOT include other header files. */ 

/* 
	HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE POINT DEDUCTIONS!
	
	1. You must apply struct data type, and text file processing MP Part 3 (MP3).
       a. Re-use the contents of your header file LASTNAME1_LASTNAME2.h.
       b. Follow the same hard requirements in MP2 on struct data type, and structure access using 
          * and ., and -> operators.
   2. Data should be read from SoGA_DATASET.txt using fscanf().
   3. The main() function should call the appropriate C function, and then call fprintf() to 
      write the answer to each question onto the OUTPUT_LASTNAME1_LASTNAME2.txt file. Numeric 
      answers with double data type must be written with 6 digits after the decimal point.  
   4. There should NOT be any printf() and scanf() statement in the entire source code, 
      not even in main(), and in the function that reads the SoGA data text file.  
   5. Document your codes with SENSIBLE comments.
   6.Use double data type (not float) for all floating point values/variables/functions/return type.
   7. Do NOT use any global variables.
   8. Do NOT use library functions that were NOT discussed in our class.
*/


/*
    ALL typedef declarations must be encoded in your header file.  
    All #define must be encoded in your header file.
    Do NOT place them in this file.
*/


/*
    Define any function that you need below this comment.  

    For functions that serve as answers to the questions, include the following as comments
    BEFORE the function definition itself:
       a. Question number, and the actual question.
       b. Thereafter, type the answer number, and the corresponding expected answer.
    
    For example: 
      Q1:  Which country has the lowest baseline life expectancy?
      A1:  Lesotho

    The following should be included as comments and appear BEFORE each function definition:
       a. Purpose: describe succintly what the function is supposed to accomplish.
       b. Parameters: describe succintly the nature/purpose of each parameter.
       c. Return type: if the function is not void, describe succintly what it will return as a result.          
       
    Document the body of the function by including comments alongside codes that you think
    may not be easy to understand to the person reading the codes. 
*/

/*
Q1: What is the average baseline life expectancy considering all territories? [average]
A1:  72.856707733485763

Purpose: Finding the average baseline life expectancy of the territories

Parameters: 
territoryType territories[] - contains the address of the array of territories

int n - total number of territories

Return type: function returns a double value of the average
*/

double Question1(territoryType* territories[MAX], int n){
    int i;
    double sum = 0.0;
    
    for(i = 0; i < n; i++){
        sum += territories[i]->LE; //Indirect access via structure pointer operator
    }
    
    return sum / n; // returns average
}

/*
Q2: If the SoGA_Dataset were to have its baseline life expectancy sorted top to down in
DESCENDING order(excluding global), what would be the names of the territories from <0>
to <9>? List the territory name and the corresponding baseline life expectancy. [linear search after selection sort]

A2: When parameter_start_index is set to 0 and parameter_end_index is set to 9, the answer is as follows:
Singapore                 84.5652999143781
Japan                     84.5578506644436
Iceland                   83.8917219255797
Switzerland               83.8636222586254
Italy                     83.0321327612239
Spain                     83.0122773325250
Israel                    82.9020467589883
Norway                    82.8291798839164
South_Korea               82.8262503583497
Luxembourg                82.7989527790003

Purpose: Listing territories from highest to lowest life expectancy

Parameters: 
territoryType territories[] - contains the address of the array of territories

int parameter_start_index - the starting index of the list
int parameter_end_index - the end index of the list

int n - total number of territories

Return type: function returns a double value of the average
*/
double Question2(territoryType territories[MAX], int parameter_start_index, int parameter_end_index, int n) {
    // Sorting the territories array in descending order based on LE (using Selection Sort)
    int i, j, max_index;

    for (i = 0; i < n - 1; i++) {
        max_index = i;
        for (j = i + 1; j < n; j++) {
            //excluding Global
            if (strcmp(territories[j].name, "Global") != 0 &&
                territories[j].LE > territories[max_index].LE) {
                max_index = j;
            }
        }
        // Swap territories[i] and territories[max_index]
        if (max_index != i) {
            territoryType temp = territories[i];
            territories[i] = territories[max_index];
            territories[max_index] = temp;
        }
    }

    return territories[parameter_end_index].LE; // Returning the LE of the last territory in the specified range
}

/*
Q3: What are the territories (excluding global) and their corresponding baseline LEs that have a Baseline LE between <75.50>
and <76.00>? List the answers in DESCCENDING order. [selection sort after linear search]

A3: When parameter_baselineLE_low is set to 75.50 and parameter_baselineLE_High is set to 76.00, the answer is as follows:
Libya              75.8633960834569
Latvia             75.843691938156
Montenegro         75.8367078197165
Brazil             75.7443781010499
Armenia            75.6862792868842
Mexico             75.6715997128358
Serbia             75.6518007987158
El Salvador        75.5640478948693

Purpose: Listing the territories that have baseline LE's between two given values

Parameters: 
territoryType territories[] - contains the address of the array of territories
double parameter_baselineLE_low - lower bound for the baseline LE
double parameter_baselineLE_high - upper bound for the baseline LE

territoryType* matchingTerritories[] - address of the array containing all the territories with LE's in between the lower and upper bounds

int n - total number of territories

Return type: returns the number of territories within the range of LE's
*/
int Question3(territoryType territories[MAX], int n, double parameter_baselineLE_low, double parameter_baselineLE_high, territoryType* matchingTerritories[MAX]) {
    int count = 0;
    int i, j;

    // Filtering territories based on parameter_baselineLE_low and parameter_baselineLE_high
    for (i = 0; i < n; i++) {
        if (strcmp(territories[i].name, "Global") != 0 && territories[i].LE >= parameter_baselineLE_low && territories[i].LE <= parameter_baselineLE_high) {
            matchingTerritories[count] = &territories[i]; // Use address of the territory
            count++;
        }
    }

    // Sorting matching territories in descending order using selection sort
    for (i = 0; i < count - 1; i++) {
        int max_idx = i;
        for (j = i + 1; j < count; j++) {
            if ((*matchingTerritories[j]).LE > (*matchingTerritories[max_idx]).LE) { // Accessing via dereferenced pointers
                max_idx = j;
            }
        }
        // Swap territories using pointers
        territoryType *temp = matchingTerritories[max_idx];
        matchingTerritories[max_idx] = matchingTerritories[i];
        matchingTerritories[i] = temp;
    }

    return count;
}

/*
Q4: If the SoGA_Dataset were to have its Delta Air Pollution to be sorted top to down
in ASCENDING order, what is the delta air pollution of the 10th country? Provide the territory name. [selection sort]
A4:  Ireland, 0.163050911642800

Purpose: Finding the average baseline life expectancy of the territories

Parameters: 
territoryType territories[] - contains the address of the array of territories

int n - total number of territories

Return type: function returns a double value of the average
*/
double Question4(territoryType territories[MAX], int n, String territoryName) {
    // Sorting territories based on air pollution in ascending order
    int i, j, min_index;    
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (territories[j].airPoll < territories[min_index].airPoll) {
                min_index = j;
            }
        }
        // Swap territories[i] and territories[min_index]
        if (min_index != i) {
            territoryType temp = territories[i];
            territories[i] = territories[min_index];
            territories[min_index] = temp;
        }
    }

    // Assigning specific information about territories to provided variable
    strcpy(territoryName, territories[9].name);

    // Return air pollution of the 10th country
    return territories[9].airPoll;
}

/*
Purpose: Helper function to alphabetically sort the territories for Question5()

Parameters: 
territoryType territ_sorted[] - contains the address of the array of territories

int n - total number of territories
*/
void alphabeticalSort(territoryType territ_sorted[], int n){
    int i, j;
    territoryType temp;

    // Sort territories based on name in ascending order using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            //if the first name is alphabetically after the second, swap the two
            if (strcmp(territ_sorted[j].name, territ_sorted[j + 1].name) > 0) {
                //swap
                temp = territ_sorted[j];
                territ_sorted[j] = territ_sorted[j + 1];
                territ_sorted[j + 1] = temp;
            }
        }
    }
}

/*
Q5: What is the baseline LE of <Poland>? [binary search]

A5: When parameter_name is Poland, the answer is as follows:
78.0667012657982

Purpose: Finding the baseline LE of 

Parameters: 
territoryType territories[] - contains the address of the array of territories

int n - total number of territories

Return type: if the name is found in the dataset, function returns the life expectancy of that territory, 
otherwise it returns -1.0
*/
double Question5(territoryType territories[MAX], int n, String parameter_name) {
    int low = 0, high = n - 1, mid;
    int found = 0;

    while (found != 1 && low <= high) {
        mid = low + (high - low) / 2;

        if (strcmp(parameter_name, territories[mid].name) == 0){
            found = 1;
        }

        else if (strcmp(parameter_name, territories[mid].name) < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (found)
        return territories[mid].LE;
    else
        return -1.0; // Indicate territory name not found
}
   
/*
Purpose: Takes in all the values of SoGA_DATASET.txt

Parameters: 
territoryType territories[] - contains the address of the array of territories

Return type: returns the total number of territories 
*/
int Input(territoryType territories[MAX]){
    int i = 0;
    territoryType tempTerritory;
    FILE* soga; //memory address of the dataset txt file
    soga = fopen("SoGA_DATASET.txt", "r");

	//takes in inputs while exactly 16 fields are entered per line
    for(i = 0; fscanf(soga, "%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", tempTerritory.name, 
	&tempTerritory.LE, &tempTerritory.airPoll, &tempTerritory.ambPM, &tempTerritory.ozone, &tempTerritory.HAP,
	&tempTerritory.environ, &tempTerritory.occup, &tempTerritory.unsafeWASH, &tempTerritory.metabolic, &tempTerritory.dietary, 
	&tempTerritory.highFast, &tempTerritory.tobacco, &tempTerritory.smoking, &tempTerritory.secondhand, &tempTerritory.unsafeSEX) == 16; i++){

        strcpy(territories[i].name, tempTerritory.name);
	
    	territories[i].LE = tempTerritory.LE;
    	territories[i].airPoll = tempTerritory.airPoll;
    	territories[i].ambPM = tempTerritory.ambPM;
    	territories[i].ozone = tempTerritory.ozone;
    	territories[i].HAP = tempTerritory.HAP;
    	territories[i].environ = tempTerritory.environ;
    	territories[i].occup = tempTerritory.occup;
    	territories[i].unsafeWASH = tempTerritory.unsafeWASH;
    	territories[i].metabolic = tempTerritory.metabolic;
    	territories[i].dietary = tempTerritory.dietary;
    	territories[i].highFast = tempTerritory.highFast;
    	territories[i].tobacco = tempTerritory.tobacco;
    	territories[i].smoking = tempTerritory.smoking;
    	territories[i].secondhand = tempTerritory.secondhand;
    	territories[i].unsafeSEX = tempTerritory.unsafeSEX;
        
    }
    
    fclose(soga);

    return i;
}

int
main()
{
	FILE* fp; //memory address of the output txt file
	fp = fopen(FILENAME, "w");
	
	territoryType territories[MAX]; //array of territories' names and factor values
    int i;
    int numTerritories = Input(territories); //actual number of territories

    // Question 1
    territoryType* pointersToTerritories[MAX]; //struct pointer array for indirectly accessing territories[]
    double AverageLE = 0.0; //average of all the territories


    // Question 2
    int parameter_start_index; //lower bound of array
    int parameter_end_index; //upper bound of array

    // Question 3
    territoryType* matchingTerritories[MAX]; //array of territories that fit in a range of life expectancies
    int rangeCount = 0; //number of territories that fit in a range of life expectancies
    double parameter_baselineLE_low; //lower bound of LE
    double parameter_baselineLE_high; //upper bound of LE

    // Question 4
    double DeltaPol; //contains a territory's loss of life due to air pollution value
    String territoryName; //will contain the answer of Question 4

    // Question 5
    String parameter_name; //name of territory being asked
    double BinaryLE; //will contain the LE of the asked territory 
        
    /* 
       Call the function that answers a question. Thereafter, use fprintf() NOT printf()
       to output the the question and the corresponding answer onto OUTPUT_LASTNAME1_LASTNAME2.TXT.
       
       expectancy = Q1_Answer(territory, param_x, param_y); // where expectancy, territory, param_x and param_y are local variables.

       fprintf(fp, "Q1: Which territory has the lowest baseline life expectancy?\n");
       fprintf(fp, "A1: %s %lf\n", territory, expectancy);       
    
    */
    
    // QUESTION 1 -----------------------------------------------------------------------------------------------------------------
    //struct pointer for indirectly accessing territories[]
    for (i = 0; i < numTerritories; i++) {
        pointersToTerritories[i] = &territories[i];
    }

    AverageLE = Question1(pointersToTerritories, numTerritories);
    
    fprintf(fp, "Q1: What is the average baseline life expectancy considering all territories?\n");
   	fprintf(fp, "A1: %lf\n\n", AverageLE); //write into the output file


    // QUESTION 2 -----------------------------------------------------------------------------------------------------------------
    parameter_start_index = 0;
    parameter_end_index = 9;

    Question2(territories, parameter_start_index, parameter_end_index, numTerritories);
    fprintf(fp,"Q2: If the SoGA_Dataset were to have its baseline life expectancy sorted top to down in DESCENDING order (excluding global), what would be the names of the territories from %d to %d? List the territory name and the corresponding baseline life expectancy. \n", parameter_start_index, parameter_end_index);   
    fprintf(fp,"A2: When parameter_start_index is set to %d and parameter_end_index is set to %d, the answer is as follows:\n\n", parameter_start_index, parameter_end_index);

    for (i = parameter_start_index; i <= parameter_end_index; i++) {
        fprintf(fp,"%-25s %lf\n", territories[i].name, territories[i].LE);
    }
    
    fprintf(fp, "\n");

    // QUESTION 3 -----------------------------------------------------------------------------------------------------------------
    parameter_baselineLE_low = 75.50;
    parameter_baselineLE_high = 76.00;

    rangeCount = Question3(territories, numTerritories, parameter_baselineLE_low, parameter_baselineLE_high, matchingTerritories);

	fprintf(fp,"Q3: What are the territories (excluding global) and their corresponding baseline LEs that have a Baseline LE between %.2lf and %.2lf? List the answers in DESCCENDING order.\n", parameter_baselineLE_low, parameter_baselineLE_high);    
   	fprintf(fp,"A3: When parameter_baselineLE_low is set to %.2lf and parameter_baselineLE_high is set to %.2lf, the answer is as follows:\n\n", parameter_baselineLE_low, parameter_baselineLE_high);

    if (rangeCount > 0) {
        for (i = 0; i < rangeCount; i++) {
            fprintf(fp,"%-25s %lf\n", matchingTerritories[i]->name, matchingTerritories[i]->LE);
        }
       	fprintf(fp, "\n");
    } else {
        fprintf(fp,"No territories found within the specified range.\n\n");
    }

    // QUESTION 4 -----------------------------------------------------------------------------------------------------------------
    
    DeltaPol = Question4(territories, numTerritories, territoryName);
    fprintf(fp,"Q4: If the SoGA_Dataset were to have its Delta Air Pollution sorted top to down in ASCENDING order, what is the delta air pollution of the 10th country? Provide the territory name.\n");
    fprintf(fp,"A4: %s, Air Pollution: %lf\n\n", territoryName, DeltaPol);

    // QUESTION 5 -----------------------------------------------------------------------------------------------------------------
    strcpy(parameter_name, "Poland");
    alphabeticalSort(territories, numTerritories); //alphabetically sort territories

    BinaryLE = Question5(territories, numTerritories, parameter_name);
    fprintf(fp,"Q5: What is the baseline LE of %s?\n", parameter_name);

    //prints territory name and LE if found
    if (BinaryLE == -1)
        fprintf(fp,"A5: %s not found.\n", parameter_name);
    else
        fprintf(fp,"A5: %s's baseline LE is: %lf\n\n", parameter_name, BinaryLE);
        
    fclose(fp);

    return 0;
}
	
//end of file.