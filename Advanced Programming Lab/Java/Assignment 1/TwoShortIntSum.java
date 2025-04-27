
import java.util.*;

public class TwoShortIntSum {

    public static void main(String[] args) {
        short num1, num2;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two short integers");

        try {
            num1 = sc.nextShort();
            num2 = sc.nextShort();
            System.out.println("Sum of two short integers is " + (short) (num1 + num2));
        } catch (InputMismatchException e) {
            System.out.println("Invalid Range for short int (Should be between -32768 to 32767 )");
            sc.nextLine();
        }

        sc.close();
    }
}