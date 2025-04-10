//{ Driver Code Starts
import java.util.*;

class Implement_strstr {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t > 0) {
            String line = sc.nextLine();
            String a = line.split(" ")[0];
            line = sc.nextLine();
            String b = line.split(" ")[0];

            Solution g = new Solution();
            System.out.println(g.firstOccurence(a, b));

            t--;

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    // Function to locate the occurrence of the string x in the string s.
   int firstOccurence(String txt, String pat) {
        // Your code here
        int n = txt.length();
        int m = pat.length();

        if (m > n) return -1; // Pattern can't be larger than text

        int[] lps = computeLPS(pat); // Preprocess LPS array

        int i = 0, j = 0; // Pointers for txt and pat
        while (i < n) {
            if (txt.charAt(i) == pat.charAt(j)) {
                i++;
                j++;
            }
            if (j == m) return i - j; // Pattern found

            if (i < n && txt.charAt(i) != pat.charAt(j)) {
                if (j != 0) j = lps[j - 1]; // Move j using LPS
                else i++; // Move i normally
            }
        }
        return -1; // Pattern not found
    }

    private int[] computeLPS(String pat) {
        int m = pat.length();
        int[] lps = new int[m];
        int len = 0, i = 1;

        while (i < m) {
            if (pat.charAt(i) == pat.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) len = lps[len - 1];
                else lps[i++] = 0;
            }
        }
        return lps;
    
    }
}
