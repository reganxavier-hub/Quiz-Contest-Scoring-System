/*
 * Program: Quiz Contest Scoring System
 * Author: Regan
 * Language: C
 * Project: Command Line Argument based
 * Description: A C-based Quiz Contest Scoring System designed for small-scale competitions, where participants' scores are updated after each round. 
                This program keeps track of participants, allows score entry for each round, and determines the winner based on the highest score.
 * Organization: Regan's Tech Lab
 */

#include <stdio.h>
#include <string.h>

// Maximum number of participants
#define MAX_PARTICIPANTS 10

// Structure of a participant
typedef struct Participant {
    char name[50];
    int score;
    char id;
} Participant;

// Global array for participant details
Participant participants[MAX_PARTICIPANTS];
int participantCount = 0;

// Function declarations
void addParticipants(int);
void displayAllParticipants();
void recordScores(int);
void showResults();

// Driver Code
int main() {
    // Get the number of participants
    printf("Enter the number of participants: ");
    scanf("%d", &participantCount);
    if (participantCount > MAX_PARTICIPANTS) {
        printf("Number of participants cannot exceed %d. Terminating the program.\n", MAX_PARTICIPANTS);
        return 0;
    }

    // Register participants
    addParticipants(participantCount);

    // Conduct quiz rounds
    int rounds;
    printf("Enter the number of quiz rounds: ");
    scanf("%d", &rounds);

    for (int i = 0; i < rounds; i++) {
        printf("\n--- Round %d ---\n", i + 1);
        recordScores(i);
    }

    // Display the final results
    showResults();

    return 0;
}

// Function to add participants
void addParticipants(int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name of participant %d: ", i + 1);
        scanf("%s", participants[i].name);
        participants[i].score = 0; // Initialize score to 0
        participants[i].id = 'A' + i; // Assign unique IDs
    }
}

// Function to display all participants with their IDs
void displayAllParticipants() {
    printf("\nParticipants:\n");
    for (int i = 0; i < participantCount; i++) {
        printf("%c: %s (Score: %d)\n", participants[i].id, participants[i].name, participants[i].score);
    }
}

// Function to record scores for a round
void recordScores(int round) {
    displayAllParticipants();

    for (int i = 0; i < participantCount; i++) {
        printf("Enter score for participant %s (ID: %c) in round %d: ", participants[i].name, participants[i].id, round + 1);
        int score;
        scanf("%d", &score);
        participants[i].score += score; // Update participant's score
    }
}

// Function to show the final results
void showResults() {
    int maxScore = 0;
    int winnerIndex = -1;
    int tieCount = 0;

    for (int i = 0; i < participantCount; i++) {
        if (participants[i].score > maxScore) {
            maxScore = participants[i].score;
            winnerIndex = i;
        }
    }

    for (int i = 0; i < participantCount; i++) {
        if (participants[i].score == maxScore) {
            tieCount++;
        }
    }

    printf("\n----- FINAL RESULTS -----\n");

    if (tieCount > 1) {
        printf("It's a tie! \nMultiple participants have the highest score of %d!\n", maxScore);
    } else if (winnerIndex != -1) {
        printf("The winner is %s (ID: %c) with a score of %d!\n", participants[winnerIndex].name, participants[winnerIndex].id, maxScore);
    } else {
        printf("No winner determined\n");
    }
}
