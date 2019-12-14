import java.util.Scanner;

public class InputCalculator {
    public static void inputThenPrintSumAndAverage () {
        Scanner scanner = new Scanner(System.in);

        double counter = 0;
        long sum = 0;
        //long avg = 0;

        while (true) {
            double order = counter + 1;
            //System.out.println("Enter number #" + order + ":");

            boolean isAnInt = scanner.hasNextInt();

            if(isAnInt) {
                int number = scanner.nextInt();
                counter++;
                sum += number;
            } else if (!isAnInt){
                //System.out.println("SUM = 0 AVG = 0");
                break;
                //System.out.println("Invalid number");
            }

        }
        double average = (sum / counter);
        System.out.println("average" + average);
        long avg = Math.round(average);
        System.out.println("SUM = " + sum + " AVG = " + avg);
        scanner.close();
    }
}
