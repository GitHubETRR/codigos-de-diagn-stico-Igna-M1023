#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#pragma comment(lib, "winmm.lib")
const char* WAV_FILE_PATH = "C:\\Users\\imagnarelli\\Downloads\\pinking.wav";
const char* DEVICE_ALIAS = "myWav";


void sendMCICommand(const char* command) {
    char errorBuffer[256];
    MCIERROR mciError = mciSendString(command, NULL, 0, NULL);
    if (mciError != 0) {
        mciGetErrorString(mciError, errorBuffer, sizeof(errorBuffer));
        printf("MCI Error: %s\nCommand: %s\n", errorBuffer, command);
    }
}

void displayMenu() {
    printf("\n--- WAV Player Menu ---\n");
    printf("p) Play / Resume\n");
    printf("r) Restart\n");
    printf("f) Seek Forward 5 seconds\n");
    printf("b) Seek Back 5 seconds\n");
    printf("x) Exit\n");
    printf("-----------------------\n");
    printf("Enter your choice: ");
}

int main() {
    static int isPlaying = 0;  
    char commandString[256];
    char returnString[128];
    char choice;
    printf("Opening file: %s\n", WAV_FILE_PATH);
    sprintf(commandString, "open \"%s\" type waveaudio alias %s", WAV_FILE_PATH, DEVICE_ALIAS);
    sendMCICommand(commandString);

    while (1) {
        displayMenu();
        choice = _getch();
        printf("%c\n", choice);

        switch (choice) {
            case 'p':
            case 'P':
                if (isPlaying) {
                    printf("Pausing...\n");
                    sprintf(commandString, "pause %s", DEVICE_ALIAS);
                    isPlaying = 0;
                } else {
                    printf("Playing/Resuming...\n");
                    sprintf(commandString, "play %s", DEVICE_ALIAS);
                    isPlaying = 1;
                }
                sendMCICommand(commandString);
                break;

            case 'r': 
            case 'R':
                printf("Restarting audio...\n");
                sprintf(commandString, "seek %s to start", DEVICE_ALIAS);
                sendMCICommand(commandString);
                sprintf(commandString, "play %s", DEVICE_ALIAS);
                sendMCICommand(commandString);
                break;

            case 'f': 
            case 'F':
                { 
                    printf("Seeking forward 5 seconds...\n");
                    sprintf(commandString, "status %s position", DEVICE_ALIAS);
                    mciSendString(commandString, returnString, sizeof(returnString), NULL);
                    long currentPosition = atol(returnString); // Convert string to long
                    sprintf(commandString, "status %s length", DEVICE_ALIAS);
                    mciSendString(commandString, returnString, sizeof(returnString), NULL);
                    long totalLength = atol(returnString);
                    long newPosition = currentPosition + 5000;
                    if (newPosition >= totalLength) {
                        printf("End of audio reached. Restarting.\n");
                        sprintf(commandString, "seek %s to start", DEVICE_ALIAS);
                    } else {
                        printf("Seeking to %ld ms.\n", newPosition);
                        sprintf(commandString, "seek %s to %ld", DEVICE_ALIAS, newPosition);
                    }
                    sendMCICommand(commandString);
                    sprintf(commandString, "play %s", DEVICE_ALIAS);
                    sendMCICommand(commandString);
                }
                break;

            case 'b': 
            case 'B':
                {
                    printf("Seeking back 5 seconds...\n");
                    sprintf(commandString, "status %s position", DEVICE_ALIAS);
                    mciSendString(commandString, returnString, sizeof(returnString), NULL);
                    long currentPosition = atol(returnString);
                    long newPosition = currentPosition - 5000;
                    if (newPosition < 0) {
                        newPosition = 0; 
                    }
                    printf("Seeking to %ld ms.\n", newPosition);
                    sprintf(commandString, "seek %s to %ld", DEVICE_ALIAS, newPosition);
                    sendMCICommand(commandString);
                    sprintf(commandString, "play %s", DEVICE_ALIAS); 
                    sendMCICommand(commandString);
                }
                break;

            case 'x': 
            case 'X':
                printf("Closing device and exiting...\n");
                sprintf(commandString, "close %s", DEVICE_ALIAS);
                sendMCICommand(commandString);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}