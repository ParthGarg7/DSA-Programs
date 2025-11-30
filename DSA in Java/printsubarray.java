import java.util.*;

public class printsubarray{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the size of the array: ");
        int size = scan.nextInt();
        int[] Array1 = new int[size];
        System.out.println("Enter the elements of the array: ");

        for(int i = 0; i < size; i++)
            Array1[i] = scan.nextInt();
        
        System.out.println("The given array is : ");
        for(var x: Array1)
            System.out.print(x + " ");

        System.out.println();

        System.out.println("The subarrays of the given are: ");
          
         
        for (int i = 0 ; i < size ; i++) 
        {
            for(int j = 0 ; j < size ; j++ )
            {
               for(int k = j ; k <i+1 ; k++  ) 
                   System.out.print(Array1[k] + " ");

               System.out.println();
            }
        }
    }
}