
float getFloat(char* mensaje);
int getInt(char* mensaje);
char getChar(char* mensaje);
int esNumericoFlotante(char str[]);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);

void clearStdin(void);
void pause(void);
void clearScreen(void);



int getEmail(char*email, int cantidad);

void incrementarID2(int * numeroid);
int incrementarID(int * numeroid);

void ponerMayusculas (char stringAUsar[]);
int validSexo(char sexo);
