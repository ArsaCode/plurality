#include "cs50.h"
#include <stdio.h>
#include <string.h>

/*
Hello ! This is the plurality votes counter made for the Problem Set 3 of CS50's Introduction to Computer Science course.
The user should input the key in the command prompt after the ./plurality names (names as a different names like EMMA, JOHN, etc...) command.

The software works as follows :

1 . Get the users input and checks if it's valid
2 . Asks for the numbers of voters
3 . Gets each vote
4 . Sorts the vote by number
5 . Prints the winners of the election

Feel free to send any suggestions at contact@arsadevs.com
*/

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 1;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    int candidateId = -1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(name, candidates[i].name))
        {
            candidateId = i;
        }
    }
    if (candidateId != -1)
    {
        candidates[candidateId].votes++;
        return true;
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int maxVotes = candidates[0].votes;
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxVotes)
        {
            maxVotes = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxVotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}