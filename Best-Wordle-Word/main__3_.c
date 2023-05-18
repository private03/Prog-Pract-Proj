//  bestWordle.c
//  Author: Edwin Jasper
//  Date: 11/01/22
//  Location: your moms house
// if you mark me ill become your stepfather.
//  Links to wordle dictionary words at:
//    https://www.reddit.com/r/wordle/comments/s4tcw8/a_note_on_wordles_word_list/
//

#include <stdio.h>
#include <stdlib.h> // for exit( -1)
#include <string.h>

struct WNS {
  int score;
  char word[6];
};

//-----------------------------------------------------------------------------------------
// Comparator for use in built-in qsort(..) function.  Parameters are declared
// to be a generic type, so they will match with anything. This is a two-part
// comparison.  First the scores are compared.  If they are the same, then the
// words themselves are also compared, so that the results are in descending
// order by score, and within score they are in alphabetic order.

int compareFunction(const void *a, const void *b) {
  // Before using parameters we have cast them into the actual type they are in
  // our program and then extract the numerical value used in comparison

  int firstScore = ((struct WNS *)a)->score;
  int secondScore = ((struct WNS *)b)->score;

  char firstWord[81];
  strcpy(firstWord, ((struct WNS *)a)->word);
  char secondWord[81];
  strcpy(secondWord, ((struct WNS *)b)->word);
  // If scores are different, then that's all we need for our comparison.
  if (firstScore != secondScore) {
    // We reverse the values, so the result is in descending vs. the otherwise
    // ascending order return firstScore - secondScore;   // ascending order
    return secondScore - firstScore; // descending order
  } else {
    // Scores are equal, so check words themselves, to put them in alphabetical
    // order Hint: return the value of strcmp( parameter a word,  parameter b
    // word)
    return strcmp(firstWord, secondWord);
  }
} // end compareFunction(..)

// ...
// Sort the allWords array in descending order by score, and within score they
// should also be sorted into ascending order alphabetically.  Use the built-in
// C quick sort qsort(...). The last parameter is the name of the comparison
// function we use (a function pointer).
//
// ... uncomment out the line below once you have it in a meaningful context in
// your code. qsort( theArray, numElementsInArray, sizeof( your struct),
// compareFunction); qsort( arr, totalWords, sizeof(struct WNS*),
// compareFunction);

// -----------------------------------------------------------------------------------------
// function for reading a file (Taken from sample code in main and transfered to
// this function).

void readFile(char fileName[81], int *totalWords) {
  FILE *inFilePtr = fopen(fileName, "r"); // Connect logical name to filename
  char inputString[81];

  // Sanity check: ensure file open worked correctly
  if (inFilePtr == NULL) {
    printf("Error: could not open %s for reading\n", fileName);
    exit(-1); // must include stdlib.h
  }

  // Read each word from file and print it.  You could do other things along the
  // way, like counting how many words there are.
  while (fscanf(inFilePtr, "%s", inputString) != EOF) {
    ++(*totalWords);
    // printf("%d ", *totalWords);
    // printf("%s\n", inputString);
  }

  // Close the file
  fclose(inFilePtr);
}

// -----------------------------------------------------------------------------------------

void arrayInsert(char fileName[81], struct WNS *arr, int *iter) {
  FILE *inFilePtr = fopen(fileName, "r"); // Connect logical name to filename
  char inputString[81];

  // Sanity check: ensure file open worked correctly
  if (inFilePtr == NULL) {
    printf("Error: could not open %s for reading\n", fileName);
    exit(-1); // must include stdlib.h
  }

  // Read each word from file and print it.  You could do other things along the
  // way, like counting how many words there are.
  // int iter = 0;
  while (fscanf(inFilePtr, "%s", inputString) != EOF) {
    strcpy(arr[(*iter)].word, inputString);
    // printf("\nthe string in the arrays struct is %s", arr[(*iter)].word);
    (*iter)++;
  }

  // Close the file
  fclose(inFilePtr);

  // return arr;
}

// -----------------------------------------------------------------------------------------

// -----------------------------------------------------------------------------------------
void scoringSystem(struct WNS *individStruct, struct WNS *answerArr,
                   int answersEnds) {
  individStruct->score = 0;
  char protectWord[6];
  strcpy(protectWord, individStruct->word);
  // printf("\n\n");

  for (int x = 0; x < answersEnds; x++) {

    char tempansWord[6];

    strcpy(protectWord, individStruct->word);
    strcpy(tempansWord, answerArr[x].word);
    
    for (int i = 0; i < strlen(protectWord); i++) {
      
      if (protectWord[i] == tempansWord[i]) {

        individStruct->score = individStruct->score + 3;
        memmove(&protectWord[i], &protectWord[i + 1], strlen(protectWord) - i);
        memmove(&tempansWord[i], &tempansWord[i + 1], strlen(tempansWord) - i);
        --i;
      }
    }
   
    for (int z = 0; z < strlen(protectWord); z++) { 
      for (int l = 0; l < strlen(tempansWord); l++) {
        if (protectWord[z] == tempansWord[l]) {
          individStruct->score = individStruct->score + 1;
          memmove(&protectWord[z], &protectWord[z + 1],
                  strlen(protectWord) - z);
          memmove(&tempansWord[l], &tempansWord[l + 1],
                  strlen(tempansWord) - l);
          --z;
        }
      }
    }

   
  }

}
// -----------------------------------------------------------------------------------------

void prefacescoringSystemsw(struct WNS *individStruct, struct WNS *answerArr,
                            int answersEnds) {

  char protectWord[6];
  strcpy(protectWord, individStruct->word);

  for (int x = 0; x < answersEnds; x++) {

    strcpy(protectWord, individStruct->word);

    for (int i = 0; i < strlen(answerArr[x].word); i++) {
      if (protectWord[i] == answerArr[x].word[i]) {
      
        protectWord[i] = " ";
        answerArr[x].word[i] = " ";
      }
    }
    for (int z = 0; z < strlen(protectWord); z++) {
      for (int l = 0; l < strlen(answerArr[l].word); l++) {
        if (protectWord[z] == answerArr[x].word[l]) {
       

          protectWord[z] = " ";
          answerArr[x].word[l] = " ";
        }
      }
    }
  }
}

// -----------------------------------------------------------------------------------------
void swscoringSystem(struct WNS *individStruct, struct WNS *answerArr,
                     int answersEnds) {
  individStruct->score = 0;
  char protectWord[6];
  strcpy(protectWord, individStruct->word);


  for (int x = 0; x < answersEnds; x++) {

    char tempansWord[6];

    strcpy(protectWord, individStruct->word);
    strcpy(tempansWord, answerArr[x].word);
    
    for (int i = 0; i < strlen(tempansWord); i++) {
      
      if (protectWord[i] == tempansWord[i]) {

        individStruct->score = individStruct->score + 3;
        memmove(&protectWord[i], &protectWord[i + 1], strlen(protectWord) - i);
        memmove(&tempansWord[i], &tempansWord[i + 1], strlen(tempansWord) - i);
        --i;
      }
    }
    
    for (int z = 0; z < strlen(tempansWord); z++) { 
      for (int l = 0; l < strlen(protectWord); l++) {
        if (protectWord[l] == tempansWord[z]) {
          individStruct->score = individStruct->score + 1;
          memmove(&protectWord[l], &protectWord[l + 1],
                  strlen(protectWord) - l);
          memmove(&tempansWord[z], &tempansWord[z + 1],
                  strlen(tempansWord) - z);
          --z;
        }
      }
    }

    
  }
  
}
// -----------------------------------------------------------------------------------------
int main() {
  char answersFileName[81] = "answersTiny.txt"; // Stores the answers file name
  char guessesFileName[81] = "guessesTiny.txt"; // Stores the guesses file name
  char fileName[81];
  int totalWords = 0;
  // Set default file names
  // ...

  printf("Default file names are %s and %s\n", answersFileName,
         guessesFileName);

  // Display menu, to allow partial credit for different program components
  int menuOption = 0;
  do {
    printf("\n");
    printf("Menu Options:\n");
    printf("  1. Display best first words only\n");
    printf("  2. Display best first and best second words\n");
    printf("  3. Change answers and guesses filenames\n");
    printf("  4. Exit\n");
    printf("Your choice: ");
    scanf("%d", &menuOption);

    // Handle menu option 3 to exit the program
    if (menuOption == 4) {
      exit(1); // Exit the program
    } else if (menuOption == 3) {
      // Change file names.  Menu will then be redisplayed.
      printf("Enter new answers and guesses filenames: ");
      scanf("%s %s", answersFileName, guessesFileName);
    }
  } while (menuOption == 3);
  strcpy(fileName, answersFileName);
  readFile(fileName, &totalWords);
  int answerWords = totalWords;
  printf("%s has %d words\n", fileName, totalWords);
  strcpy(fileName, guessesFileName);
  readFile(fileName, &totalWords);
  printf("%s has %d words\n", fileName, totalWords - answerWords);

  struct WNS *arr =
      malloc(sizeof(struct WNS) * (totalWords + 1)); // <- correct malloc
  struct WNS *answerArr = malloc(sizeof(struct WNS) * (totalWords + 1));

  int gIter = 0;
  int suplIter = 0;
  int answersEnds = 0;

  strcpy(fileName, answersFileName);
  arrayInsert(fileName, arr, &gIter);
  arrayInsert(fileName, answerArr, &suplIter);

  answersEnds = gIter;
  strcpy(fileName, guessesFileName);
  arrayInsert(fileName, arr, &gIter);

  for (int i = 0; i < totalWords; i++) {
    scoringSystem(&arr[i], answerArr, answersEnds);
  }
  // do not put a point in sizeof(struct WNS !!)
  qsort(arr, totalWords, sizeof(struct WNS), compareFunction);
  struct WNS *copyOfarr = malloc(sizeof(struct WNS) * (totalWords + 1));

  struct WNS *copyOfanswerarr = malloc(sizeof(struct WNS) * (totalWords + 1));

  if (menuOption == 1) {
    printf("\nWords and scores for top first words:");
    for (int i = 0; arr[i].score == arr[0].score; i++) {
      printf("\n%s %d", arr[i].word, arr[i].score);
    }
  } else if (menuOption == 2) {
    printf("\nWords and scores for top first words and second words:");
    for (int x = 0; arr[x].score == arr[0].score; x++) {
      printf("\n%s %d", arr[x].word, arr[x].score);
      for (int i = 0; i < totalWords; i++) {
        copyOfarr[i] = arr[i];
      }

      for (int i = 0; i < answersEnds; i++) {
        copyOfanswerarr[i] = answerArr[i];
      }
      prefacescoringSystemsw(&arr[x], answerArr, answersEnds);

      for (int i = 0; i < totalWords; i++) {
        swscoringSystem(&arr[i], answerArr, answersEnds);
      }

      qsort(arr, totalWords, sizeof(struct WNS), compareFunction);
      for (int x = 0; arr[x].score == arr[0].score; x++) {
        printf("\n   %s %d", arr[x].word, arr[x].score);
      }
      for (int i = 0; i < totalWords; i++) {
        arr[i] = copyOfarr[i];
      }

      for (int i = 0; i < answersEnds; i++) {
        answerArr[i] = copyOfanswerarr[i];
      }
    }
  }

  
  printf("\nDone\n");

  return 0;
} // end main()
