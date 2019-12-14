public class PerfectNumber {
    public static boolean isPerfectNumber(int number) {
        int sum = 0;
        boolean success = true;
        if(number<1) {
            success = false;
        } else {
            for(int i = 1; i < number; i++) {
                if(number % i == 0) {
                    sum = sum + i;
                }
            }
            if(sum == number) {
                success = true;
            } else{
                success = false;
            }
        }
        return success;
    }
}
