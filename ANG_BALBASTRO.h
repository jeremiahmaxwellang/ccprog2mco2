/*
	CCPROG2 MP3 header file (.h source code)
    
    Do not forget to encode your name, section and date of submission.
    
    LASTNAME1, FIRSTNAME1: ANG, JEREMIAH MAXWELL                                 SECTION1: S14
    LASTNAME2, FIRSTNAME2: BALBASTRO, LIANNE MAXENE                              SECTION2: S14
    
    DATE SUBMITTED     :	November 23, 2023
		
	Rename this file using your last names in alphabetical order, for example CRUZ_TAN.h
		
	Make sure to include your header file in your C source code for MP Part 2.  
*/

/*
    Encode below this comment the following:
    
    1. #define directives
    2. typedef alias(es)for your string(s)
    3. declaration of your user-defined struct data type(s)
    4. typedef alias(es) for your struct data type(s)

    You may have as many typedef as you deem necessary.

    This header should NOT include the codes for any function definitions.  Function definitions
    should be encoded in your C source file only.
*/

/* You have to put an inline comment for each struct member as part of the documentation. */

#define MAX 206 //max amount of territories
#define FILENAME "OUTPUT_ANG_BALBASTRO.txt"

typedef char String[35]; //used 35 characters since longest territory name is 32 char long (Saint_Vincent_and_the_Grenadines)

typedef struct territoryTag{
	String name;		//name of the territory
	double LE;			//baseline life expectancy value
	double airPoll;		//loss of life due to air pollution
	double ambPM;		//loss of life due to ambient particulate matter
	double ozone;		//loss of life due to ozone
	double HAP;			//loss of life due to household air pollution
	double environ;		//loss of life due to environmental hazards
	double occup;		//loss of life due to occupational hazards
	double unsafeWASH;	//loss of life due to unsafe water, sanitization, and health
	double metabolic;	//loss of life due to metabolic syndrome
	double dietary;		//loss of life due to dietary
	double highFast;	//loss of life due to high fasting plasma sugar
	double tobacco;		//loss of life due to tobacco
	double smoking;		//loss of life due to smoking
	double secondhand;	//loss of life due to secondhand smoking
	double unsafeSEX;	//loss of life due to unsafe sex
}territoryType;



