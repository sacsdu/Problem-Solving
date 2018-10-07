/*******************************************************
*    Problem Name:  Packets
*    Problem ID:    D (UVA 311)
*    Occassion:    Dept Team Contest 8 Oct 2008
*
*    Algorithm:      Bruite Force
*    Special Case:    NA
*    Judge Status:    Accepted by UVA and mooshak
*    Author:        Atiqur Rahman
*******************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

int posX, posY;
bool board[8][8];

bool seekIfPossible(int size, int curPos) {
  int i, j, k, l;
  bool f;

  if (curPos == 0)
    return false;
  for (i=0; i<=6- size; i++) {
    for (j=0; j<=6-size; j++) {
      f = true;
      for (k= i; k<i+size; k++) {
        for (l=j; l<j+size; l++) {
          if (board[k][l])
            f = false;
        }
      }
      if (f) {
        posX = i;
        posY = j;
        return true;
      }
    }
  }
  return false;
}

void pushPacket(int size) {
  int i, j;
  for (i=posX; i<posX+size; i++)
    for (j=posY; j<posY+size; j++) {
      board[i][j] = true;
    }
}

int main () {
  int i, j, np[8], takenPackets, totalPackets;
  bool zf, possible;

  while (true) {
    zf = true;
    totalPackets = 0;
    for (i=0; i<6; i++) {
      scanf("%d", &np[i]);
      if (np[i])
        zf = false;
      totalPackets += np[i];
    }
    if (zf)
      break;

    takenPackets = 0;

    while (totalPackets) {
      for (i=0; i<6; i++)
        for (j=0; j<6; j++)
          board[i][j] = false;

      for (i=5; i>=0; i--) {
        possible = seekIfPossible(i+1, np[i]);
        while (possible) {
          pushPacket(i+1);
          np[i]--;
          totalPackets--;
          possible = seekIfPossible(i+1, np[i]);
        }
      }
      takenPackets++;
    }
    printf("%d\n", takenPackets);
  }
  return 0;
}
