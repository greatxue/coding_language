/*
 * Function: gcd
 * Usage: int g = gcd(x, y);
 * -------------------------
 * Computes the greatest common divisor using a recursive implementation
 * of Euclid's algorithm.
 */

int gcd(int x, int y) {
   int guess;
//   int min = (x < y) ? x : y;
   for (int i = 1; i <= x; i++) {
        if (x % i == 0 && y % i == 0)
           guess = i;
   }
   return guess;
}

//int gcd(int x, int y) {
//   int guess = (x < y) ? x : y;
//   while (x % guess != 0 || y % guess != 0) {
//      guess--;
//   }
//   return guess;
//}

//int gcd(int x, int y) {
//   int r = x % y;
//   while (r != 0) {
//      x = y;
//      y = r;
//      r = x % y;
//   }
//   return y;
//}

//int gcd(int x, int y) {
//   if (x % y == 0) {
//      return y;
//   } else {
//      return gcd(y, x % y);
//   }
//}
