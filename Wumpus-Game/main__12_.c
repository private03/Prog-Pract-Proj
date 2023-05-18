/*
        Program 1: Wumpus, version 1 (fixed size array)
        // You will want to add more to this header comment!
*/
// Seed the random number generator.  Change seed to time(0) to change output
// each time.
// srand(time(0));

/*
Rules:
When the arrow target is not adjacent it ricochets to lowest room that it is
currently in. If the arrow returns to the same player room you kill yourself If
the the arrow is shoot purposely in the same cave you kill yourself Can go into
a sequence of rooms as long as they are connected After the arrow is fired and
sequence is over wumpus moves like a little bitch if the arrow hits nothing but
doesnt kill you the arrow is in the last room where you shoot it or the room it
ritchochet into.
  */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // for srand

void displayCave() {
  printf("       ______18______             \n"
         "      /      |       \\           \n"
         "     /      _9__      \\          \n"
         "    /      /    \\      \\        \n"
         "   /      /      \\      \\       \n"
         "  17     8        10     19       \n"
         "  | \\   / \\      /  \\   / |    \n"
         "  |  \\ /   \\    /    \\ /  |    \n"
         "  |   7     1---2     11  |       \n"
         "  |   |    /     \\    |   |      \n"
         "  |   6----5     3---12   |       \n"
         "  |   |     \\   /     |   |      \n"
         "  |   \\       4      /    |      \n"
         "  |    \\      |     /     |      \n"
         "  \\     15---14---13     /       \n"
         "   \\   /            \\   /       \n"
         "    \\ /              \\ /        \n"
         "    16---------------20           \n"
         "\n");
}

void displayInstructions() {
  printf("\n");
  displayCave();
  printf(
      "Hunt the Wumpus:                                             \n"
      "The Wumpus lives in a completely dark cave of 20 rooms. Each \n"
      "room has 3 tunnels leading to other rooms.                   \n"
      "                                                             \n"
      "Hazards:                                                     \n"
      "1. Two rooms have bottomless pits in them.  If you go there you fall "
      "and die.   \n"
      "2. Two other rooms have super-bats.  If you go there, the bats grab you "
      "and fly you to some random room, which could be troublesome.  Then "
      "those bats go  to a new room different from where they came from and "
      "from the other bats. \n "
      "3. The Wumpus is not bothered by the pits or bats, as he has sucker "
      "feet and is too heavy for bats to lift.  Usually he is asleep.  Two "
      "things wake him up: Anytime you shoot an arrow, or you entering his "
      "room.  The Wumpus will move into the lowest-numbered adjacent room "
      "anytime you shoot an arrow. When you move into the Wumpus' room, then "
      "he wakes and moves if he is in an odd-numbered room, but stays still "
      "otherwise.  After that, if he is in your room, he snaps your neck and "
      "you die! \n"
      "                                                                     "
      "           \n"
      "Moves:                                                               "
      "           \n"
      "On each move you can do the following, where input can be upper or "
      "lower-case:  \n"

      "1. Move into an adjacent room.  To move enter 'M' followed by a "
      "space and       \n"
      "   then a room number.                                               "
      "           \n"
      "2. Shoot your guided arrow through a list of up to three adjacent "
      "rooms, which you specify.  Your arrow ends up in the final room. To "
      "shoot enter 'S' followed by the number of rooms (1..3), and then the "
      "list of the desired number (up to 3) of adjacent room numbers, "
      "separated by spaces. If an arrow can't go a direction because there is "
      "no connecting tunnel, it ricochets and moves to the lowest-numbered "
      "adjacent room and continues doing this until it has traveled the "
      "designated number of rooms. If the arrow hits the Wumpus, you win! If "
      "the arrow hits you, you lose. You automatically pick up the arrow if "
      "you go through a room with the arrow in it.         \n "
      "3. Enter 'R' to reset the person and hazard locations, useful for "
      "testing.      \n"
      "4. Enter 'C' to cheat and display current board positions.           "
      "           \n"
      "5. Enter 'D' to display this set of instructions.                    "
      "           \n"
      "6. Enter 'P' to print the maze room layout.                          "
      "           \n"
      "7. Enter 'G' to guess which room Wumpus is in, to win or lose the game!"
      "           \n                                                        "
      "8. Enter 'X' to exit the game.                                       "
      "           \n"
      "                                                                     "
      "           \n"
      "Good luck!                                                           "
      "           \n"
      " \n\n");
} // end displayInstructions()

void Able2traverselvl(int playermovSelec, int *currentPlayloc,
                      bool *spotAccessible) {

  if (*currentPlayloc == 5 || *currentPlayloc == 6 || *currentPlayloc == 15 ||
      *currentPlayloc == 16) {
    if ((*currentPlayloc + 1) == playermovSelec ||
        (*currentPlayloc - 1) == playermovSelec) {
      *currentPlayloc = playermovSelec;
      *spotAccessible = true;
    }

  } else if (*currentPlayloc == 1 || *currentPlayloc == 8 ||
             *currentPlayloc == 13 || *currentPlayloc == 20 ) {
    if ((*currentPlayloc + 7) == playermovSelec ||
        (*currentPlayloc - 7) == playermovSelec) {
      if(playermovSelec != 6){
      *currentPlayloc = playermovSelec;
      *spotAccessible = true;
        }
    }

  } else if (*currentPlayloc == 2 || *currentPlayloc == 10 ||
             *currentPlayloc == 11 || *currentPlayloc == 19) {
    if ((*currentPlayloc + 8) == playermovSelec ||
        (*currentPlayloc - 8) == playermovSelec) {
      *currentPlayloc = playermovSelec;
      *spotAccessible = true;
    }

  } else if (*currentPlayloc == 3 || *currentPlayloc == 9 ||
             *currentPlayloc == 12 || *currentPlayloc == 18) {
    if ((*currentPlayloc + 9) == playermovSelec ||
        (*currentPlayloc - 9) == playermovSelec) {
      *currentPlayloc = playermovSelec;
      *spotAccessible = true;
    }

  } else if (*currentPlayloc == 4 || *currentPlayloc == 7 ||
             *currentPlayloc == 14 || *currentPlayloc == 17) {

    if ((*currentPlayloc + 10) == playermovSelec ||
        (*currentPlayloc - 10) == playermovSelec) {
      *currentPlayloc = playermovSelec;
      *spotAccessible = true;
    }
  }
}

void traverseBetween(int playermovSelec, int *currentPlayloc,
                     bool *spotAccessible) {

  if (*currentPlayloc <= 5 && *currentPlayloc >= 1) {
    if (playermovSelec <= 5 && playermovSelec >= 1) {

      if ((playermovSelec == *currentPlayloc + 1) ||
          (playermovSelec == *currentPlayloc - 1)) {
        *currentPlayloc = playermovSelec;
        *spotAccessible = true;

      } else if ((playermovSelec == *currentPlayloc + 4) ||
                 (playermovSelec == *currentPlayloc - 4)) {
        *currentPlayloc = playermovSelec;
        *spotAccessible = true;
      }
    }
  }

  else if (*currentPlayloc <= 15 && *currentPlayloc >= 6) {
    if (playermovSelec <= 15 && playermovSelec >= 6) {

      if ((playermovSelec == *currentPlayloc + 1) ||
          (playermovSelec == *currentPlayloc - 1)) {
        *currentPlayloc = playermovSelec;
        *spotAccessible = true;

      } else if ((playermovSelec == *currentPlayloc + 7) ||
                 (playermovSelec == *currentPlayloc - 7)) {
        *currentPlayloc = playermovSelec;
        *spotAccessible = true;
      }
    }
  }

  else if (*currentPlayloc <= 20 && *currentPlayloc >= 16) {
    if (playermovSelec <= 20 && playermovSelec >= 16) {
      if ((playermovSelec == *currentPlayloc + 1) ||
          (playermovSelec == *currentPlayloc - 1)) {
        *currentPlayloc = playermovSelec;
        *spotAccessible = true;

      } else if ((playermovSelec == *currentPlayloc + 4) ||
                 (playermovSelec == *currentPlayloc - 4)) {
        *currentPlayloc = playermovSelec;
        *spotAccessible = true;
      }
    }
  }
}

void lvladjGobjects(int gameobjectpostion, int currentPlayloc,
                    char gameobject[]) {

  if (currentPlayloc == 5 || currentPlayloc == 6 || currentPlayloc == 15 ||
      currentPlayloc == 16) {

    if ((currentPlayloc + 1) == gameobjectpostion ||
        (currentPlayloc - 1) == gameobjectpostion) {
    }

  } else if (currentPlayloc == 1 || currentPlayloc == 8 ||
             currentPlayloc == 13 || currentPlayloc == 20) {
    if ((currentPlayloc + 7) == gameobjectpostion ||
        (currentPlayloc - 7) == gameobjectpostion) {
      if ((strcmp(gameobject, "PIT")) == 0) {
        printf("You feel a draft. ");
      } else if ((strcmp(gameobject, "Wumpus")) == 0) {
        printf("You smell a stench. ");
      } else if ((strcmp(gameobject, "BATS")) == 0) {
        printf("You hear rustling of bat wings. ");
      }
    }

  } else if (currentPlayloc == 2 || currentPlayloc == 10 ||
             currentPlayloc == 11 || currentPlayloc == 19) {
    if ((currentPlayloc + 8) == gameobjectpostion ||
        (currentPlayloc - 8) == gameobjectpostion) {
      if ((strcmp(gameobject, "PIT")) == 0) {
        printf("You feel a draft. ");
      } else if ((strcmp(gameobject, "Wumpus")) == 0) {
        printf("You smell a stench. ");
      } else if ((strcmp(gameobject, "BATS")) == 0) {
        printf("You hear rustling of bat wings. ");
      }
    }

  } else if (currentPlayloc == 3 || currentPlayloc == 9 ||
             currentPlayloc == 12 || currentPlayloc == 18) {
    if ((currentPlayloc + 9) == gameobjectpostion ||
        (currentPlayloc - 9) == gameobjectpostion) {
      if ((strcmp(gameobject, "PIT")) == 0) {
        printf("You feel a draft. ");
      } else if ((strcmp(gameobject, "Wumpus")) == 0) {
        printf("You smell a stench. ");
      } else if ((strcmp(gameobject, "BATS")) == 0) {
        printf("You hear rustling of bat wings. ");
      }
    }

  } else if (currentPlayloc == 4 || currentPlayloc == 7 ||
             currentPlayloc == 14 || currentPlayloc == 17) {

    if ((currentPlayloc + 10) == gameobjectpostion ||
        (currentPlayloc - 10) == gameobjectpostion) {
      if ((strcmp(gameobject, "PIT")) == 0) {
        printf("You feel a draft. ");
      } else if ((strcmp(gameobject, "Wumpus")) == 0) {
        printf("You smell a stench. ");
      } else if ((strcmp(gameobject, "BATS")) == 0) {
        printf("You hear rustling of bat wings. ");
      }
    }
  }
}

void gotraverseBetween(int gameobjectpostion, int currentPlayloc,
                       char gameobject[]) {

  if (currentPlayloc <= 5 && currentPlayloc >= 1) {
    if (gameobjectpostion <= 5 && gameobjectpostion >= 1) {

      if ((gameobjectpostion == currentPlayloc + 1) ||
          (gameobjectpostion == currentPlayloc - 1)) {
        if ((strcmp(gameobject, "PIT")) == 0) {
          printf("You feel a draft. ");
        } else if ((strcmp(gameobject, "Wumpus")) == 0) {
          printf("You smell a stench. ");
        } else if ((strcmp(gameobject, "BATS")) == 0) {
          printf("You hear rustling of bat wings. ");
        }

      } else if ((gameobjectpostion == currentPlayloc + 4) ||
                 (gameobjectpostion == currentPlayloc - 4)) {
        if ((strcmp(gameobject, "PIT")) == 0) {
          printf("You feel a draft. ");
        } else if ((strcmp(gameobject, "Wumpus")) == 0) {
          printf("You smell a stench. ");
        } else if ((strcmp(gameobject, "BATS")) == 0) {
          printf("You hear rustling of bat wings. ");
        }
      }
    }
  }

  else if (currentPlayloc <= 15 && currentPlayloc >= 6) {
    if (gameobjectpostion <= 15 && gameobjectpostion >= 6) {

      if ((gameobjectpostion == currentPlayloc + 1) ||
          (gameobjectpostion == currentPlayloc - 1)) {
        if ((strcmp(gameobject, "PIT")) == 0) {
          printf("You feel a draft. ");

        } else if ((strcmp(gameobject, "Wumpus")) == 0) {
          printf("You smell a stench. ");
        } else if ((strcmp(gameobject, "BATS")) == 0) {
          printf("You hear rustling of bat wings. ");
        }

      } else if ((gameobjectpostion == currentPlayloc + 9) ||
                 (gameobjectpostion == currentPlayloc - 9)) {
        if ((strcmp(gameobject, "PIT")) == 0) {
          printf("You feel a draft. ");

        } else if ((strcmp(gameobject, "Wumpus")) == 0) {
          printf("You smell a stench. ");
        } else if ((strcmp(gameobject, "BATS")) == 0) {
          printf("You hear rustling of bat wings. ");
        }
      }
    }
  }

  else if (currentPlayloc <= 20 && currentPlayloc >= 16) {
    if (gameobjectpostion <= 20 && gameobjectpostion >= 16) {
      if ((gameobjectpostion == currentPlayloc + 1) ||
          (gameobjectpostion == currentPlayloc - 1)) {
        if ((strcmp(gameobject, "PIT")) == 0) {
          printf("You feel a draft. ");
        } else if ((strcmp(gameobject, "Wumpus")) == 0) {
          printf("You smell a stench. ");
        } else if ((strcmp(gameobject, "BATS")) == 0) {
          printf("You hear rustling of bat wings. ");
        }

      } else if ((gameobjectpostion == currentPlayloc + 4) ||
                 (gameobjectpostion == currentPlayloc - 4)) {
        if ((strcmp(gameobject, "PIT")) == 0) {
          printf("You feel a draft. ");
        } else if ((strcmp(gameobject, "Wumpus")) == 0) {
          printf("You smell a stench. ");
        } else if ((strcmp(gameobject, "BATS")) == 0) {
          printf("You hear rustling of bat wings. ");
        }
      }
    }
  }
}
//--------------------------------------------------------------------------------
int main(void) {
  int roundNum = 1;
  int maxSize = 20;
  int *caves = malloc(sizeof(int) * maxSize);
  for (int i = 0; i < maxSize + 1; i++) {
    caves[i] = i;
  }

  srand(1);

  int playermovSelec;
  char optionSelec;
  bool exitGame = false;

  int x;

  bool haveArrow = false;
  int currentPlayloc = 4;
  int pitLoc1 = 18;
  int pitLoc2 = 16;
  int wumpusLoc = 7;
  int manBat1 = 14;
  int manBat2 = 13;
  int arrowRoom = 10;
  for (x = 0; x < 20; x++) {

    if ((manBat1 != pitLoc1) && (manBat1 != manBat2)) {
      break;
    }
    manBat1 = rand() % 20 + 1;
  }
  for (x = 0; x < 20; x++) {

    if ((pitLoc2 != pitLoc1) && (pitLoc2 != manBat1) && (pitLoc2 != manBat2)) {
      break;
    }
    pitLoc2 = rand() % 20 + 1;
  }
  for (x = 0; x < 20; x++) {
    if ((wumpusLoc != pitLoc1) && (wumpusLoc != pitLoc2) &&
        (wumpusLoc != manBat1) && (wumpusLoc != manBat2)) {
      break;
    }
    wumpusLoc = rand() % 20 + 1;
  }
  for (x = 0; x < 20; x++) {
    if ((currentPlayloc != pitLoc1) && (currentPlayloc != pitLoc2) &&
        (currentPlayloc != wumpusLoc) && (currentPlayloc != manBat1) &&
        (currentPlayloc != manBat2)) {
      break;
    }
    currentPlayloc = rand() % 20 + 1;
  }
  for (x = 0; x < 20; x++) {
    if ((arrowRoom != pitLoc1) && (arrowRoom != pitLoc2) &&
        (arrowRoom != wumpusLoc) && (arrowRoom != manBat1) &&
        (arrowRoom != manBat2) && ((arrowRoom != currentPlayloc))) {
      break;
    }
    arrowRoom = rand() % 20 + 1;
  }

  printf("You are in room %d. ", currentPlayloc);
int z;
      char gameObject1[] = "Wumpus";
      char gameObject2[] = "PIT";
      char gameObject3[] = "BATS";
  for (z = 0; z < 20; z++) {
        if (caves[z] == wumpusLoc) {

          lvladjGobjects(caves[z], currentPlayloc, gameObject1);
          gotraverseBetween(caves[z], currentPlayloc, gameObject1);
          
        } }
  for (z = 0; z < 20; z++) {
       if (caves[z] == pitLoc1 || caves[z] == pitLoc2) {

          lvladjGobjects(caves[z], currentPlayloc, gameObject2);
          gotraverseBetween(caves[z], currentPlayloc, gameObject2);
        }} 
  for (z = 0; z < 20; z++) {
      if (caves[z] == manBat1 || caves[z] == manBat2) {

          lvladjGobjects(caves[z], currentPlayloc, gameObject3);
          gotraverseBetween(caves[z], currentPlayloc, gameObject3);
        }
         }
  printf("\n\n");
 
  while (exitGame == false) {
    bool noroundInc = false;
    printf("%d. Enter your move (or 'D' for directions): ", roundNum);

    scanf("%s", &optionSelec);

    if (optionSelec == 'm' || optionSelec == 'M') {

      scanf("%d", &playermovSelec);

      bool spotAccessible = false;
     

      Able2traverselvl(playermovSelec, &currentPlayloc, &spotAccessible);

      if (spotAccessible == false) {
        traverseBetween(playermovSelec, &currentPlayloc, &spotAccessible);
      }
      if(haveArrow == true)
      {
        arrowRoom = currentPlayloc;
      }

      if (spotAccessible == false) {
        printf("Invalid move.  Please retry. \n");
        noroundInc = true;
      }
      int tempBatLoc;

      if ((currentPlayloc == pitLoc1) || (currentPlayloc == pitLoc2)) {
        printf("Aaaaaaaaahhhhhh....   \n");
        printf("    You fall into a pit and die. \n");
        printf("\nExiting Program ...\n");
        exit(0);
      } 
      else if (currentPlayloc == wumpusLoc) {
        if (wumpusLoc % 2 == 1) {
          int firstPass;
          int secondPass;
          int thirdPass;
          int iter = 0;
          bool wumpuspotAccess = false;
          int y;

          for (y = 0; y < 20; y++) {
            Able2traverselvl(caves[y], &wumpusLoc, &wumpuspotAccess);
            if (wumpuspotAccess == false) {
              traverseBetween(caves[y], &wumpusLoc, &wumpuspotAccess);
            }
            if (wumpuspotAccess == true) {
              ++iter;
              if (iter == 1) {
                firstPass = caves[y];
              } else if (iter == 2) {
                secondPass = caves[y];
              } else if (iter == 3) {
                thirdPass = caves[y];
              }
            }
          }
          if (firstPass > secondPass) {
            if (secondPass < thirdPass) {
              wumpusLoc = secondPass;
            } else {
              wumpusLoc = thirdPass;
            }
          } else {
            if (firstPass < thirdPass) {
              wumpusLoc = firstPass;
            } else {
              wumpusLoc = thirdPass;
            }
          }
          printf("You hear a slithering sound, as the Wumpus slips away. \n"
                 "Whew, that was close! \n");

        } else if (wumpusLoc % 2 == 0) {
          printf("You briefly feel a slimy tentacled arm as your neck is "
                 "snapped.\n");
          printf("It is over.\n\n");

          printf("Exiting Program ...");
          exit(0);
        }
      } 
      else if ((currentPlayloc == manBat1) || (currentPlayloc == manBat2)) {
        if (currentPlayloc == manBat1) {
          manBat1 = rand() % 20 + 1;
          tempBatLoc = currentPlayloc;
          while ((manBat1 == currentPlayloc) || (manBat1 == wumpusLoc) ||
                 (manBat1 == manBat2) || (manBat1 == pitLoc1) ||
                 (manBat1 == pitLoc2) || (manBat1 == tempBatLoc)) {
            manBat1 = rand() % 20 + 1;
          }
        } else if (currentPlayloc == manBat2) {
          manBat2 = rand() % 20 + 1;
          tempBatLoc = currentPlayloc;
          while ((manBat2 == currentPlayloc) || (manBat2 == wumpusLoc) ||
                 (manBat2 == manBat2) || (manBat2 == pitLoc1) ||
                 (manBat2 == pitLoc2) || (manBat2 == tempBatLoc)) {
            manBat2 = rand() % 20 + 1;
          }
        }
        int tempLoc = currentPlayloc;
        currentPlayloc = rand() % 20 + 1;
        while (currentPlayloc == tempLoc || (currentPlayloc == wumpusLoc) ||
               (currentPlayloc == manBat1) || (currentPlayloc == manBat2) ||
               (currentPlayloc == pitLoc1) || (currentPlayloc == pitLoc2) ||
               (currentPlayloc == tempBatLoc)) {
          currentPlayloc = rand() % 20 + 1;
        }
        printf("Woah... you're flying!\n You've just been transported by bats "
               "to room %d \n",
               currentPlayloc);
      } 
      else if (currentPlayloc == arrowRoom && haveArrow != true) {
        haveArrow = true;
        printf("Congratulations, you found the arrow and can once again shoot. "
               "\n");
      }
      printf("You are in room %d. ", currentPlayloc);
      int z;
      
       for (z = 0; z < 20; z++) {
        if (caves[z] == wumpusLoc) {

          lvladjGobjects(caves[z], currentPlayloc, "Wumpus");
          gotraverseBetween(caves[z], currentPlayloc, "Wumpus");
          
        } }
       for (z = 0; z < 20; z++) {
       if (caves[z] == pitLoc1 || caves[z] == pitLoc2) {

          lvladjGobjects(caves[z], currentPlayloc, "PIT");
          gotraverseBetween(caves[z], currentPlayloc, "PIT");
        }} 
       for (z = 0; z < 20; z++) {
      if (caves[z] == manBat1 || caves[z] == manBat2) {

          lvladjGobjects(caves[z], currentPlayloc, "BATS");
          gotraverseBetween(caves[z], currentPlayloc, "BATS");
        }
         }
      
     
      if (noroundInc == false) {
        ++roundNum;
      }
      printf("\n\n");
    }
    else if (optionSelec == 's' || optionSelec == 'S') {
      bool arrowlocAccessible = false;
      int *shootsFired;
      int maxfireSize;
      if (arrowRoom != currentPlayloc) {
        printf(
            "Sorry, you can't shoot an arrow you don't have. Go find it.\n");
        printf("You are in room %d.\n", currentPlayloc);

      }
      else {
         scanf("%d", &maxfireSize);
        printf("Enter the number of rooms (1..3) into which you want to shoot, "
               "followed by the rooms themselves: ");
       
        shootsFired = malloc(sizeof(int) * maxfireSize);
        for (int i = 0; i < maxfireSize; i++) {
          int enter = 0;
          scanf("%d", &enter);
          shootsFired[i] = enter;
        }
        for (int n = 0; n < maxfireSize; n++) {
          if (shootsFired[n] == currentPlayloc) {
             printf("You just shot yourself.  \n" "Maybe Darwin was right.  You're dead.\n");
            printf("Exiting Program ...");
            exit(0);
          }
          //printf("Arrow moved from room %d to ", arrowRoom);
          Able2traverselvl(shootsFired[n], &arrowRoom, &arrowlocAccessible);
          
          if (arrowlocAccessible == false) {
            //printf("Arrow moved from room %d to ", arrowRoom);
            traverseBetween(shootsFired[n], &arrowRoom, &arrowlocAccessible);
            //printf("%d \n", arrowRoom);
          }
          // if the room isnt accesible it sends it to lowest number room
          if (arrowlocAccessible == false) {

            printf("Room %d is not adjacent. Arrow ricochets... \n",
                   shootsFired[n]);
            int firstaPass = 0;
            int secondaPass = 0;
            int thirdaPass = 0;
            int richotetLocation = 0;

            int y;

            for (y = 0; y < 20; y++) {
              Able2traverselvl(caves[y], &arrowRoom, &arrowlocAccessible);
              if (arrowlocAccessible == false) {
                traverseBetween(caves[y], &arrowRoom, &arrowlocAccessible);
              }
              if (arrowlocAccessible == true) {
                ++richotetLocation;
                if (richotetLocation == 1) {
                  firstaPass = caves[y];
                } else if (richotetLocation == 2) {
                  secondaPass = caves[y];
                } else if (richotetLocation == 3) {
                  thirdaPass = caves[y];
                }
              }
            }
            
            if (firstaPass > secondaPass) {
              if (secondaPass < thirdaPass) {
                arrowRoom = secondaPass;
              } else {
                arrowRoom = thirdaPass;
              }
            } else {
              if (firstaPass < thirdaPass) {
                arrowRoom = firstaPass;
              } else {
                arrowRoom = thirdaPass;
              }
            }
            if(arrowRoom == currentPlayloc) {
             printf("You just shot yourself, and are dying.\n" "It didn't take long, you're dead.\n");
              printf("Exiting Program ...\n");
            exit(0);
          }else if(arrowRoom == wumpusLoc){
              
            printf("Your arrow ricochet killed the Wumpus, you lucky dog!\n"  "Accidental victory, but still you win!\n");
              printf("Exiting Program ...\n");
            exit(0);}
              
          }
          //if it hits wumpus on purpose
          if (arrowRoom == wumpusLoc){
            printf(
                "Wumpus has just been pierced by your deadly arrow! \n"
                "Congratulations on your victory, you awesome hunter you. \n");
             printf("Exiting Program ...\n");
            exit(0);
          } 
          //if it hits wupus on accident
          // If it doesnt hit wumpus
          else if (arrowRoom != wumpusLoc && n+1 == maxfireSize) {
           // printf("wumpus is moving");
            int firstPass;
            int secondPass;
            int thirdPass;
            int iter = 0;
            bool wumpuspotAccess = false;
            int y;
            for (y = 0; y < 20; y++) {
              Able2traverselvl(caves[y], &wumpusLoc, &wumpuspotAccess);
              if (wumpuspotAccess == false) {
                traverseBetween(caves[y], &wumpusLoc, &wumpuspotAccess);
              }
              if (wumpuspotAccess == true) {
                ++iter;
                if (iter == 1) {
                  firstPass = caves[y];
                } else if (iter == 2) {
                  secondPass = caves[y];
                } else if (iter == 3) {
                  thirdPass = caves[y];
                }
              }
            }
            if (firstPass > secondPass) {
              if (secondPass < thirdPass) {
                wumpusLoc = secondPass;
              } else {
                wumpusLoc = thirdPass;
              }
            } else {
              if (firstPass < thirdPass) {
                wumpusLoc = firstPass;
              } else {
                wumpusLoc = thirdPass;
              }
            }
          }
          if (arrowRoom == currentPlayloc) {
            printf("You just shot yourself.  \n" "Maybe Darwin was right.  You're dead.\n");
          }
          haveArrow = false;
          arrowlocAccessible = false;

          
        }
        printf("You are in room %d. \n", currentPlayloc);
       
      }
      ++roundNum;
    }

    else if (optionSelec == 'r' || optionSelec == 'R') {

      printf("Enter the room locations (1..20) for player, wumpus, pit1, "
             "pit2, bats1, bats2, and arrow: \n\n");
      scanf("%d", &currentPlayloc);
      scanf("%d", &wumpusLoc);
      scanf("%d", &pitLoc1);
      scanf("%d", &pitLoc2);
      scanf("%d", &manBat1);
      scanf("%d", &manBat2);
      scanf("%d", &arrowRoom);

      if (arrowRoom == -1) {
        arrowRoom = currentPlayloc;
        haveArrow = true;
      }

      printf("You are in room %d. ", currentPlayloc);
      int z;
      char gameObject1[] = "Wumpus";
      char gameObject2[] = "PIT";
      char gameObject3[] = "BATS";
      for (z = 0; z < 20; z++) {
        if (caves[z] == wumpusLoc) {

          lvladjGobjects(caves[z], currentPlayloc, gameObject1);
          gotraverseBetween(caves[z], currentPlayloc, gameObject1);
        } else if (caves[z] == pitLoc1 || caves[z] == pitLoc2) {

          lvladjGobjects(caves[z], currentPlayloc, gameObject2);
          gotraverseBetween(caves[z], currentPlayloc, gameObject2);
        } else if (caves[z] == manBat1 || caves[z] == manBat2) {

          lvladjGobjects(caves[z], currentPlayloc, gameObject3);
          gotraverseBetween(caves[z], currentPlayloc, gameObject3);
        }
      }
      printf("\n\n");

    }
    else if (optionSelec == 'c' || optionSelec == 'C') {
       int nonArrowroom;
      if(currentPlayloc == arrowRoom){
      
       nonArrowroom = -1;}
      else{nonArrowroom = arrowRoom;}
      printf("Cheating! Game elements are in the following rooms: \n"
             "Player Wumpus Pit1 Pit2 Bats1 Bats2 arrow \n");
      printf("  %d     %d     %d     %d     %d    %d    %d\n ", currentPlayloc,
             wumpusLoc, pitLoc1, pitLoc2, manBat1, manBat2, nonArrowroom);
      printf("\nYou are in room %d. \n\n", currentPlayloc);
    } 
    else if (optionSelec == 'd' || optionSelec == 'D') {
      displayInstructions();
      printf("You are in room %d. \n\n", currentPlayloc);

    } 
    else if (optionSelec == 'p' || optionSelec == 'P') {
      printf("\n");
      displayCave();

      printf("You are in room %d. \n\n", currentPlayloc);
    } 
    else if (optionSelec == 'g' || optionSelec == 'G') {
      printf("Enter room (1..20) you think Wumpus is in: ");
      int guess;
      scanf("%d", &guess);
      if (guess == wumpusLoc) {
        printf("You won!\n\n");
        exitGame = true;
      } else {
        printf("You lost!\n\n");
        exitGame = true;
      }
      printf("Exiting Program ...");
    } 
    else if (optionSelec == 'x' || optionSelec == 'X') {
      exitGame = true;
      printf("\nExiting Program ...");
    }
  }
  return 0;
}