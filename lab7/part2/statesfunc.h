// Ryan O'Halloran
// CSE 20311
// Lab 7 - statesfunc.h - header file for reading in a CSV file of US state information and providing options to a user
typedef struct {
    char abbr[3]; // abbreviation
    char name[30]; // name
    char capt[30]; // capital
    int year;   // year founded
} State;
int read_file(State[], FILE *, char [], int);
void print_options(void);
void state_name_info(State[], int, char[]);
void state_abbr_info(State[], int, char[]);
void print_before_year(State[], int, int);
void print_after_year(State[], int, int);
void print_in_order(State[], int);
void states_starting_letter(State[], int, char);