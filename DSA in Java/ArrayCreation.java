import java.util.*;

public class ArrayCreation
{
    // This code demonstrates different methods of array creation in Java
    public static void main(String[] args)
    {
        //Method 1 (static array)
        int[] Array1 = new int[]{1,2,3,4,5}; // A array of size 5
        // new int[size]{} this is incorrect
        System.out.println("Array 1:");
        for (int x: Array1)
           System.out.print(x + " ");
        System.out.println("");

        //  int[] Array2 = new int[5];
        //  Array2 = {1,2,3,4,5};  error

        int[] Array2 = new int[5];
        Array2[0] = 6;
        Array2[1] = 7;
        Array2[2] = 8;

        System.out.println("Array 2:");
        for (int x: Array2)
          System.out.print(x + " ");
        System.out.println("");

        int[] Array3 = {23,45,56,36,28,73,20};

        System.out.println("Array 3:");
        for (int x: Array3)
          System.out.print(x + " ");
        System.out.println("");

        int Array4[] = {4,5,6,3,8,7,0};

        System.out.println("Array 4:");
        for (int x: Array4)
          System.out.print(x + " ");
        System.out.println("");

        int[] Array5 = {3,5,6,6,8,7,2};

        System.out.println("Array 5:");
        for (int x: Array5)
          System.out.print(x + " ");
        System.out.println("");

        int Array6[] = new int[3];

        Array6[0] = 6;
        Array6[1] = 7;
        Array6[2] = 8;
 
        System.out.println("Array 6:");
        for (int x: Array6)
          System.out.print(x + " ");
        System.out.println("");

        //Method 2 dynamic array
        int size;
        System.out.println("Enter the size of the Array: ");
        Scanner scan = new Scanner(System.in);
        size = scan.nextInt();
        int[] Array7 = new int[size];

        for(int i = 0 ; i < size ; i++)
        {
            System.out.println("Enter element" + (i+1) + ": ");
            Array7[i] = scan.nextInt();
        }

        System.out.println("Array 7:");
        for (int x: Array7)
          System.out.print(x + " ");
        System.out.println("");

       //printing array 
       System.out.println("Array 7: " + Arrays.toString(Array7));
       
    }
}