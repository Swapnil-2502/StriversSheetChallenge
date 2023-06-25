#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
  int notes[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int NumberofCoins = 0;

  for (int i = 8; i >= 0; i--) {
        while(notes[i] <= amount) {
            amount -= notes[i];
            NumberofCoins++;
        }
    }
    return NumberofCoins;

    //TC = O(8);
    //SC = O(1);
}
