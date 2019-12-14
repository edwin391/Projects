public class MinutesToYearsDaysCalculator {

    public static void printYearsAndDays(long minutes) {

        if(minutes < 0) {
            System.out.println("Invalid Value");
        } else {
            long hour = minutes / 60;
            long days = minutes % 525600;
            days = days / 1440;
            long years = minutes / 525600;
            System.out.println(minutes + " min = " + years + " y and " + days + " d");
        }
    }
}
