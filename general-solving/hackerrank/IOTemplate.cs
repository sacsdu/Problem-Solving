/***************************************************************************
* Title : Utility for Hackerrank
* URL   : 
* Date  : 2018-06-05
* Author: Atiq Rahman
* Notes : Usually I implement the Run function and separate the IO part using
*   the method included below.
*   I did not change/simplify this IO handling, just kept it the way hackerrank
*   provided it.
***************************************************************************/
using System.IO;
using System;

class HK_Solution {
  static void Main(string[] args) {
    TextWriter textWriter = new StreamWriter(@System.Environment.
      GetEnvironmentVariable("OUTPUT_PATH"), true);
    string[] nm = Console.ReadLine().Split();

    Convert.ToInt32(nm[0]);
    Convert.ToInt32(nm[1]);

    int[] a = Array.ConvertAll(Console.ReadLine().Split(), aTemp => Convert.ToInt32(aTemp));
    int[] b = Array.ConvertAll(Console.ReadLine().Split(), bTemp => Convert.ToInt32(bTemp));
    
    textWriter.WriteLine(string.Join(" ", Run(a, b)));

    textWriter.Flush();
    textWriter.Close();
  }
}
